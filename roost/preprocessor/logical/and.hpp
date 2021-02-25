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
# ifndef ROOST_PREPROCESSOR_LOGICAL_AND_HPP
# define ROOST_PREPROCESSOR_LOGICAL_AND_HPP
#
# include <roost/preprocessor/config/config.hpp>
# include <roost/preprocessor/logical/bool.hpp>
# include <roost/preprocessor/logical/bitand.hpp>
#
# /* ROOST_PP_AND */
#
# if ~ROOST_PP_CONFIG_FLAGS() & ROOST_PP_CONFIG_EDG()
#    define ROOST_PP_AND(p, q) ROOST_PP_BITAND(ROOST_PP_BOOL(p), ROOST_PP_BOOL(q))
# else
#    define ROOST_PP_AND(p, q) ROOST_PP_AND_I(p, q)
#    define ROOST_PP_AND_I(p, q) ROOST_PP_BITAND(ROOST_PP_BOOL(p), ROOST_PP_BOOL(q))
# endif
#
# endif
