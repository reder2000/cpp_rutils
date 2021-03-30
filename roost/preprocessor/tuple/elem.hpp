# /* Copyright (C) 2001
#  * Housemarque Oy
#  * http://www.housemarque.com
#  *
#  * Distributed under the Roost Software License, Version 1.0. (See
#  * accompanying file LICENSE_1_0.txt or copy at
#  * http://www.roost.org/LICENSE_1_0.txt)
#  */
#
# /* Revised by Paul Mensonides (2002-2011) */
# /* Revised by Edward Diener (2011,2014,2020) */
#
# /* See http://www.roost.org for most recent version. */
#
# ifndef ROOST_PREPROCESSOR_TUPLE_ELEM_HPP
# define ROOST_PREPROCESSOR_TUPLE_ELEM_HPP
#
# include <roost/preprocessor/cat.hpp>
# include <roost/preprocessor/config/config.hpp>
# include <roost/preprocessor/facilities/expand.hpp>
# include <roost/preprocessor/facilities/overload.hpp>
# include <roost/preprocessor/tuple/rem.hpp>
# include <roost/preprocessor/variadic/elem.hpp>
# include <roost/preprocessor/tuple/detail/is_single_return.hpp>
#
# if ROOST_PP_VARIADICS_MSVC
#     define ROOST_PP_TUPLE_ELEM(...) ROOST_PP_TUPLE_ELEM_I(ROOST_PP_OVERLOAD(ROOST_PP_TUPLE_ELEM_O_, __VA_ARGS__), (__VA_ARGS__))
#     define ROOST_PP_TUPLE_ELEM_I(m, args) ROOST_PP_TUPLE_ELEM_II(m, args)
#     define ROOST_PP_TUPLE_ELEM_II(m, args) ROOST_PP_CAT(m ## args,)
/*
  Use ROOST_PP_REM_CAT if it is a single element tuple ( which might be empty )
  else use ROOST_PP_REM. This fixes a VC++ problem with an empty tuple and ROOST_PP_TUPLE_ELEM
  functionality. See tuple_elem_bug_test.cxx.
*/
#     define ROOST_PP_TUPLE_ELEM_O_2(n, tuple) \
         ROOST_PP_VARIADIC_ELEM(n, ROOST_PP_EXPAND(ROOST_PP_TUPLE_IS_SINGLE_RETURN(ROOST_PP_REM_CAT,ROOST_PP_REM,tuple) tuple)) \
         /**/
# else
#     define ROOST_PP_TUPLE_ELEM(...) ROOST_PP_OVERLOAD(ROOST_PP_TUPLE_ELEM_O_, __VA_ARGS__)(__VA_ARGS__)
#     define ROOST_PP_TUPLE_ELEM_O_2(n, tuple) ROOST_PP_VARIADIC_ELEM(n, ROOST_PP_REM tuple)
# endif
# define ROOST_PP_TUPLE_ELEM_O_3(size, n, tuple) ROOST_PP_TUPLE_ELEM_O_2(n, tuple)
#
# /* directly used elsewhere in Roost... */
#
# define ROOST_PP_TUPLE_ELEM_1_0(a) a
#
# define ROOST_PP_TUPLE_ELEM_2_0(a, b) a
# define ROOST_PP_TUPLE_ELEM_2_1(a, b) b
#
# define ROOST_PP_TUPLE_ELEM_3_0(a, b, c) a
# define ROOST_PP_TUPLE_ELEM_3_1(a, b, c) b
# define ROOST_PP_TUPLE_ELEM_3_2(a, b, c) c
#
# endif
