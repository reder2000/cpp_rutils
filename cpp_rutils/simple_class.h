#pragma once

#include "enum.h"
#include "boost/preprocessor/tuple/elem.hpp"
#include "boost/preprocessor/tuple/size.hpp"
#include "boost/preprocessor/if.hpp"
#include "boost/preprocessor/comparison/equal.hpp"

// name_tuple = ((type_1,name_1),(type_2,name_2),...)

// -> type_i _name_i = value_i ;
#define EMIT_SIMPLE_CLASS_DECLARE_WITH_DEFAULT(elem) \
  BOOST_PP_TUPLE_ELEM(0, elem) BOOST_PP_CAT(_, BOOST_PP_TUPLE_ELEM(1, elem)) = BOOST_PP_TUPLE_ELEM(2, elem)

#define EMIT_SIMPLE_CLASS_DECLARE_WITHOUT_DEFAULT(elem) \
  BOOST_PP_TUPLE_ELEM(0, elem) BOOST_PP_CAT(_, BOOST_PP_TUPLE_ELEM(1, elem))

// -> type_i _name_i ;
#define EMIT_SIMPLE_CLASS_DECLARE(r, data, i, elem) \
  BOOST_PP_IF(BOOST_PP_EQUAL(BOOST_PP_TUPLE_SIZE(elem) , 3), EMIT_SIMPLE_CLASS_DECLARE_WITH_DEFAULT(elem), EMIT_SIMPLE_CLASS_DECLARE_WITHOUT_DEFAULT(elem));

// ->  type_i _name_i ; ...
#define EMIT_SIMPLE_CLASS_DECLARE_ALL(name) PROCESS_TUPLE(EMIT_SIMPLE_CLASS_DECLARE, name, name)

// ->  type_i _name_i ; ...
#define EMIT_SIMPLE_CLASS_DECLARE_ALL_NMSPC(nmspc, name) \
  PROCESS_TUPLE(EMIT_SIMPLE_CLASS_DECLARE, nmspc##_##name, nmspc##_##name)

// type_1 name_1 , ...
#define EMIT_SIMPLE_CLASS_PYBIND11_DECLARE(r, data, i, elem) \
  BOOST_PP_COMMA_IF(i) BOOST_PP_TUPLE_ELEM(0, elem) BOOST_PP_TUPLE_ELEM(1, elem)

// name_1, ...
#define EMIT_SIMPLE_CLASS_PYBIND11_LIST_NAMES(r, data, i, elem) \
  BOOST_PP_COMMA_IF(i) BOOST_PP_TUPLE_ELEM(1, elem)

// py::arg(name_1), ...
#define EMIT_SIMPLE_CLASS_PYBIND11_LIST_DOC_NAMES(r, data, i, elem) \
  BOOST_PP_COMMA_IF(i) py::arg(BOOST_PP_STRINGIZE(BOOST_PP_TUPLE_ELEM(1, elem)))

// .def_readwrite<>("name_1",&simple_class::name1
#define EMIT_SIMPLE_CLASS_PYBIND11_PROPERTIES(r, data, i, elem)      \
  .def_readwrite<>(BOOST_PP_STRINGIZE(BOOST_PP_TUPLE_ELEM(1, elem)), \
                                      &data::BOOST_PP_CAT(_, BOOST_PP_TUPLE_ELEM(1, elem)))
// pybind init + properties
#define EMIT_SIMPLE_CLASS_PYBIND11(name, m)                                                    \
  py::class_<name>(                                                                            \
      m, BOOST_PP_STRINGIZE(name))                                                             \
             .def(py::init(                                                                    \
                      [](PROCESS_TUPLE(EMIT_SIMPLE_CLASS_PYBIND11_DECLARE, name, name)) {      \
                        return name{                                                           \
                            PROCESS_TUPLE(EMIT_SIMPLE_CLASS_PYBIND11_LIST_NAMES, name, name)}; \
                      }),                                                                      \
                  PROCESS_TUPLE(EMIT_SIMPLE_CLASS_PYBIND11_LIST_DOC_NAMES, name, name))        \
                 PROCESS_TUPLE(EMIT_SIMPLE_CLASS_PYBIND11_PROPERTIES, name, name)

// .def_readwrite<>("name_1",&namespace::simple_class::name1
#define EMIT_SIMPLE_CLASS_PYBIND11_NPSPC_PROPERTIES(r, data, i, elem)                     \
  .def_readwrite<>(BOOST_PP_STRINGIZE(BOOST_PP_TUPLE_ELEM(1, elem)),                      \
                                      &BOOST_PP_TUPLE_ELEM(0, data)::BOOST_PP_TUPLE_ELEM( \
                                          1, data)::BOOST_PP_CAT(_, BOOST_PP_TUPLE_ELEM(1, elem)))

// pybind init + properties
#define EMIT_SIMPLE_NAMESPACE_CLASS_PYBIND11(nmspc, name, m)                                   \
  py::class_<nmspc::name>(                                                                     \
      m, BOOST_PP_STRINGIZE(name))                                                             \
             .def(py::init(                                                                    \
                      [](PROCESS_TUPLE(EMIT_SIMPLE_CLASS_PYBIND11_DECLARE, nmspc##_##name,     \
                                       nmspc##_##name)) {      \
                        return nmspc::name{                                                    \
                            PROCESS_TUPLE(EMIT_SIMPLE_CLASS_PYBIND11_LIST_NAMES, \
                                                         nmspc##_##name, nmspc##_##name)}; \
                      }),                                                                      \
                  PROCESS_TUPLE(EMIT_SIMPLE_CLASS_PYBIND11_LIST_DOC_NAMES, nmspc##_##name,      \
                                nmspc##_##name))        \
                 PROCESS_TUPLE(EMIT_SIMPLE_CLASS_PYBIND11_NPSPC_PROPERTIES, (nmspc, name),      \
                               nmspc##_##name)
