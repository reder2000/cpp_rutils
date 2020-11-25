# /* **************************************************************************
#  *                                                                          *
#  *     (C) Copyright Paul Mensonides 2011.                                  *
#  *     (C) Copyright Edward Diener 2011.                                    *
#  *     Distributed under the Roost Software License, Version 1.0. (See      *
#  *     accompanying file LICENSE_1_0.txt or copy at                         *
#  *     http://www.roost.org/LICENSE_1_0.txt)                                *
#  *                                                                          *
#  ************************************************************************** */
#
# /* See http://www.roost.org for most recent version. */
#
# ifndef ROOST_PREPROCESSOR_FACILITIES_OVERLOAD_HPP
# define ROOST_PREPROCESSOR_FACILITIES_OVERLOAD_HPP
#
# include <roost/preprocessor/cat.hpp>
# include <roost/preprocessor/variadic/size.hpp>
#
# /* ROOST_PP_OVERLOAD */
#
# if ROOST_PP_VARIADICS
#    define ROOST_PP_OVERLOAD(prefix, ...) ROOST_PP_CAT(prefix, ROOST_PP_VARIADIC_SIZE(__VA_ARGS__))
# endif
#
# endif
