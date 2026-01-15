#include <concepts>
#include <iterator>

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
concept Divisible = requires(T a, std::size_t n) {
	{ a / n } -> std::same_as<T>;
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
		result = result + value;
	}

	return result;
}


template<Iterable C>
requires Addable<typename C::value_type> && Divisible<typename C::value_type>
auto mean(const C& container) {

	using T = typename C::value_type;

	size_t n  = count_elements(container);

	if (n == 0) {
		return T {}
	}

	T total_sum {};

	for (const auto& value : container) {
		total_sum += value;
	}

	return (total_sum)/n;

}

}

int main() {
	return 0;
}
