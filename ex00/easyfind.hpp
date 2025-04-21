#pragma once
#include <algorithm>
template <typename T> typename T::iterator easyfind(T &haystack, int needle) { return std::find(haystack.begin(), haystack.end(), needle); }
template <typename T> typename T::const_iterator easyfind(const T &haystack, int needle) { return std::find(haystack.begin(), haystack.end(), needle); }
