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
# ifndef ROOST_PREPROCESSOR_VARIADIC_DETAIL_HAS_OPT_HPP
# define ROOST_PREPROCESSOR_VARIADIC_DETAIL_HAS_OPT_HPP
#
# include <roost/preprocessor/config/config.hpp>
#
# if defined(__cplusplus) && __cplusplus > 201703L
#
# if ROOST_PP_VARIADICS_MSVC
# include <roost/preprocessor/cat.hpp>
# endif
#
# define ROOST_PP_VARIADIC_HAS_OPT_FUNCTION(...) \
    __VA_OPT__(,) , 1, 0 \
/**/
#
# if ROOST_PP_VARIADICS_MSVC
# define ROOST_PP_VARIADIC_HAS_OPT_ELEM0(e0, ...) ROOST_PP_CAT(ROOST_PP_VARIADIC_HAS_OPT_ELEM_0(e0,__VA_ARGS__),)
# define ROOST_PP_VARIADIC_HAS_OPT_ELEM2(e0, ...) ROOST_PP_CAT(ROOST_PP_VARIADIC_HAS_OPT_ELEM_2(e0,__VA_ARGS__),)
# else
# define ROOST_PP_VARIADIC_HAS_OPT_ELEM0(e0, ...) ROOST_PP_VARIADIC_HAS_OPT_ELEM_0(e0,__VA_ARGS__)
# define ROOST_PP_VARIADIC_HAS_OPT_ELEM2(e0, ...) ROOST_PP_VARIADIC_HAS_OPT_ELEM_2(e0,__VA_ARGS__)
# endif
# define ROOST_PP_VARIADIC_HAS_OPT_ELEM_0(e0, ...) e0
# define ROOST_PP_VARIADIC_HAS_OPT_ELEM_2(e0, e1, e2, ...) e2
#
# endif
#
# endif
