#include <concepts>
#include <iterator>
#include <cmath>

using namespace std;

template<typename C>
concept Iterable = requires(C c) {
	std::begin(c);
	std::end(c);
};;


template<typename T>
concept Addable = requires(T a, T b) {
	{a + b} -> std::same_as<T>;
};


template<typename T>
concept Divisible = requires(T a, size_t n) {
	{ a / n } -> std::same_as<T>;
}

template<typename T>
concept Comparable = requires(T a, T b) {
	{a = b} -> same_as<bool>;
	{a > b} -> same_as<bool>;
	{b < a} -> same_as<bool>;
}

template <Iterable C> 
size_t count_elements(const C& container) {

	size_t count = 0;
	
	for (const auto &_ : container ) {
		++ count ;
	}

	return count ;
}

namespace CoreNumeric {

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
	T result {};

	size_t n = count_elements(container);
	
	if (n == 0) {
		cout << "El contenedor tiene 0 elementos, no se puede obtener un máximo" << endl;
		return T {};	
	}

	T result = container[0];	
	for (auto value& : container) {
		result = max(result, value);
	}

	return result;
}

template <Iterable C>
requires Addable<typename C::value_type> && 
Divisible<typename C::value_type> &&
Comparable<typename C::value_type>
auto transform_reduce(const C& container, function<C> f) {

	using T = typename C::value_type;

	T result {};

	if (n == 0) {
		cout << "El contenedor está vacío" << endl;
		T {};	
	}

	for (auto value& : container) {
		result += f(value);
	}

	return result;
}


} // Fin del namespace

int main() {
	return 0;
}
