#pragma once
#include "../require.h"

template <typename Container, typename Key>
inline
typename const Container::value_type & at(const Container & c , const Key & k)
{
	auto w = c.find(k);
	if (w==c.end())
	{
		MFAIL("could not find key {} in {}", k , type_name<Container>());
	}
	return *w;
}

template <typename Container, typename Key>
inline
typename Container::value_type& at(Container& c, const Key& k)
{
	auto w = c.find(k);
	if (w == c.end())
	{
		MFAIL("could not find key {} in {}", k, type_name<Container>());
	}
	return *w;
}
