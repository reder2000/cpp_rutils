#pragma once

// smart enum with conversion from/to string
// just write
// #define MyDataType_tuple (enum1,enum2,...);


#include "boost/preprocessor/tuple/rem.hpp"
#include "boost/preprocessor/cat.hpp"
#include "boost/preprocessor/punctuation/comma_if.hpp"
#include "boost/preprocessor/stringize.hpp"
#include "boost/preprocessor/list/for_each_i.hpp"
#include "boost/preprocessor/tuple/to_list.hpp"
#include "boost/preprocessor/list/for_each.hpp"
#include "boost/preprocessor/seq/elem.hpp"
#include "to_string.h"
#include "always_false.h"
#include "string_literal.h"
#include "require.h"

template <class T>
std::string_view enum_to_string(T)
{
  static_assert(always_false_v<T>);
  return {};
}

template <class T>
T string_to_enum(std::string_view s);

// name => name_tuple
#define NAME_TUPLE(name) BOOST_PP_CAT(name, _tuple)

// process tuple with macro
#define PROCESS_TUPLE(macro, data, name) \
  BOOST_PP_LIST_FOR_EACH_I(macro, data, BOOST_PP_TUPLE_TO_LIST(NAME_TUPLE(name)))


// name_tuple = (a,b,...) =>
// enum class name_tuple {a,b,...}
#define EMIT_ENUM_CLASS_ENUM(name)            \
  enum class name                             \
  {                                           \
    BOOST_PP_TUPLE_REM_CTOR(NAME_TUPLE(name)) \
  }

// , data::elem => , "elem"
#define EMIT_ENUM_TO_STRING(r, data, i, elem) BOOST_PP_COMMA_IF(i) BOOST_PP_STRINGIZE(elem)

// name => name_tuple_sl
#define NAME_TUPLE_SL(name) BOOST_PP_CAT(name, _tuple_sl)
// name => name_tuple_sl = tuple_sl<"a","b",...>
#define EMIT_TUPLE_SL(name) \
  using NAME_TUPLE_SL(name) = tuple_sl<PROCESS_TUPLE(EMIT_ENUM_TO_STRING, name, name)>
// deprecated
//#define EMIT_TUPLE_SL(name)                                      \
//  using NAME_TUPLE_SL(name) = tuple_sl<BOOST_PP_LIST_FOR_EACH_I( \
//      EMIT_ENUM_TO_STRING, name, BOOST_PP_TUPLE_TO_LIST(NAME_TUPLE(name)))>

// name => enum to string
#define EMIT_ENUM_CLASS_TO_STRING(name)                                               \
  template <>                                                                         \
  inline std::string_view enum_to_string<name>(name value)                            \
  {                                                                                   \
    size_t i = static_cast<size_t>(static_cast<std::underlying_type_t<name>>(value)); \
    return tuple_sl_get_i<NAME_TUPLE_SL(name)>(i);                                    \
  }

//// name_tuple = (a,b) =>
//// name2String map = { {a,"a"} , {b,"b"} }
//#define EMIT_ENUM_CLASS_TO_STRING(name) \
//template <> \
//inline const char*  enum_to_string<name>(name value)  { \
//	static const char* tab[] = { \
//	BOOST_PP_LIST_FOR_EACH_I(EMIT_ENUM_TO_STRING,name,BOOST_PP_TUPLE_TO_LIST(NAME_TUPLE(name)))  \
//	} ;\
//	return tab[static_cast<size_t>(value)] ;\
//}

// name => string to enum
#define EMIT_STRING_TO_ENUM_CLASS(name)                                                            \
  template <>                                                                                      \
  inline name string_to_enum(std::string_view s)                                                   \
  {                                                                                                \
    size_t i = tuple_sl_index_s<NAME_TUPLE_SL(name)>(s);                                           \
    MREQUIRE(i != std::string::npos, "{} is not a valid string for", s, BOOST_PP_STRINGIZE(name)); \
    return static_cast<name>(i);                                                                   \
  }                                                                                                \
  template <>                                                                                      \
  inline std::string to_string<name>(const name& value)                                            \
  {                                                                                                \
    return std::string(enum_to_string(value));                                                     \
  }


//#define EMIT_STRING_TO_ENUM(r, data, elem) if (BOOST_PP_SEQ_ELEM(0,data) == BOOST_PP_STRINGIZE(elem)) return BOOST_PP_SEQ_ELEM(1,data)::elem ;
//
//#define EMIT_STRING_TO_ENUM_CLASS(name) \
//template <> \
//inline name string_to_enum(std::string_view s) { \
//	BOOST_PP_LIST_FOR_EACH( EMIT_STRING_TO_ENUM , (s)(name) , BOOST_PP_TUPLE_TO_LIST(NAME_TUPLE(name)) )  \
//	throw std::runtime_error(fmt::format("did not find {}", s)); \
//} \
//template <> \
//inline std::string to_string<name>(const name &value)\
//{ return std::string(enum_to_string(value)) ; }

#define EMIT_ENUM_CLASS_FMT_FORMATTER(name)            \
  template <>                                          \
  struct fmt::formatter<name> : formatter<std::string> \
  {                                                    \
    template <typename FormatContext>                  \
    auto format(name v, FormatContext& ctx)            \
    {                                                  \
      auto s = ::to_string(v);                         \
      return formatter<std::string>::format(s, ctx);   \
    }                                                  \
  }


#define EMIT_ENUM_CLASS(name)      \
  EMIT_ENUM_CLASS_ENUM(name);      \
  EMIT_TUPLE_SL(name);             \
  EMIT_ENUM_CLASS_TO_STRING(name); \
  EMIT_STRING_TO_ENUM_CLASS(name); \
  EMIT_ENUM_CLASS_FMT_FORMATTER(name)


// expanding pybind

//py::enum_<ScopedEnum>(m, "ScopedEnum", py::arithmetic())
//    .value("Two", ScopedEnum::Two)
//    .value("Three", ScopedEnum::Three);

#define EMIT_ENUM_PYBIND11_VALUE(r, data, i, elem) .value(BOOST_PP_STRINGIZE(elem), data::elem)

// deprecate
//#define EMIT_ENUM_PYBIND11(name,m) \
//  py::enum_<name>(m, BOOST_PP_STRINGIZE(name), py::arithmetic())\
//  BOOST_PP_LIST_FOR_EACH_I( \
//      EMIT_ENUM_PYBIND11_VALUE, name, BOOST_PP_TUPLE_TO_LIST(NAME_TUPLE(name)))

#define EMIT_ENUM_PYBIND11(name, m)                                          \
  pybind11::enum_<name>(m, BOOST_PP_STRINGIZE(name), pybind11::arithmetic()) \
                            PROCESS_TUPLE(EMIT_ENUM_PYBIND11_VALUE, name, name)
