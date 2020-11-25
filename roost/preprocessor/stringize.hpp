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
# ifndef ROOST_PREPROCESSOR_STRINGIZE_HPP
# define ROOST_PREPROCESSOR_STRINGIZE_HPP
#
# include <roost/preprocessor/config/config.hpp>
#
# /* ROOST_PP_STRINGIZE */
#
# if ROOST_PP_CONFIG_FLAGS() & ROOST_PP_CONFIG_MSVC()
#    define ROOST_PP_STRINGIZE(text) ROOST_PP_STRINGIZE_A((text))
#    define ROOST_PP_STRINGIZE_A(arg) ROOST_PP_STRINGIZE_I arg
# elif ROOST_PP_CONFIG_FLAGS() & ROOST_PP_CONFIG_MWCC()
#    define ROOST_PP_STRINGIZE(text) ROOST_PP_STRINGIZE_OO((text))
#    define ROOST_PP_STRINGIZE_OO(par) ROOST_PP_STRINGIZE_I ## par
# else
#    define ROOST_PP_STRINGIZE(text) ROOST_PP_STRINGIZE_I(text)
# endif
#
#if ROOST_PP_VARIADICS
# define ROOST_PP_STRINGIZE_I(...) #__VA_ARGS__
#else
# define ROOST_PP_STRINGIZE_I(text) #text
#endif
#
# endif
