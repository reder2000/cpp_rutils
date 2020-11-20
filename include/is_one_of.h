#pragma once 

template <class T>
constexpr inline
bool is_one_of(T value, T other) {
	return value == other;
}

template <class T, class... Args>
constexpr inline
bool is_one_of(T value, T other, Args... args ) {
	return is_one_of(value, other) || is_one_of(value, args...);
}
