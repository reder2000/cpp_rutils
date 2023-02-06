#pragma once

#include "cpp_rutils_config.h"
#include <cstddef>
#if !HAVE_CXX20_SSIZE_T
using ssize_t = long long;
#endif
