# /* **************************************************************************
#  *                                                                          *
#  *     (C) Copyright Edward Diener 2011.                                    *
#  *     (C) Copyright Paul Mensonides 2011.                                  *
#  *     Distributed under the Roost Software License, Version 1.0. (See      *
#  *     accompanying file LICENSE_1_0.txt or copy at                         *
#  *     http://www.roost.org/LICENSE_1_0.txt)                                *
#  *                                                                          *
#  ************************************************************************** */
#
# /* See http://www.roost.org for most recent version. */
#
# ifndef ROOST_PREPROCESSOR_TUPLE_SIZE_HPP
# define ROOST_PREPROCESSOR_TUPLE_SIZE_HPP
#
# include <roost/preprocessor/cat.hpp>
# include <roost/preprocessor/config/config.hpp>
# include <roost/preprocessor/variadic/size.hpp>
#
# if ROOST_PP_VARIADICS
#    if ROOST_PP_VARIADICS_MSVC
#        define ROOST_PP_TUPLE_SIZE(tuple) ROOST_PP_CAT(ROOST_PP_VARIADIC_SIZE tuple,)
#    else
#        define ROOST_PP_TUPLE_SIZE(tuple) ROOST_PP_VARIADIC_SIZE tuple
#    endif
# endif
#
# endif
