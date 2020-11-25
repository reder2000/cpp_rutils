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
# ifndef ROOST_PREPROCESSOR_PUNCTUATION_COMMA_IF_HPP
# define ROOST_PREPROCESSOR_PUNCTUATION_COMMA_IF_HPP
#
# include <roost/preprocessor/config/config.hpp>
# include <roost/preprocessor/control/if.hpp>
# include <roost/preprocessor/facilities/empty.hpp>
# include <roost/preprocessor/punctuation/comma.hpp>
#
# /* ROOST_PP_COMMA_IF */
#
# if ~ROOST_PP_CONFIG_FLAGS() & ROOST_PP_CONFIG_EDG()
#    define ROOST_PP_COMMA_IF(cond) ROOST_PP_IF(cond, ROOST_PP_COMMA, ROOST_PP_EMPTY)()
# else
#    define ROOST_PP_COMMA_IF(cond) ROOST_PP_COMMA_IF_I(cond)
#    define ROOST_PP_COMMA_IF_I(cond) ROOST_PP_IF(cond, ROOST_PP_COMMA, ROOST_PP_EMPTY)()
# endif
#
# endif
