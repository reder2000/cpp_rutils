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
# ifndef ROOST_PREPROCESSOR_LIST_SIZE_HPP
# define ROOST_PREPROCESSOR_LIST_SIZE_HPP
#
# include <roost/preprocessor/config/config.hpp>
#
# if ~ROOST_PP_CONFIG_FLAGS() & ROOST_PP_CONFIG_STRICT()
#
# include <roost/preprocessor/arithmetic/inc.hpp>
# include <roost/preprocessor/control/while.hpp>
# include <roost/preprocessor/list/adt.hpp>
# include <roost/preprocessor/tuple/elem.hpp>
# include <roost/preprocessor/tuple/rem.hpp>
#
# /* ROOST_PP_LIST_SIZE */
#
# if ~ROOST_PP_CONFIG_FLAGS() & ROOST_PP_CONFIG_EDG()
#    define ROOST_PP_LIST_SIZE(list) ROOST_PP_TUPLE_ELEM(2, 0, ROOST_PP_WHILE(ROOST_PP_LIST_SIZE_P, ROOST_PP_LIST_SIZE_O, (0, list)))
# else
#    define ROOST_PP_LIST_SIZE(list) ROOST_PP_LIST_SIZE_I(list)
#    define ROOST_PP_LIST_SIZE_I(list) ROOST_PP_TUPLE_ELEM(2, 0, ROOST_PP_WHILE(ROOST_PP_LIST_SIZE_P, ROOST_PP_LIST_SIZE_O, (0, list)))
# endif
#
# if ~ROOST_PP_CONFIG_FLAGS() & ROOST_PP_CONFIG_EDG()
#    define ROOST_PP_LIST_SIZE_P(d, rl) ROOST_PP_LIST_IS_CONS(ROOST_PP_TUPLE_ELEM(2, 1, rl))
# else
#    define ROOST_PP_LIST_SIZE_P(d, rl) ROOST_PP_LIST_SIZE_P_I(ROOST_PP_TUPLE_REM_2 rl)
#    define ROOST_PP_LIST_SIZE_P_I(im) ROOST_PP_LIST_SIZE_P_II(im)
#    define ROOST_PP_LIST_SIZE_P_II(r, l) ROOST_PP_LIST_IS_CONS(l)
# endif
#
# if ~ROOST_PP_CONFIG_FLAGS() & ROOST_PP_CONFIG_EDG()
#    define ROOST_PP_LIST_SIZE_O(d, rl) (ROOST_PP_INC(ROOST_PP_TUPLE_ELEM(2, 0, rl)), ROOST_PP_LIST_REST(ROOST_PP_TUPLE_ELEM(2, 1, rl)))
# else
#    define ROOST_PP_LIST_SIZE_O(d, rl) ROOST_PP_LIST_SIZE_O_I(ROOST_PP_TUPLE_REM_2 rl)
#    define ROOST_PP_LIST_SIZE_O_I(im) ROOST_PP_LIST_SIZE_O_II(im)
#    define ROOST_PP_LIST_SIZE_O_II(r, l) (ROOST_PP_INC(r), ROOST_PP_LIST_REST(l))
# endif
#
# /* ROOST_PP_LIST_SIZE_D */
#
# if ~ROOST_PP_CONFIG_FLAGS() & ROOST_PP_CONFIG_EDG()
#    define ROOST_PP_LIST_SIZE_D(d, list) ROOST_PP_TUPLE_ELEM(2, 0, ROOST_PP_WHILE_ ## d(ROOST_PP_LIST_SIZE_P, ROOST_PP_LIST_SIZE_O, (0, list)))
# else
#    define ROOST_PP_LIST_SIZE_D(d, list) ROOST_PP_LIST_SIZE_D_I(d, list)
#    define ROOST_PP_LIST_SIZE_D_I(d, list) ROOST_PP_TUPLE_ELEM(2, 0, ROOST_PP_WHILE_ ## d(ROOST_PP_LIST_SIZE_P, ROOST_PP_LIST_SIZE_O, (0, list)))
# endif
#
# else
#
# include <roost/preprocessor/arithmetic/inc.hpp>
# include <roost/preprocessor/control/iif.hpp>
# include <roost/preprocessor/control/while.hpp>
# include <roost/preprocessor/facilities/identity.hpp>
# include <roost/preprocessor/list/adt.hpp>
# include <roost/preprocessor/tuple/elem.hpp>
# include <roost/preprocessor/tuple/rem.hpp>
#
# /* ROOST_PP_LIST_SIZE */
#
#    define ROOST_PP_LIST_SIZE(list) ROOST_PP_IIF(ROOST_PP_LIST_IS_CONS(list),ROOST_PP_LIST_SIZE_S,ROOST_PP_IDENTITY_N(0,1))(list)
#    define ROOST_PP_LIST_SIZE_S(list) ROOST_PP_LIST_SIZE_DO(ROOST_PP_LIST_REST(list))
#
# if ~ROOST_PP_CONFIG_FLAGS() & ROOST_PP_CONFIG_EDG()
#    define ROOST_PP_LIST_SIZE_DO(list) ROOST_PP_TUPLE_ELEM(2, 0, ROOST_PP_WHILE(ROOST_PP_LIST_SIZE_P, ROOST_PP_LIST_SIZE_O, (1, list)))
# else
#    define ROOST_PP_LIST_SIZE_DO(list) ROOST_PP_LIST_SIZE_I(list)
#    define ROOST_PP_LIST_SIZE_I(list) ROOST_PP_TUPLE_ELEM(2, 0, ROOST_PP_WHILE(ROOST_PP_LIST_SIZE_P, ROOST_PP_LIST_SIZE_O, (1, list)))
# endif
#
# if ~ROOST_PP_CONFIG_FLAGS() & ROOST_PP_CONFIG_EDG()
#    define ROOST_PP_LIST_SIZE_P(d, rl) ROOST_PP_LIST_IS_CONS(ROOST_PP_TUPLE_ELEM(2, 1, rl))
# else
#    define ROOST_PP_LIST_SIZE_P(d, rl) ROOST_PP_LIST_SIZE_P_I(ROOST_PP_TUPLE_REM_2 rl)
#    define ROOST_PP_LIST_SIZE_P_I(im) ROOST_PP_LIST_SIZE_P_II(im)
#    define ROOST_PP_LIST_SIZE_P_II(r, l) ROOST_PP_LIST_IS_CONS(l)
# endif
#
# if ~ROOST_PP_CONFIG_FLAGS() & ROOST_PP_CONFIG_EDG()
#    define ROOST_PP_LIST_SIZE_O(d, rl) (ROOST_PP_INC(ROOST_PP_TUPLE_ELEM(2, 0, rl)), ROOST_PP_LIST_REST(ROOST_PP_TUPLE_ELEM(2, 1, rl)))
# else
#    define ROOST_PP_LIST_SIZE_O(d, rl) ROOST_PP_LIST_SIZE_O_I(ROOST_PP_TUPLE_REM_2 rl)
#    define ROOST_PP_LIST_SIZE_O_I(im) ROOST_PP_LIST_SIZE_O_II(im)
#    define ROOST_PP_LIST_SIZE_O_II(r, l) (ROOST_PP_INC(r), ROOST_PP_LIST_REST(l))
# endif
#
# /* ROOST_PP_LIST_SIZE_D */
#
#    define ROOST_PP_LIST_SIZE_D(d, list) ROOST_PP_IIF(ROOST_PP_LIST_IS_CONS(list),ROOST_PP_LIST_SIZE_S_D,ROOST_PP_IDENTITY_N(0,2))(d,list)
#    define ROOST_PP_LIST_SIZE_S_D(d,list) ROOST_PP_LIST_SIZE_DO_D(d,ROOST_PP_LIST_REST(list))
#
# if ~ROOST_PP_CONFIG_FLAGS() & ROOST_PP_CONFIG_EDG()
#    define ROOST_PP_LIST_SIZE_DO_D(d, list) ROOST_PP_TUPLE_ELEM(2, 0, ROOST_PP_WHILE_ ## d(ROOST_PP_LIST_SIZE_P, ROOST_PP_LIST_SIZE_O, (1, list)))
# else
#    define ROOST_PP_LIST_SIZE_DO_D(d, list) ROOST_PP_LIST_SIZE_D_I(d, list)
#    define ROOST_PP_LIST_SIZE_D_I(d, list) ROOST_PP_TUPLE_ELEM(2, 0, ROOST_PP_WHILE_ ## d(ROOST_PP_LIST_SIZE_P, ROOST_PP_LIST_SIZE_O, (1, list)))
# endif
#
# endif
#
# endif
