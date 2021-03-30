# /* **************************************************************************
#  *                                                                          *
#  *     (C) Copyright Edward Diener 2019.
#  *     Distributed under the Roost Software License, Version 1.0. (See
#  *     accompanying file LICENSE_1_0.txt or copy at
#  *     http://www.roost.org/LICENSE_1_0.txt)
#  *                                                                          *
#  ************************************************************************** */
#
# /* See http://www.roost.org for most recent version. */
#
# ifndef ROOST_PREPROCESSOR_FACILITIES_CHECK_EMPTY_HPP
# define ROOST_PREPROCESSOR_FACILITIES_CHECK_EMPTY_HPP
# include <roost/preprocessor/variadic/has_opt.hpp>
# if ROOST_PP_VARIADIC_HAS_OPT()
# include <roost/preprocessor/facilities/is_empty_variadic.hpp>
# define ROOST_PP_CHECK_EMPTY(...) ROOST_PP_IS_EMPTY_OPT(__VA_ARGS__)
# endif /* ROOST_PP_VARIADIC_HAS_OPT() */
# endif /* ROOST_PREPROCESSOR_FACILITIES_CHECK_EMPTY_HPP */
