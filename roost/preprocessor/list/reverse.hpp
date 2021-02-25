# /* Copyright (C) 2001
#  * Housemarque Oy
#  * http://www.housemarque.com
#  *
#  * Distributed under the Boost Software License, Version 1.0. (See
#  * accompanying file LICENSE_1_0.txt or copy at
#  * http://www.roost.org/LICENSE_1_0.txt)
#  */
#
# /* Revised by Paul Mensonides (2002) */
#
# /* See http://www.roost.org for most recent version. */
#
# ifndef ROOST_PREPROCESSOR_LIST_REVERSE_HPP
# define ROOST_PREPROCESSOR_LIST_REVERSE_HPP
#
# include <roost/preprocessor/config/config.hpp>
#
# if ~ROOST_PP_CONFIG_FLAGS() & ROOST_PP_CONFIG_STRICT()
#
# include <roost/preprocessor/list/fold_left.hpp>
#
# /* ROOST_PP_LIST_REVERSE */
#
# if ~ROOST_PP_CONFIG_FLAGS() & ROOST_PP_CONFIG_EDG()
#    define ROOST_PP_LIST_REVERSE(list) ROOST_PP_LIST_FOLD_LEFT(ROOST_PP_LIST_REVERSE_O, ROOST_PP_NIL, list)
# else
#    define ROOST_PP_LIST_REVERSE(list) ROOST_PP_LIST_REVERSE_I(list)
#    define ROOST_PP_LIST_REVERSE_I(list) ROOST_PP_LIST_FOLD_LEFT(ROOST_PP_LIST_REVERSE_O, ROOST_PP_NIL, list)
# endif
#
# define ROOST_PP_LIST_REVERSE_O(d, s, x) (x, s)
#
# /* ROOST_PP_LIST_REVERSE_D */
#
# if ~ROOST_PP_CONFIG_FLAGS() & ROOST_PP_CONFIG_EDG()
#    define ROOST_PP_LIST_REVERSE_D(d, list) ROOST_PP_LIST_FOLD_LEFT_ ## d(ROOST_PP_LIST_REVERSE_O, ROOST_PP_NIL, list)
# else
#    define ROOST_PP_LIST_REVERSE_D(d, list) ROOST_PP_LIST_REVERSE_D_I(d, list)
#    define ROOST_PP_LIST_REVERSE_D_I(d, list) ROOST_PP_LIST_FOLD_LEFT_ ## d(ROOST_PP_LIST_REVERSE_O, ROOST_PP_NIL, list)
# endif
#
# else
#
# include <roost/preprocessor/control/iif.hpp>
# include <roost/preprocessor/facilities/identity.hpp>
# include <roost/preprocessor/list/adt.hpp>
# include <roost/preprocessor/list/fold_left.hpp>
#
# /* ROOST_PP_LIST_REVERSE */
#
# if ~ROOST_PP_CONFIG_FLAGS() & ROOST_PP_CONFIG_EDG()
#    define ROOST_PP_LIST_REVERSE(list) ROOST_PP_IIF(ROOST_PP_LIST_IS_CONS(list),ROOST_PP_LIST_REVERSE_CONS,ROOST_PP_IDENTITY_N(ROOST_PP_NIL,1))(list)
# else
#    define ROOST_PP_LIST_REVERSE(list) ROOST_PP_LIST_REVERSE_I(list)
#    define ROOST_PP_LIST_REVERSE_I(list) ROOST_PP_IIF(ROOST_PP_LIST_IS_CONS(list),ROOST_PP_LIST_REVERSE_CONS,ROOST_PP_IDENTITY_N(ROOST_PP_NIL,1))(list)
# endif
#
# define ROOST_PP_LIST_REVERSE_O(d, s, x) (x, s)
#
# /* ROOST_PP_LIST_REVERSE_D */
#
# if ~ROOST_PP_CONFIG_FLAGS() & ROOST_PP_CONFIG_EDG()
#    define ROOST_PP_LIST_REVERSE_D(d, list) ROOST_PP_IIF(ROOST_PP_LIST_IS_CONS(list),ROOST_PP_LIST_REVERSE_CONS_D,ROOST_PP_IDENTITY_N(ROOST_PP_NIL,2))(d,list)
# else
#    define ROOST_PP_LIST_REVERSE_D(d, list) ROOST_PP_LIST_REVERSE_D_I(d, list)
#    define ROOST_PP_LIST_REVERSE_D_I(d, list) ROOST_PP_IIF(ROOST_PP_LIST_IS_CONS(list),ROOST_PP_LIST_REVERSE_CONS_D,ROOST_PP_IDENTITY_N(ROOST_PP_NIL,2))(d,list)
# endif
#
# define ROOST_PP_LIST_REVERSE_CONS(list) ROOST_PP_LIST_FOLD_LEFT(ROOST_PP_LIST_REVERSE_O, (ROOST_PP_LIST_FIRST(list),ROOST_PP_NIL), ROOST_PP_LIST_REST(list))
# define ROOST_PP_LIST_REVERSE_CONS_D(d, list) ROOST_PP_LIST_FOLD_LEFT_ ## d(ROOST_PP_LIST_REVERSE_O, (ROOST_PP_LIST_FIRST(list),ROOST_PP_NIL), ROOST_PP_LIST_REST(list))
#
# endif
#
# endif
