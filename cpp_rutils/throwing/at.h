#pragma once
#include "../require.h"

// at that throw an error with the key when the key is not find

template <typename Container, typename Key>
inline
typename const Container::mapped_type& at(const Container & c , const Key & k)
{
	auto w = c.find(k);
	if (w!=c.end())
		return w->second;
	MFAIL("could not find key {} in {}", k , type_name<Container>());
}

template <typename Container, typename Key>
inline
typename Container::mapped_type& at(Container& c, const Key& k)
{
	auto w = c.find(k);
	if (w != c.end())
		return w->second;
	MFAIL("could not find key {} in {}", k, type_name<Container>());
}

// at that throw an error with the key when the key is not find
// that macro version gibes the actual call site

#define AT(cc,kk) \
	[](auto &&c, auto &&k) { \
		auto w = c.find(k); \
		if (w != c.end()) \
			return w->second; \
		[[no_return]] MFAIL("could not find key {} in {}", k, type_name<decltype(c)>()); } \
		(cc,kk)
