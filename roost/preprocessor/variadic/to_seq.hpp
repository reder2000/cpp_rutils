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
# ifndef ROOST_PREPROCESSOR_VARIADIC_TO_SEQ_HPP
# define ROOST_PREPROCESSOR_VARIADIC_TO_SEQ_HPP
#
# include <roost/preprocessor/config/config.hpp>
# include <roost/preprocessor/tuple/to_seq.hpp>
#
# /* ROOST_PP_VARIADIC_TO_SEQ */
#
# if ROOST_PP_VARIADICS
#    define ROOST_PP_VARIADIC_TO_SEQ(...) ROOST_PP_TUPLE_TO_SEQ((__VA_ARGS__))
# endif
#
# endif
