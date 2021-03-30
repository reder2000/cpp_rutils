# /* **************************************************************************
#  *                                                                          *
#  *     (C) Copyright Edward Diener 2014,2019.
#  *     Distributed under the Roost Software License, Version 1.0. (See
#  *     accompanying file LICENSE_1_0.txt or copy at
#  *     http://www.roost.org/LICENSE_1_0.txt)
#  *                                                                          *
#  ************************************************************************** */
#
# /* See http://www.roost.org for most recent version. */
#
# ifndef ROOST_PREPROCESSOR_FACILITIES_IS_EMPTY_VARIADIC_HPP
# define ROOST_PREPROCESSOR_FACILITIES_IS_EMPTY_VARIADIC_HPP
#
# include <roost/preprocessor/config/config.hpp>
# include <roost/preprocessor/punctuation/is_begin_parens.hpp>
# include <roost/preprocessor/facilities/detail/is_empty.hpp>
#
#if ROOST_PP_VARIADICS_MSVC && _MSC_VER <= 1400
#
#define ROOST_PP_IS_EMPTY(param) \
    ROOST_PP_DETAIL_IS_EMPTY_IIF \
      ( \
      ROOST_PP_IS_BEGIN_PARENS \
        ( \
        param \
        ) \
      ) \
      ( \
      ROOST_PP_IS_EMPTY_ZERO, \
      ROOST_PP_DETAIL_IS_EMPTY_PROCESS \
      ) \
    (param) \
/**/
#define ROOST_PP_IS_EMPTY_ZERO(param) 0
# else
# if defined(__cplusplus) && __cplusplus > 201703L
# include <roost/preprocessor/variadic/has_opt.hpp>
#define ROOST_PP_IS_EMPTY(...) \
    ROOST_PP_DETAIL_IS_EMPTY_IIF \
      ( \
      ROOST_PP_VARIADIC_HAS_OPT() \
      ) \
      ( \
      ROOST_PP_IS_EMPTY_OPT, \
      ROOST_PP_IS_EMPTY_NO_OPT \
      ) \
    (__VA_ARGS__) \
/**/
#define ROOST_PP_IS_EMPTY_FUNCTION2(...) \
    __VA_OPT__(0,) 1 \
/**/
#define ROOST_PP_IS_EMPTY_FUNCTION(...) \
    ROOST_PP_IS_EMPTY_FUNCTION2(__VA_ARGS__) \
/**/
#define ROOST_PP_IS_EMPTY_OPT(...) \
    ROOST_PP_VARIADIC_HAS_OPT_ELEM0(ROOST_PP_IS_EMPTY_FUNCTION(__VA_ARGS__),) \
/**/
# else
#define ROOST_PP_IS_EMPTY(...) \
    ROOST_PP_IS_EMPTY_NO_OPT(__VA_ARGS__) \
/**/
# endif /* defined(__cplusplus) && __cplusplus > 201703L */
#define ROOST_PP_IS_EMPTY_NO_OPT(...) \
    ROOST_PP_DETAIL_IS_EMPTY_IIF \
      ( \
      ROOST_PP_IS_BEGIN_PARENS \
        ( \
        __VA_ARGS__ \
        ) \
      ) \
      ( \
      ROOST_PP_IS_EMPTY_ZERO, \
      ROOST_PP_DETAIL_IS_EMPTY_PROCESS \
      ) \
    (__VA_ARGS__) \
/**/
#define ROOST_PP_IS_EMPTY_ZERO(...) 0
# endif /* ROOST_PP_VARIADICS_MSVC && _MSC_VER <= 1400 */
# endif /* ROOST_PREPROCESSOR_FACILITIES_IS_EMPTY_VARIADIC_HPP */
