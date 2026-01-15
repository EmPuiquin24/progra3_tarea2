#ifndef CoreNumeric_H
#define CoreNumeric_H

#include "concepts.h"
#include <concepts>
#include <functional>
#include <iostream>
#include <cmath>

namespace CoreNumeric {

template <Iterable C> 
size_t count_elements(const C& container) {

	size_t count = 0;
	
	for (const auto &_ : container ) {
		++ count ;
	}

	return count ;
}


template<Iterable C>
requires Addable<typename C::value_type>
auto sum(const C& container) {

	using T = typename C::value_type;

	T result {};
	for (const auto& value : container) {
		result += value;
	}

	return result;
}


template<Iterable C>
requires Addable<typename C::value_type> && Divisible<typename C::value_type>
auto mean(const C& container) {

	using T = typename C::value_type;

	size_t n  = count_elements(container);
	if (n == 0) {
		return T {};
	}

	T total_sum = sum(container);

	return total_sum/n;	
}


template<Iterable C>
requires Addable<typename C::value_type> && Divisible<typename C::value_type>
auto variance(const C& container) {

	using T = typename C::value_type;

	size_t n = count_elements(container);	
	if (n == 0) {
		cout << "El contenedor tiene 0 elementos, no se puede obtener la varianza" << endl;
		return T {};
	}

	T container_avg = mean(container);
	
	T upper_sum{};
	for (const auto& value: container) {
		upper_sum += pow(container - container_avg, 2);	
	}	

	return upper_sum/n;
}

template<Iterable C>
requires Comparable<typename C::value_type>
auto max(const C& container) {

	using T = typename C::value_type;

	size_t n = count_elements(container);
	if (n == 0) {
		cout << "El contenedor tiene 0 elementos, no se puede obtener un máximo" << endl;
		return T {};	
	}

	T result = container[0];	
	for (auto const& value : container) {
		result = max(result, value);
	}

	return result;
}

template <Iterable C, typename U>
requires Addable<typename C::value_type> && 
Divisible<typename C::value_type> &&
Comparable<typename C::value_type>
auto transform_reduce(const C& container, function<U(C)> func) {

	using T = typename C::value_type;

	T result {};

	size_t n = count_elements(container);
	if (n == 0) {
		cout << "El contenedor está vacío" << endl;
		return T {};	
	}

	for (auto const& value : container) {
		result += func(value);
	}

	return result;
}

// Variadic templates
template<Addable... Args>
auto sum_variadic(Args... args) {
	return (0+...+(args));
}

template<typename... Args>
requires ((Addable<Args> && Divisible<Args>) && ...)
auto mean_variadic(Args... args) {

	auto upper_sum = sum_variadic(args...);
	
	if (upper_sum == 0) {
		return 0.0;	
	}
	
	return (upper_sum/sizeof...(args));
}

template<typename... Args>
requires ((Addable<Args> && Divisible<Args>) && ...)
auto variance_variadic(Args... args) {

	auto args_mean = mean_variadic(args...);
	
	return (((args - args_mean)*(args - args_mean)) + ...) / (sizeof...(args));
}

template<typename... Args>
requires (Comparable<Args> && ...)
auto max_variadic(Args... args) {

	using T = common_type_t<Args...>;

	T max_number = std::numeric_limits<T>::lowest();

	((max_number = (args > max_number? args : max_number)), ...);

	return max_number;
}

} // Fin del namespace

#endif // CoreNumeric_H
