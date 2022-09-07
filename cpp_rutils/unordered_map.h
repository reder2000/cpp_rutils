#pragma once 

// shorten std::unordered_map to um

#include <unordered_map>

template <class _Kty, class _Ty, class _Hasher = std::hash<_Kty>, class _Keyeq = std::equal_to<_Kty>>
using um = std::unordered_map<_Kty, _Ty, _Hasher, _Keyeq>;

// unordered map with a callback function
// rather than writing value = map.contains(key) ? map[key] , new_value
// call value = map.find_or_add(key,callback_fn,args_to_fn...)

template <class _Kty, class _Ty, class _Hasher = std::hash<_Kty>, class _Keyeq = std::equal_to<_Kty>>
struct um_cp : public std::unordered_map<_Kty, _Ty, _Hasher, _Keyeq>
{
	using std::unordered_map<_Kty, _Ty, _Hasher, _Keyeq>::unordered_map;

	template <typename  Fn, typename... Args>
	_Ty& find_or_add(const _Kty& key, Fn fn, Args ...args_to_fn);
};

template <class _Kty, class _Ty, class _Hasher, class _Keyeq>
template <typename Fn, typename ... Args>
_Ty& um_cp<_Kty, _Ty, _Hasher, _Keyeq>::find_or_add(const _Kty& key, Fn fn, Args... args_to_fn)
{
	auto w = this->find(key);
	if (w != this->end()) 
		return w->second; 
	auto r = this->emplace(key, fn(args_to_fn...));
	return r.first->second;
}
