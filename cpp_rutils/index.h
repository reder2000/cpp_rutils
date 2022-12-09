#pragma once
#include <tuple>

// python-like index
// return std::string::npos if not found

template <typename Ctn, typename V>
size_t index(const Ctn& ctn, const V& val)
{
	for (auto&& [i, res] = std::tuple{ ctn.begin(), (size_t)0 }; i != ctn.end(); ++i, ++res)
		if (*i == val)
			return res;
	return std::string::npos;
}

template <typename Ctn, typename Cdn>
size_t index_if(const Ctn& ctn, Cdn cdn)
{
        for (auto&& [i, res] = std::tuple{ctn.begin(), (size_t)0}; i != ctn.end(); ++i, ++res)
                if (cdn(*i)) return res;
        return std::string::npos;
}
