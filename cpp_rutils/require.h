#pragma once

// set of macro for checking requirements
// usually in the form 
// MACRO( condition , fmt_format_spec, args...)

#include <fmt/format.h>
#include "name.h"
#include <boost/preprocessor/variadic/size.hpp>
#include <boost/preprocessor/if.hpp>
#include <boost/preprocessor/dec.hpp>
#include <boost/preprocessor/stringize.hpp>
#include <boost/preprocessor/variadic/to_tuple.hpp>
#include <boost/preprocessor/tuple/enum.hpp>
#include <boost/preprocessor/facilities/is_empty.hpp>

#define MFAIL(...) \
	throw std::runtime_error( \
		fmt::format("{} , {} , {} , {} " , __func__ , __FILE__ , __LINE__ ,\
		  fmt::format(__VA_ARGS__)))

#define MREQUIRE2(success,VA_ARGS1,VA_ARGS2) \
	if (!(success)) throw std::runtime_error( \
		fmt::format("{} , {} , {} , {} , {}" , __func__ , __FILE__ , __LINE__ ,\
		  fmt::format(BOOST_PP_TUPLE_ENUM(VA_ARGS1)), fmt::format(BOOST_PP_TUPLE_ENUM(VA_ARGS2))))

#define MREQUIRE1(success,...) \
	if (!(success)) throw std::runtime_error( \
		fmt::format("{} , {} , {} , {} " , __func__ , __FILE__ , __LINE__ ,\
		  fmt::format(__VA_ARGS__)))

#define MREQUIRE0(...) \
	MREQUIRE1(__VA_ARGS__, # __VA_ARGS__ )

#define MREQUIRE(...) \
	BOOST_PP_IF(BOOST_PP_DEC(BOOST_PP_VARIADIC_SIZE(__VA_ARGS__)) , \
			MREQUIRE1(__VA_ARGS__) , MREQUIRE0(__VA_ARGS__))

#define _MREQUIRE_OP1(op,a,b,...) \
	MREQUIRE2( (a) op (b) , \
		BOOST_PP_VARIADIC_TO_TUPLE( BOOST_PP_STRINGIZE(a) ":({}) not "  BOOST_PP_STRINGIZE(op) " " BOOST_PP_STRINGIZE(b) ":({})" , (a) , (b) ) , \
		BOOST_PP_VARIADIC_TO_TUPLE(__VA_ARGS__) )

#define _MREQUIRE_OP0(op,a,b) \
	MREQUIRE1( (a) op (b) , BOOST_PP_STRINGIZE(a) ":({}) not "  BOOST_PP_STRINGIZE(op) " " BOOST_PP_STRINGIZE(b) ":({})" , (a) , (b) )

#define _MREQUIRE_OP(op,a,b,...) \
	BOOST_PP_IF( BOOST_PP_IS_EMPTY(__VA_ARGS__) , \
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
	_MREQUIRE_OP(>=, a, b, __VA_ARGS__)

#define MREQUIRE_TRY1(what_to_try,...)                                                                                                                      \
  {                                                                                                                                                  \
    bool success;                                                                                                                                    \
    try                                                                                                                                              \
    {                                                                                                                                                \
      success = what_to_try;                                                                                                                                \
    }                                                                                                                                                \
    catch (std::exception & e)                                                                                                                       \
    {                                                                                                                                                \
      throw std::runtime_error(fmt::format("{} , {} , {} failed with exception {} ({}) ", __func__, __FILE__, __LINE__, e.what()   \
                   , fmt::format(__VA_ARGS__)        ));                                                                                                            \
    }                                                                                                                                                \
    if (! success)                                                                             \
    {                                                                                          \
      throw std::runtime_error(fmt::format("{} , {} , {} , {} ", __func__, __FILE__, __LINE__, \
                                           fmt::format(__VA_ARGS__)));                         \
    }                                                                                          \
  }

#define MREQUIRE_TRY0(what_to_try) \
  MREQUIRE_TRY1(what_to_try, "{}", # what_to_try )

#define MREQUIRE_TRY(what_to_try,...)                                                                    \
  BOOST_PP_IF(BOOST_PP_DEC(BOOST_PP_VARIADIC_SIZE(__VA_ARGS__)), \
              MREQUIRE_TRY1(what_to_try, __VA_ARGS__), \
              MREQUIRE_TRY0(what_to_try))

#define default_fail(arg) \
	default: MREQUIRE(false,"unhandled case {}",arg); \
	break

#define default_fail_enum_string(arg) \
	default: MREQUIRE(false,"unhandled case {}::{}",type_name<decltype(arg)>(), to_string(arg)); \
	break
