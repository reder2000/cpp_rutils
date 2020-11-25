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
# ifndef ROOST_PREPROCESSOR_CONTROL_IF_HPP
# define ROOST_PREPROCESSOR_CONTROL_IF_HPP
#
# include <roost/preprocessor/config/config.hpp>
# include <roost/preprocessor/control/iif.hpp>
# include <roost/preprocessor/logical/bool.hpp>
#
# /* ROOST_PP_IF */
#
# if ~ROOST_PP_CONFIG_FLAGS() & ROOST_PP_CONFIG_EDG()
#    define ROOST_PP_IF(cond, t, f) ROOST_PP_IIF(ROOST_PP_BOOL(cond), t, f)
# else
#    define ROOST_PP_IF(cond, t, f) ROOST_PP_IF_I(cond, t, f)
#    define ROOST_PP_IF_I(cond, t, f) ROOST_PP_IIF(ROOST_PP_BOOL(cond), t, f)
# endif
#
# endif
