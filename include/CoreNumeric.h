#ifndef CoreNumeric_H
#define CoreNumeric_H

#include "concepts.h"
#include <concepts>
#include <functional>
#include <iostream>
#include <cmath>

namespace CoreNumeric {

	template<Iterable C> 
	size_t count_elements(const C& container) {

		size_t count = 0;
		
		for (const auto &_ : container) {
			++ count;
		}

		return count;
	}


	template<Iterable C>
	requires Addable<typename C::value_type>
	auto sum(const C& container) {

		using T = typename C::value_type;

		if constexpr (std::is_integral_v<T>) {
			long long result = 0;
			for (const auto& value : container) {
				result += value;
			}

			return result;
		} else {
			T result {};
			for (const auto& value : container) {
				result += value;
			}

			return result;
		}
	}


	template<Iterable C>
	requires Addable<typename C::value_type> && Divisible<typename C::value_type>
	auto mean(const C& container) {

		using T = typename C::value_type;

		size_t n  = count_elements(container);
		if (n == 0) {
			if constexpr (std::is_integral_v<T>) {
				return 0.0;
			} else {
				return T {};
			}
		}
		T total_sum = sum(container);

		if constexpr (std::is_integral_v<T>) {
			return static_cast<double>(total_sum)/n;
		} else {
			return total_sum/n;
		}
	}


	template<Iterable C>
	requires Addable<typename C::value_type> && Divisible<typename C::value_type> &&
	Subtractable<typename C::value_type> && Multipliable<typename C::value_type>
	auto variance(const C& container) {

		using T = typename C::value_type;

		size_t n = count_elements(container);	
		if (n == 0) {
			if constexpr (std::is_integral_v<T>) {
				return 0.0;
			} else {
				return T {};
			}
		}
		auto container_avg = mean(container);
		
		if constexpr (std::is_integral_v<T>) {
			double upper_sum = 0.0;
			for (const auto& value: container) {
				upper_sum += std::pow(value - container_avg, 2);
			}

			return upper_sum / n;

		} else {
			T upper_sum{};
			for (const auto& value: container) {
				upper_sum += std::pow(value - container_avg, 2);	
			}
			
			return upper_sum / n;
		}
	}


	template<Iterable C>
	requires Comparable<typename C::value_type>
	auto max(const C& container) {

		using T = typename C::value_type;

		size_t n = count_elements(container);
		if (n == 0) {
			return T {};	
		}

		T result = *std::begin(container);
		for (auto const& value : container) {
			result = std::max(result, value);
		}

		return result;
	}


	template<Iterable C, typename Func>
	requires Addable<typename C::value_type>
	auto transform_reduce(const C& container, Func func) {

		using T = typename C::value_type;
		using ReturnType = decltype(func(std::declval<T>()));

		ReturnType result {};

		size_t n = count_elements(container);
		if (n == 0) {
			return ReturnType {};	
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
		return static_cast<double>(upper_sum) / sizeof...(args);
	}


	template<typename... Args>
	requires ((Addable<Args> && Divisible<Args> && 
	Subtractable<Args> && Multipliable<Args>) && ...)
	auto variance_variadic(Args... args) {

		using T = std::common_type_t<Args...>;
		
		auto args_mean = mean_variadic(args...);
		
		if constexpr (std::is_integral_v<T>) {
			return ((static_cast<double>(args - args_mean) * 
			         static_cast<double>(args - args_mean)) + ...) / sizeof...(args);
		} else {
			return (((args - args_mean) * (args - args_mean)) + ...) / sizeof...(args);
		}
	}


	template<typename... Args>
	requires (Comparable<Args> && ...)
	auto max_variadic(Args... args) {

		using T = std::common_type_t<Args...>;

		T max_number = std::numeric_limits<T>::lowest();

		((max_number = (args > max_number? args : max_number)), ...);

		return max_number;
	}
}

#endif // CoreNumeric_H
