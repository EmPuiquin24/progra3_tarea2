#ifndef CONCEPTS_H 
#define CONCEPTS_H 

#include <iterator>

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
	{ a / n };
};

template<typename T>
concept Subtractable = requires(T a, T b) {
	{a - b} -> std::same_as<T>;
};

template<typename T>
concept Multipliable = requires(T a, T b) {
	{a * b} -> std::same_as<T>;
};

template<typename T>
concept Comparable = requires(T a, T b) {
	{a == b} -> std::same_as<bool>;
	{a > b} -> std::same_as<bool>;
	{b < a} -> std::same_as<bool>;
	{a >= b} -> std::same_as<bool>;
	{b <= a} -> std::same_as<bool>;
};

#endif // CONCEPTS_H