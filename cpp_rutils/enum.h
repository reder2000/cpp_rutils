#pragma once 

//#include <boost/preprocessor/tuple.hpp>
#include "boost/preprocessor/tuple/rem.hpp"
#include "boost/preprocessor/cat.hpp"
#include "boost/preprocessor/punctuation/comma_if.hpp"
#include "boost/preprocessor/stringize.hpp"
#include "boost/preprocessor/list/for_each_i.hpp"
#include "boost/preprocessor/tuple/to_list.hpp"
#include "boost/preprocessor/list/for_each.hpp"
#include "boost/preprocessor/seq/elem.hpp"
#include <string_view>
#include <fmt/format.h>
#include "to_string.h"

template <class T>
const char* enum_to_string(T);

template <class T>
T string_to_enum(std::string_view s);

// name => name_tuple
#define NAME_TUPLE(name) \
	BOOST_PP_CAT(name,_tuple)


// name_tuple = (a,b) =>
// enum class name_tuple {a,b}
#define EMIT_ENUM_CLASS_ENUM(name) \
enum class name { \
	BOOST_PP_TUPLE_REM_CTOR(NAME_TUPLE(name)) \
}

// , data::elem , "elem"
#define EMIT_ENUM_TO_STRING(r, data, i, elem) \
	BOOST_PP_COMMA_IF(i) BOOST_PP_STRINGIZE(elem)

// name_tuple = (a,b) =>
// name2String map = { {a,"a"} , {b,"b"} }
#define EMIT_ENUM_CLASS_TO_STRING(name) \
template <> \
inline const char*  enum_to_string<name>(name value)  { \
	static const char* tab[] = { \
	BOOST_PP_LIST_FOR_EACH_I(EMIT_ENUM_TO_STRING,name,BOOST_PP_TUPLE_TO_LIST(NAME_TUPLE(name)))  \
	} ;\
	return tab[static_cast<size_t>(value)] ;\
}

#define EMIT_STRING_TO_ENUM(r, data, elem) if (BOOST_PP_SEQ_ELEM(0,data) == BOOST_PP_STRINGIZE(elem)) return BOOST_PP_SEQ_ELEM(1,data)::elem ;

#define EMIT_STRING_TO_ENUM_CLASS(name) \
template <> \
inline name string_to_enum(std::string_view s) { \
	BOOST_PP_LIST_FOR_EACH( EMIT_STRING_TO_ENUM , (s)(name) , BOOST_PP_TUPLE_TO_LIST(NAME_TUPLE(name)) )  \
	throw std::runtime_error(fmt::format("did not find {}", s)); \
} \
template <> \
inline std::string to_string<name>(const name &value)\
{ return std::string(enum_to_string(value)) ; }


#define EMIT_ENUM_CLASS(name) \
	EMIT_ENUM_CLASS_ENUM(name); \
	EMIT_ENUM_CLASS_TO_STRING(name); \
	EMIT_STRING_TO_ENUM_CLASS(name)
