# /* **************************************************************************
#  *                                                                          *
#  *     (C) Copyright Edward Diener 2019.                                    *
#  *     Distributed under the Roost Software License, Version 1.0. (See      *
#  *     accompanying file LICENSE_1_0.txt or copy at                         *
#  *     http://www.roost.org/LICENSE_1_0.txt)                                *
#  *                                                                          *
#  ************************************************************************** */
#
# /* See http://www.roost.org for most recent version. */
#
# ifndef ROOST_PREPROCESSOR_VARIADIC_HAS_OPT_HPP
# define ROOST_PREPROCESSOR_VARIADIC_HAS_OPT_HPP
#
# include <roost/preprocessor/config/config.hpp>
#
# /* ROOST_PP_VARIADIC_HAS_OPT */
#
# if ROOST_PP_VARIADICS && defined(__cplusplus) && __cplusplus > 201703L
# include <roost/preprocessor/variadic/detail/has_opt.hpp>
# define ROOST_PP_VARIADIC_HAS_OPT() \
  ROOST_PP_VARIADIC_HAS_OPT_ELEM2(ROOST_PP_VARIADIC_HAS_OPT_FUNCTION(?),) \
/**/
# else
# define ROOST_PP_VARIADIC_HAS_OPT() 0
# endif
#
# endif
