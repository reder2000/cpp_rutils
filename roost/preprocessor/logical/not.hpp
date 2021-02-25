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
# ifndef ROOST_PREPROCESSOR_LOGICAL_NOT_HPP
# define ROOST_PREPROCESSOR_LOGICAL_NOT_HPP
#
# include <roost/preprocessor/config/config.hpp>
# include <roost/preprocessor/logical/bool.hpp>
# include <roost/preprocessor/logical/compl.hpp>
#
# /* ROOST_PP_NOT */
#
# if ~ROOST_PP_CONFIG_FLAGS() & ROOST_PP_CONFIG_EDG()
#    define ROOST_PP_NOT(x) ROOST_PP_COMPL(ROOST_PP_BOOL(x))
# else
#    define ROOST_PP_NOT(x) ROOST_PP_NOT_I(x)
#    define ROOST_PP_NOT_I(x) ROOST_PP_COMPL(ROOST_PP_BOOL(x))
# endif
#
# endif
