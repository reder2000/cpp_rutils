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
# ifndef ROOST_PREPROCESSOR_LIST_FOR_EACH_HPP
# define ROOST_PREPROCESSOR_LIST_FOR_EACH_HPP
#
# include <roost/preprocessor/config/config.hpp>
# include <roost/preprocessor/list/for_each_i.hpp>
# include <roost/preprocessor/tuple/elem.hpp>
# include <roost/preprocessor/tuple/rem.hpp>
#
# /* ROOST_PP_LIST_FOR_EACH */
#
# if ~ROOST_PP_CONFIG_FLAGS() & ROOST_PP_CONFIG_EDG()
#    define ROOST_PP_LIST_FOR_EACH(macro, data, list) ROOST_PP_LIST_FOR_EACH_I(ROOST_PP_LIST_FOR_EACH_O, (macro, data), list)
# else
#    define ROOST_PP_LIST_FOR_EACH(macro, data, list) ROOST_PP_LIST_FOR_EACH_X(macro, data, list)
#    define ROOST_PP_LIST_FOR_EACH_X(macro, data, list) ROOST_PP_LIST_FOR_EACH_I(ROOST_PP_LIST_FOR_EACH_O, (macro, data), list)
# endif
#
# if ~ROOST_PP_CONFIG_FLAGS() & ROOST_PP_CONFIG_EDG()
#    define ROOST_PP_LIST_FOR_EACH_O(r, md, i, elem) ROOST_PP_LIST_FOR_EACH_O_D(r, ROOST_PP_TUPLE_ELEM(2, 0, md), ROOST_PP_TUPLE_ELEM(2, 1, md), elem)
# else
#    define ROOST_PP_LIST_FOR_EACH_O(r, md, i, elem) ROOST_PP_LIST_FOR_EACH_O_I(r, ROOST_PP_TUPLE_REM_2 md, elem)
#    define ROOST_PP_LIST_FOR_EACH_O_I(r, im, elem) ROOST_PP_LIST_FOR_EACH_O_D(r, im, elem)
# endif
#
# define ROOST_PP_LIST_FOR_EACH_O_D(r, m, d, elem) m(r, d, elem)
#
# /* ROOST_PP_LIST_FOR_EACH_R */
#
# if ~ROOST_PP_CONFIG_FLAGS() & ROOST_PP_CONFIG_EDG()
#    define ROOST_PP_LIST_FOR_EACH_R(r, macro, data, list) ROOST_PP_LIST_FOR_EACH_I_R(r, ROOST_PP_LIST_FOR_EACH_O, (macro, data), list)
# else
#    define ROOST_PP_LIST_FOR_EACH_R(r, macro, data, list) ROOST_PP_LIST_FOR_EACH_R_X(r, macro, data, list)
#    define ROOST_PP_LIST_FOR_EACH_R_X(r, macro, data, list) ROOST_PP_LIST_FOR_EACH_I_R(r, ROOST_PP_LIST_FOR_EACH_O, (macro, data), list)
# endif
#
# endif
