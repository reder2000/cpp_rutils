#include "fpu_seh.h"


#if defined(HAVE_SET_SE_TRANSLATOR)  // && ! defined(__clang__)
  #include <eh.h>

  #if defined(__clang__)
    #include <windows.h>
    #define EXCEPTION_POINTERS _EXCEPTION_POINTERS
  #endif

  #include <errhandlingapi.h>


namespace nsSExceptionTranslator
{

  static void        SEtransfunc(unsigned int n, EXCEPTION_POINTERS* e);
  static void        set_fp();
  static std::string code_2_msg(EXCEPTION_POINTERS* e);


  static inline bool                    _with_fpu                     = false;
  static inline _se_translator_function _previous_translator_function = nullptr;
  static inline unsigned int            _previous_control_fp;

}  // namespace nsSExceptionTranslator
LONG my_PvectoredExceptionHandler(_EXCEPTION_POINTERS* e)
{
  std__print("Runtime problem {}, exiting with code {:#x}", nsSExceptionTranslator::code_2_msg(e),
             e->ExceptionRecord->ExceptionCode);
  exit(e->ExceptionRecord->ExceptionCode);
  return EXCEPTION_EXECUTE_HANDLER;
}

void nsSExceptionTranslator::set_fp()
{
  _previous_control_fp = 0;
  _controlfp_s(&_previous_control_fp, 0, 0);
  unsigned int current_word = 0;
  _controlfp_s(&current_word, 0, _MCW_EM);
}

void nsSExceptionTranslator::SEtransfunc(unsigned int n, EXCEPTION_POINTERS* e)
{
  if (_with_fpu)
  {
    _fpreset();
    _clearfp();
    unsigned int current_word = 0;
    _controlfp_s(&current_word, 0, _MCW_EM);
  }
  MREQUIRE(n == e->ExceptionRecord->ExceptionCode, "code and exception code are different");

  MFAIL("STRUCTURED EXCEPTION {} at adress {}\n", code_2_msg(e),
        static_cast<void*>(e->ExceptionRecord->ExceptionAddress));
}


std::string nsSExceptionTranslator::code_2_msg(EXCEPTION_POINTERS* e)
{
  auto n = e->ExceptionRecord->ExceptionCode;
  switch (n)
  {
    case EXCEPTION_FLT_DIVIDE_BY_ZERO:
      return "Float/0";
    case EXCEPTION_INT_DIVIDE_BY_ZERO:
      return "Integer/0";
    case EXCEPTION_FLT_OVERFLOW:
      return "Float OVERflow";
    case EXCEPTION_FLT_UNDERFLOW:
      return "Float UNDERflow";
    case STATUS_FLOAT_INVALID_OPERATION:
      return "Float INVALID_OPERATION";
    case EXCEPTION_ACCESS_VIOLATION:
    {
      if (e->ExceptionRecord->ExceptionFlags == EXCEPTION_NONCONTINUABLE)
      {
        std__print("EXCEPTION_ACCESS_VIOLATION EXCEPTION_NONCONTINUABLE aborting");
        abort();
      }
      std::string res = "ACCESS_VIOLATION ";
      if (e->ExceptionRecord->ExceptionInformation[0] == 8)
        res += "CALLING FUNCTION AT ADDRESS ";
      else if (e->ExceptionRecord->ExceptionInformation[0] == 0)
        res += "CANNOT READ ADDRESS ";
      else
        res += "CANNOT WRITE ADDRESS ";
      return std__format("{} {}", res, reinterpret_cast<void*>(e->ExceptionRecord->ExceptionInformation[1]));
    }
    default:
      return "UNKNOWN !!!";
  }
}



SExceptionTranslator::SExceptionTranslator(bool with_fpu)
{
  using namespace nsSExceptionTranslator;
  _with_fpu = with_fpu;
  if (_with_fpu)
  {
    set_fp();
  }
  if (_previous_translator_function == nullptr)
  {
  #if ! defined(__clang__)
    _previous_translator_function = _set_se_translator(SEtransfunc);
    if (_previous_translator_function == nullptr) _previous_translator_function = SEtransfunc;
  #else
    AddVectoredContinueHandler(1, my_PvectoredExceptionHandler);
  #endif
  }
}

SExceptionTranslator::~SExceptionTranslator()
{
  using namespace nsSExceptionTranslator;
  if (_with_fpu)
  {
    unsigned int dontcare;
    _fpreset();
    _clearfp();
    _controlfp_s(&dontcare, _previous_control_fp, (_MCW_EM | _MCW_DN));
  }
}



#else

//inline long _my_gnu_exception_handler(EXCEPTION_POINTERS* exception_data)
//{
//  void (*old_handler)(int);
//  long action    = EXCEPTION_CONTINUE_SEARCH;
//  int  reset_fpu = 0;
//  switch (exception_data->ExceptionRecord->ExceptionCode)
//  {
//    case EXCEPTION_ACCESS_VIOLATION:
//      /* test if the user has set SIGSEGV */
//      old_handler = signal(SIGSEGV, SIG_DFL);
//      if (old_handler == SIG_IGN)
//      {
//        /* this is undefined if the signal was raised by anything other than raise (). */
//        signal(SIGSEGV, SIG_IGN);
//        action = EXCEPTION_CONTINUE_EXECUTION;
//      }
//      else if (old_handler != SIG_DFL)
//      {
//        /* This means 'old' is a user defined function. Call it */
//        (*old_handler)(SIGSEGV);
//        action = EXCEPTION_CONTINUE_EXECUTION;
//      }
//      else if (old_handler == SIG_ERR)
//      {
//      }
//      else
//      {
//        //char buf[250]; itoa(old_handler,buf);
//      }
//      break;
//    case EXCEPTION_FLT_INVALID_OPERATION:
//    case EXCEPTION_FLT_DIVIDE_BY_ZERO:
//    case EXCEPTION_FLT_DENORMAL_OPERAND:
//    case EXCEPTION_FLT_OVERFLOW:
//    case EXCEPTION_FLT_UNDERFLOW:
//    case EXCEPTION_FLT_INEXACT_RESULT:
//      reset_fpu = 1;
//      /* fall through. */
//    case EXCEPTION_INT_DIVIDE_BY_ZERO:
//      /* test if the user has set SIGFPE */
//      old_handler = signal(SIGFPE, SIG_DFL);
//      if (old_handler == SIG_IGN)
//      {
//        signal(SIGFPE, SIG_IGN);
//        if (reset_fpu)
//        {
//          _fpreset();
//        }
//        action = EXCEPTION_CONTINUE_EXECUTION;
//      }
//      else if (old_handler != SIG_DFL)
//      {
//        /* This means 'old' is a user defined function. Call it */
//        (*old_handler)(SIGFPE);
//        action = EXCEPTION_CONTINUE_EXECUTION;
//      }
//      break;
//    default:
//      break;
//  }
//  return action;
//}

  #include <csignal>

  #if ! defined(linux)
//  #include <cfenv>
//
//inline int feenableexcept(unsigned int excepts)
//{
//  static fenv_t fenv;
//  unsigned int  new_excepts = excepts & FE_ALL_EXCEPT;
//  // previous masks
//  unsigned int old_excepts;
//
//  if (fegetenv(&fenv))
//  {
//    return -1;
//  }
//  old_excepts = fenv.__control & FE_ALL_EXCEPT;
//
//  // unmask
//  fenv.__control &= ~new_excepts;
//  fenv.__mxcsr &= ~(new_excepts << 7);
//
//  return fesetenv(&fenv) ? -1 : old_excepts;
//}

void fpe_handler(int i)
{
  std__print("received signal {}\n", i);
  _fpreset();
  _clearfp();
  signal(SIGFPE, fpe_handler);
  throw std::runtime_error("SIGFPE");
}

struct SExceptionTranslator
{
  SExceptionTranslator(bool with_fpu);
  ~SExceptionTranslator();

  static inline unsigned int _previous_control_fp;
};

SExceptionTranslator::SExceptionTranslator(bool with_fpu)
{
  if (with_fpu)
  {
    _previous_control_fp = 0;
    _controlfp_s(&_previous_control_fp, 0, 0);
    unsigned int current_word = 0;
    _controlfp_s(&current_word, 0, _MCW_EM);
    signal(SIGFPE, fpe_handler);
  }
}

SExceptionTranslator::~SExceptionTranslator() {}

//inline
//void fphandler( int  ,  int )
//{
//  /* Initialize floating-point package. */
//  _fpreset();
//  _clearfp();
//  /* Restore calling environment and jump back to setjmp. Return
//   * -1 so that setjmp will return false for conditional test.
//   */
//  longjmp( mark(), -1 );
//}
//
//inline
//void SetFPUException ( int ON )
//{
//  #if ! defined(__linux) && ! defined(__CYGWIN__)
//  static unsigned int previous_fp_=0;
//  typedef void (*SignalHandlerPointer)(int);
//  static SignalHandlerPointer previousHandler;
//  if (ON) {
//    int jmpret;
//    previous_fp_ = _control87( FPUcfp , _MCW_EM );
//    previousHandler = signal( SIGFPE, (normalfphandler) fphandler );
//    if(  previousHandler == SIG_ERR )   {
//      fprintf( stderr, "Couldn't set SIGFPE\n" );  abort();   }
//
//    jmpret = setjmp( mark() );
//    if( jmpret != 0 )   {
//      fpcheck();   } }
//  else
//    {
//      signal( SIGFPE,previousHandler) ;
//      _clearfp();
//      _control87( FPUcfp ,0xffff); }


#if ! defined(__clang__)

TEST(cpp_rutils,fpu_seh)
//int maine()
{
  SExceptionTranslator set(true);
  auto                 h = []()
  {
    double a   = -1.;
    auto   res = log(a);
    //double res = std::numeric_limits<double>::max();
    res *= res;
    return res;
  };
  auto g = []()
  {
    double a = 0.;
    return 1. / a;
  };
  EXPECT_ANY_THROW(h());
  EXPECT_ANY_THROW(g());
  auto f = []()
  {
    void (*fun)() = nullptr;
    fun();
    double a = 0.;
    return 1. / a;
  };
  EXPECT_ANY_THROW(f());
  auto i = []()
  {
    int* i = reinterpret_cast<int*>(14);
    *i     = 14;
  };
  EXPECT_ANY_THROW(i());
  auto j = []() { int i = *reinterpret_cast<int*>(14); };
  EXPECT_ANY_THROW(j());
  auto tt = [](auto&& fun)
  {
    try
    {
      fun();
    }
    catch (std::exception& e)
    {
      std__print("tested! {}\n", e.what());
    }
  };
  tt(f);
  tt(g);
  tt(h);
  tt(i);
  tt(j);
}

#else

int filterException(int /*code*/, PEXCEPTION_POINTERS ex)
{
  fmt::print("Filtering {}\n", SExceptionTranslator::code_2_msg(ex));
  return EXCEPTION_EXECUTE_HANDLER;
}

TEST(cpp_rutils,fpu_seh_clang)
{
  SExceptionTranslator::set_fp();
  auto h = []()
  {
    double a   = -1.;
    auto   res = log(a);
    res *= res;
    return res;
  };
  __try
  {
    h();
  }
  __except (filterException(GetExceptionCode(), GetExceptionInformation()))
  {
    std::cout << "caught" << std::endl;
  }
}
#endif 

#endif

#endif