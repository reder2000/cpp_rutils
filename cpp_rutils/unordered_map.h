#pragma once 

// shorten std::unordered_map to um

#include <unordered_map>

template <class _Kty, class _Ty, class _Hasher = std::hash<_Kty>, class _Keyeq = std::equal_to<_Kty>>
using um = std::unordered_map<_Kty, _Ty, _Hasher, _Keyeq>;
