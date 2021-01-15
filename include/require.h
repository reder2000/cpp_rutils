#pragma once 

#include <fmt/format.h>
#include <roost/preprocessor/variadic/size.hpp>
#include <roost/preprocessor/if.hpp>
#include <roost/preprocessor/dec.hpp>

#define MREQUIRE1(success,...) \
	if (!(success)) throw std::runtime_error( \
		fmt::format("{} , {} , {} , {} " , __func__ , __FILE__ , __LINE__ ,\
		  fmt::format(__VA_ARGS__))) 

#define MREQUIRE0(...) \
	MREQUIRE1(__VA_ARGS__, # __VA_ARGS__ )

#define MREQUIRE(...) \
	ROOST_PP_IF(ROOST_PP_DEC(ROOST_PP_VARIADIC_SIZE(__VA_ARGS__)) , \
			MREQUIRE1(__VA_ARGS__) , MREQUIRE0(__VA_ARGS__))

#define MREQUIRE_EQUAL(a,b) \
	MREQUIRE(a==b)

#define MREQUIRE_LESS_EQUAL(a,b) \
	MREQUIRE(a<=b)

#define MREQUIRE_GREATER_EQUAL(a,b) \
		MREQUIRE(a>=b)