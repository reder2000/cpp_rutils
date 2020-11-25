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
# ifndef ROOST_PREPROCESSOR_FACILITIES_EXPAND_HPP
# define ROOST_PREPROCESSOR_FACILITIES_EXPAND_HPP
#
# include <roost/preprocessor/config/config.hpp>
#
# if ~ROOST_PP_CONFIG_FLAGS() & ROOST_PP_CONFIG_MWCC() && ~ROOST_PP_CONFIG_FLAGS() & ROOST_PP_CONFIG_DMC()
#    define ROOST_PP_EXPAND(x) ROOST_PP_EXPAND_I(x)
# else
#    define ROOST_PP_EXPAND(x) ROOST_PP_EXPAND_OO((x))
#    define ROOST_PP_EXPAND_OO(par) ROOST_PP_EXPAND_I ## par
# endif
#
# define ROOST_PP_EXPAND_I(x) x
#
# endif
