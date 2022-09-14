#pragma once

// compile time type name

#include "name.h"
#include <vector>
#include <iostream>
#include <unordered_map>

namespace detail
{
	// we cannot return a char array from a function, therefore we need a wrapper
	template <unsigned N>
	struct String {
		char c[N];
	};

	template<unsigned ...Len>
	constexpr auto cat(const char(&...strings)[Len]) {
		constexpr unsigned N = (... + Len) - sizeof...(Len);
		String<N + 1> result = {};
		result.c[N] = '\0';

		char* dst = result.c;
		for (const char* src : { strings... }) {
			for (; *src != '\0'; src++, dst++) {
				*dst = *src;
			}
		}
		return result;
	}

	template <typename T>
	struct type_namer
	{
		constexpr static auto get()
		{
			constexpr auto sv = ::type_name<T>();
			constexpr unsigned N = sv.length();
			String<N + 1> result = {};
			result.c[N] = '\0';

			char* dst = result.c;
			for (auto src : sv) {
				*dst++ = src;
			}
			return result;

		}
	};

	template <class _Ty, class _Alloc>
	struct type_namer<std::vector<_Ty, _Alloc>>
	{
		constexpr static	auto get()
		{
			return cat("vector<", type_namer<_Ty>().get().c, ">");
		}
	};

	template <class _Kty, class _Ty, class _Hasher, class _Keyeq ,
		class _Alloc>
	struct type_namer < std::unordered_map<_Kty,_Ty,_Hasher, _Keyeq, _Alloc>>
	{
		constexpr static	auto get()
		{
			return cat("unordered_map<", type_namer<_Kty>().get().c, "," , type_namer<_Ty>().get().c, ">");
		}

	};


}


template <typename T>
constexpr auto type_name_short() noexcept {
	{
		return detail::type_namer<T>::get();
	}
};

template <unsigned N>
std::ostream& operator <<(std::ostream &os , const detail::String<N> s)
{
	os << s.c;
	return os;
}