#pragma once 

#include "enum.h"
#include "boost/preprocessor/tuple/elem.hpp"

// name_tuple = ((type_1,name_1),(type_2,name_2),...)

// -> type_i name_i
#define EMIT_SIMPLE_CLASS_DECLARE(r, data, i, elem) \
	BOOST_PP_TUPLE_ELEM(0,elem) BOOST_PP_TUPLE_ELEM(1,elem);


// name => name_tuple_sl = tuple_sl<"a","b",...>
#define EMIT_SIMPLE_CLASS_DECLARE_ALL(name) \
		BOOST_PP_LIST_FOR_EACH_I(EMIT_SIMPLE_CLASS_DECLARE,name,BOOST_PP_TUPLE_TO_LIST(NAME_TUPLE(name)))  

