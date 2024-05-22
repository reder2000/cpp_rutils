#pragma once

#if ! defined(linux) // FIXME

struct SExceptionTranslator
{
  SExceptionTranslator(bool with_fpu);
  ~SExceptionTranslator();
};

#endif