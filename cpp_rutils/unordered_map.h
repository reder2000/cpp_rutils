#pragma once 

// shorten std::unordered_map to um

#include <functional>
#include <stdexcept>
#include <unordered_map>
#include <fmt/format.h>
#include "name_short.h"

template <class _Kty, class _Ty, class _Hasher = std::hash<_Kty>, class _Keyeq = std::equal_to<_Kty>>
using um = std::unordered_map<_Kty, _Ty, _Hasher, _Keyeq>;


template <class _Kty, class _Ty, class _Hasher = std::hash<_Kty>, class _Keyeq = std::equal_to<_Kty>>
struct um_p : public std::unordered_map<_Kty, _Ty, _Hasher, _Keyeq> {
	using std::unordered_map<_Kty, _Ty, _Hasher, _Keyeq>::unordered_map;

	const _Ty& at(const _Kty& key) const
	{
		auto w = this->find(key);
		if (w != this->end())
			return w->second;
		throw std::out_of_range(fmt::format("({}) {} not found in map", type_name_short<_Kty>(), key));
	}
};

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

// not good enough solution to default dict
//template <class _Kty, class _Ty, class _CreationFn, class _Hasher = std::hash<_Kty>, class _Keyeq = std::equal_to<_Kty>>
//struct default_dict : public std::unordered_map<_Kty, _Ty, _Hasher, _Keyeq>
//{
//	default_dict(_CreationFn&& creation_fn) : _creation_fn(creation_fn) {}
//
//	_Ty& operator[](_Kty&& key) {
//		auto w = this->find(key);
//		if (w != this->end())
//			return w->second;
//		auto r = this->emplace(key, _creation_fn(*this));
//		return r.first->second;
//	}
//
//	_CreationFn _creation_fn;
//};
//
//template <class _Kty, class _Ty, class _Hasher = std::hash<_Kty>, class _Keyeq = std::equal_to<_Kty>>
//struct make_default_dict
//{
//	template <class _CreationFn>
//	static constexpr 	default_dict<_Kty, _Ty, _CreationFn, _Hasher, _Keyeq> make(_CreationFn&& creation_fn)
//	{
//		return default_dict<_Kty, _Ty, _CreationFn, _Hasher, _Keyeq>(std::forward<_CreationFn>(creation_fn));
//	}
//};

template <class _Kty, class _Ty, class _Hasher = std::hash<_Kty>, class _Keyeq = std::equal_to<_Kty>>
struct default_dict : public std::unordered_map<_Kty, _Ty, _Hasher, _Keyeq>
{
	using unordered_map_type = std::unordered_map<_Kty, _Ty, _Hasher, _Keyeq>;
	using creation_function_type = std::function<_Ty(const unordered_map_type&)>;

	default_dict(creation_function_type&& creation_fn) : _creation_fn(creation_fn) {}

	_Ty& operator[](_Kty&& key) {
		auto w = this->find(key);
		if (w != this->end())
			return w->second;
		auto r = this->emplace(key, _creation_fn(*this));
		return r.first->second;
	}

	creation_function_type _creation_fn;
};
