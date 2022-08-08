#pragma once 

// true whenever value is found in args
// is_one_of(1,3,4,1) -> true

template <class T, class U>
constexpr inline
bool is_one_of(T value, U other) {
	return value == other;
}

template <class T, class U, class... Args>
constexpr inline
bool is_one_of(T value, U other, Args... args ) {
	return is_one_of(value, other) || is_one_of(value, args...);
}
