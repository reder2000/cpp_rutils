# /* **************************************************************************
#  *                                                                          *
#  *     (C) Copyright Paul Mensonides 2003.
#  *     (C) Copyright Edward Diener 2014.
#  *     Distributed under the Roost Software License, Version 1.0. (See
#  *     accompanying file LICENSE_1_0.txt or copy at
#  *     http://www.roost.org/LICENSE_1_0.txt)
#  *                                                                          *
#  ************************************************************************** */
#
# /* See http://www.roost.org for most recent version. */
#
# ifndef ROOST_PREPROCESSOR_FACILITIES_IS_EMPTY_HPP
# define ROOST_PREPROCESSOR_FACILITIES_IS_EMPTY_HPP
#
# include <roost/preprocessor/config/config.hpp>
#
# if ROOST_PP_VARIADICS
#
# include <roost/preprocessor/facilities/is_empty_variadic.hpp>
#
# else
#
# if ~ROOST_PP_CONFIG_FLAGS() & ROOST_PP_CONFIG_MSVC() && ~ROOST_PP_CONFIG_FLAGS() & ROOST_PP_CONFIG_MWCC()
# include <roost/preprocessor/tuple/elem.hpp>
# include <roost/preprocessor/facilities/identity.hpp>
# else
# include <roost/preprocessor/cat.hpp>
# include <roost/preprocessor/detail/split.hpp>
# endif
#
# /* ROOST_PP_IS_EMPTY */
#
# if ~ROOST_PP_CONFIG_FLAGS() & ROOST_PP_CONFIG_MSVC() && ~ROOST_PP_CONFIG_FLAGS() & ROOST_PP_CONFIG_MWCC()
#    define ROOST_PP_IS_EMPTY(x) ROOST_PP_IS_EMPTY_I(x ROOST_PP_IS_EMPTY_HELPER)
#    define ROOST_PP_IS_EMPTY_I(contents) ROOST_PP_TUPLE_ELEM(2, 1, (ROOST_PP_IS_EMPTY_DEF_ ## contents()))
#    define ROOST_PP_IS_EMPTY_DEF_ROOST_PP_IS_EMPTY_HELPER 1, ROOST_PP_IDENTITY(1)
#    define ROOST_PP_IS_EMPTY_HELPER() , 0
# else
#    if ROOST_PP_CONFIG_FLAGS() & ROOST_PP_CONFIG_MSVC()
#        define ROOST_PP_IS_EMPTY(x) ROOST_PP_IS_EMPTY_I(ROOST_PP_IS_EMPTY_HELPER x ())
#        define ROOST_PP_IS_EMPTY_I(test) ROOST_PP_IS_EMPTY_II(ROOST_PP_SPLIT(0, ROOST_PP_CAT(ROOST_PP_IS_EMPTY_DEF_, test)))
#        define ROOST_PP_IS_EMPTY_II(id) id
#    else
#        define ROOST_PP_IS_EMPTY(x) ROOST_PP_IS_EMPTY_I((ROOST_PP_IS_EMPTY_HELPER x ()))
#        define ROOST_PP_IS_EMPTY_I(par) ROOST_PP_IS_EMPTY_II ## par
#        define ROOST_PP_IS_EMPTY_II(test) ROOST_PP_SPLIT(0, ROOST_PP_CAT(ROOST_PP_IS_EMPTY_DEF_, test))
#    endif
#    define ROOST_PP_IS_EMPTY_HELPER() 1
#    define ROOST_PP_IS_EMPTY_DEF_1 1, ROOST_PP_NIL
#    define ROOST_PP_IS_EMPTY_DEF_ROOST_PP_IS_EMPTY_HELPER 0, ROOST_PP_NIL
# endif
#
# endif /* ROOST_PP_VARIADICS */
#
# endif /* ROOST_PREPROCESSOR_FACILITIES_IS_EMPTY_HPP */
