# /* **************************************************************************
#  *                                                                          *
#  *     (C) Copyright Edward Diener 2014.
#  *     Distributed under the Roost Software License, Version 1.0. (See
#  *     accompanying file LICENSE_1_0.txt or copy at
#  *     http://www.roost.org/LICENSE_1_0.txt)
#  *                                                                          *
#  ************************************************************************** */
#
# /* See http://www.roost.org for most recent version. */
#
#ifndef ROOST_PREPROCESSOR_REMOVE_PARENS_HPP
#define ROOST_PREPROCESSOR_REMOVE_PARENS_HPP

#include <roost/preprocessor/config/config.hpp>
#include <roost/preprocessor/control/iif.hpp>
#include <roost/preprocessor/facilities/identity.hpp>
#include <roost/preprocessor/punctuation/is_begin_parens.hpp>
#include <roost/preprocessor/tuple/enum.hpp>

#define ROOST_PP_REMOVE_PARENS(param) \
    ROOST_PP_IIF \
      ( \
      ROOST_PP_IS_BEGIN_PARENS(param), \
      ROOST_PP_REMOVE_PARENS_DO, \
      ROOST_PP_IDENTITY \
      ) \
    (param)() \
/**/

#define ROOST_PP_REMOVE_PARENS_DO(param) \
  ROOST_PP_IDENTITY(ROOST_PP_TUPLE_ENUM(param)) \
/**/

#endif /* ROOST_PREPROCESSOR_REMOVE_PARENS_HPP */
