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
# ifndef ROOST_PREPROCESSOR_COMPARISON_EQUAL_HPP
# define ROOST_PREPROCESSOR_COMPARISON_EQUAL_HPP
#
# include <roost/preprocessor/comparison/not_equal.hpp>
# include <roost/preprocessor/config/config.hpp>
# include <roost/preprocessor/logical/compl.hpp>
#
# /* ROOST_PP_EQUAL */
#
# if ~ROOST_PP_CONFIG_FLAGS() & ROOST_PP_CONFIG_EDG()
#    define ROOST_PP_EQUAL(x, y) ROOST_PP_COMPL(ROOST_PP_NOT_EQUAL(x, y))
# else
#    define ROOST_PP_EQUAL(x, y) ROOST_PP_EQUAL_I(x, y)
#    define ROOST_PP_EQUAL_I(x, y) ROOST_PP_COMPL(ROOST_PP_NOT_EQUAL(x, y))
# endif
#
# /* ROOST_PP_EQUAL_D */
#
# define ROOST_PP_EQUAL_D(d, x, y) ROOST_PP_EQUAL(x, y)
#
# endif
