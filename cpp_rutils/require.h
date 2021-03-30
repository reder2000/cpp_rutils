#pragma once

#include <fmt/format.h>
#include "name.h"
#include <roost/preprocessor/variadic/size.hpp>
#include <roost/preprocessor/if.hpp>
#include <roost/preprocessor/dec.hpp>
#include <roost/preprocessor/stringize.hpp>
#include <roost/preprocessor/variadic/to_tuple.hpp>
#include <roost/preprocessor/tuple/enum.hpp>
#include <roost/preprocessor/facilities/is_empty.hpp>

#define MREQUIRE2(success,VA_ARGS1,VA_ARGS2) \
	if (!(success)) throw std::runtime_error( \
		fmt::format("{} , {} , {} , {} , {}" , __func__ , __FILE__ , __LINE__ ,\
		  fmt::format(ROOST_PP_TUPLE_ENUM(VA_ARGS1)), fmt::format(ROOST_PP_TUPLE_ENUM(VA_ARGS2))))

#define MREQUIRE1(success,...) \
	if (!(success)) throw std::runtime_error( \
		fmt::format("{} , {} , {} , {} " , __func__ , __FILE__ , __LINE__ ,\
		  fmt::format(__VA_ARGS__)))

#define MREQUIRE0(...) \
	MREQUIRE1(__VA_ARGS__, # __VA_ARGS__ )

#define MREQUIRE(...) \
	ROOST_PP_IF(ROOST_PP_DEC(ROOST_PP_VARIADIC_SIZE(__VA_ARGS__)) , \
			MREQUIRE1(__VA_ARGS__) , MREQUIRE0(__VA_ARGS__))

#define _MREQUIRE_OP1(op,a,b,...) \
	MREQUIRE2( (a) op (b) , \
		ROOST_PP_VARIADIC_TO_TUPLE( ROOST_PP_STRINGIZE(a) ":({}) not "  ROOST_PP_STRINGIZE(op) " " ROOST_PP_STRINGIZE(b) ":({})" , (a) , (b) ) , \
		ROOST_PP_VARIADIC_TO_TUPLE(__VA_ARGS__) )

#define _MREQUIRE_OP0(op,a,b) \
	MREQUIRE1( (a) op (b) , ROOST_PP_STRINGIZE(a) ":({}) not "  ROOST_PP_STRINGIZE(op) " " ROOST_PP_STRINGIZE(b) ":({})" , (a) , (b) )

#define _MREQUIRE_OP(op,a,b,...) \
	ROOST_PP_IF( ROOST_PP_IS_EMPTY(__VA_ARGS__) , \
			_MREQUIRE_OP0(op,a,b) , \
			_MREQUIRE_OP1(op, a, b, __VA_ARGS__) ) 

#define MREQUIRE_EQUAL(a,b,...) \
	_MREQUIRE_OP(==,a,b,__VA_ARGS__)

#define MREQUIRE_LESS(a,b,...) \
	_MREQUIRE_OP(<,a,b,__VA_ARGS__)

#define MREQUIRE_GREATER(a,b,...) \
	_MREQUIRE_OP(>,a,b,__VA_ARGS__)

#define MREQUIRE_LESS_EQUAL(a,b,...) \
	_MREQUIRE_OP(<=,a,b,__VA_ARGS__)

#define MREQUIRE_GREATER_EQUAL(a,b,...) \
	_MREQUIRE_OP(>=,a,b,__VA_ARGS__)

#define default_fail(arg) \
	default: MREQUIRE(false,"unhandled case {}",arg); \
	break

#define default_fail_enum_string(arg) \
	default: MREQUIRE(false,"unhandled case {}::{}",type_name<decltype(arg)>(), to_string(arg)); \
	break