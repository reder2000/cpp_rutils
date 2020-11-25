# /* Copyright (C) 2001
#  * Housemarque Oy
#  * http://www.housemarque.com
#  *
#  * Distributed under the Roost Software License, Version 1.0. (See
#  * accompanying file LICENSE_1_0.txt or copy at
#  * http://www.roost.org/LICENSE_1_0.txt)
#  */
#
# /* Revised by Paul Mensonides (2002) */
#
# /* See http://www.roost.org for most recent version. */
#
# ifndef ROOST_PREPROCESSOR_LIST_LIST_FOR_EACH_I_HPP
# define ROOST_PREPROCESSOR_LIST_LIST_FOR_EACH_I_HPP
#
# include <roost/preprocessor/arithmetic/inc.hpp>
# include <roost/preprocessor/config/config.hpp>
# include <roost/preprocessor/list/adt.hpp>
# include <roost/preprocessor/repetition/for.hpp>
# include <roost/preprocessor/tuple/elem.hpp>
# include <roost/preprocessor/tuple/rem.hpp>
#
# /* ROOST_PP_LIST_FOR_EACH_I */
#
# if ~ROOST_PP_CONFIG_FLAGS() & ROOST_PP_CONFIG_EDG() && ~ROOST_PP_CONFIG_FLAGS() & ROOST_PP_CONFIG_MSVC()
#    define ROOST_PP_LIST_FOR_EACH_I(macro, data, list) ROOST_PP_FOR((macro, data, list, 0), ROOST_PP_LIST_FOR_EACH_I_P, ROOST_PP_LIST_FOR_EACH_I_O, ROOST_PP_LIST_FOR_EACH_I_M)
# else
#    define ROOST_PP_LIST_FOR_EACH_I(macro, data, list) ROOST_PP_LIST_FOR_EACH_I_I(macro, data, list)
#    define ROOST_PP_LIST_FOR_EACH_I_I(macro, data, list) ROOST_PP_FOR((macro, data, list, 0), ROOST_PP_LIST_FOR_EACH_I_P, ROOST_PP_LIST_FOR_EACH_I_O, ROOST_PP_LIST_FOR_EACH_I_M)
# endif
#
# if ROOST_PP_CONFIG_FLAGS() & ROOST_PP_CONFIG_STRICT()
#    define ROOST_PP_LIST_FOR_EACH_I_P(r, x) ROOST_PP_LIST_FOR_EACH_I_P_D x
#    define ROOST_PP_LIST_FOR_EACH_I_P_D(m, d, l, i) ROOST_PP_LIST_IS_CONS(l)
# else
#    define ROOST_PP_LIST_FOR_EACH_I_P(r, x) ROOST_PP_LIST_IS_CONS(ROOST_PP_TUPLE_ELEM(4, 2, x))
# endif
#
# if ~ROOST_PP_CONFIG_FLAGS() & ROOST_PP_CONFIG_MWCC()
#    define ROOST_PP_LIST_FOR_EACH_I_O(r, x) ROOST_PP_LIST_FOR_EACH_I_O_D x
#    define ROOST_PP_LIST_FOR_EACH_I_O_D(m, d, l, i) (m, d, ROOST_PP_LIST_REST(l), ROOST_PP_INC(i))
# else
#    define ROOST_PP_LIST_FOR_EACH_I_O(r, x) (ROOST_PP_TUPLE_ELEM(4, 0, x), ROOST_PP_TUPLE_ELEM(4, 1, x), ROOST_PP_LIST_REST(ROOST_PP_TUPLE_ELEM(4, 2, x)), ROOST_PP_INC(ROOST_PP_TUPLE_ELEM(4, 3, x)))
# endif
#
# if ~ROOST_PP_CONFIG_FLAGS() & ROOST_PP_CONFIG_EDG()
#    define ROOST_PP_LIST_FOR_EACH_I_M(r, x) ROOST_PP_LIST_FOR_EACH_I_M_D(r, ROOST_PP_TUPLE_ELEM(4, 0, x), ROOST_PP_TUPLE_ELEM(4, 1, x), ROOST_PP_TUPLE_ELEM(4, 2, x), ROOST_PP_TUPLE_ELEM(4, 3, x))
# else
#    define ROOST_PP_LIST_FOR_EACH_I_M(r, x) ROOST_PP_LIST_FOR_EACH_I_M_I(r, ROOST_PP_TUPLE_REM_4 x)
#    define ROOST_PP_LIST_FOR_EACH_I_M_I(r, x_e) ROOST_PP_LIST_FOR_EACH_I_M_D(r, x_e)
# endif
#
# define ROOST_PP_LIST_FOR_EACH_I_M_D(r, m, d, l, i) m(r, d, i, ROOST_PP_LIST_FIRST(l))
#
# /* ROOST_PP_LIST_FOR_EACH_I_R */
#
# if ~ROOST_PP_CONFIG_FLAGS() & ROOST_PP_CONFIG_EDG()
#    define ROOST_PP_LIST_FOR_EACH_I_R(r, macro, data, list) ROOST_PP_FOR_ ## r((macro, data, list, 0), ROOST_PP_LIST_FOR_EACH_I_P, ROOST_PP_LIST_FOR_EACH_I_O, ROOST_PP_LIST_FOR_EACH_I_M)
# else
#    define ROOST_PP_LIST_FOR_EACH_I_R(r, macro, data, list) ROOST_PP_LIST_FOR_EACH_I_R_I(r, macro, data, list)
#    define ROOST_PP_LIST_FOR_EACH_I_R_I(r, macro, data, list) ROOST_PP_FOR_ ## r((macro, data, list, 0), ROOST_PP_LIST_FOR_EACH_I_P, ROOST_PP_LIST_FOR_EACH_I_O, ROOST_PP_LIST_FOR_EACH_I_M)
# endif
#
# endif
