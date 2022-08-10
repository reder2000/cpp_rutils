#pragma once 

#include <codecvt>  // codecvt_utf8
#include <locale>   // wstring_convert

// locale-independent to_wstring that actually works, no nonsense
[[nodiscard]] inline std::wstring to_wstrings(const std::string& utf8)
{
  std::wstring_convert<std::codecvt_utf8<wchar_t>> cvt;
  return cvt.from_bytes(utf8);
}

// locale-independent to_string that actually works, no nonsense
[[nodiscard]] inline std::string to_strings(const std::wstring& unicode)
{
  std::wstring_convert<std::codecvt_utf8<wchar_t>> cvt;
  return cvt.to_bytes(unicode);
}
// locale-independent to_string that actually works, no nonsense
[[nodiscard]] inline const std::string & to_strings(const std::string& not_unicode)
{
  return not_unicode;
}

// locale-independent to_string that actually works, no nonsense
[[nodiscard]] inline const std::wstring & to_wstrings(const std::wstring& unicode)
{
  return unicode;
}

