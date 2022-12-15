#ifndef EASYFIND_TPP
#define EASYFIND_TPP
#include "easyfind.hpp"

template <typename T>
typename T::iterator easyfind(T& container, int value)
{
	typename T::iterator iter;

	iter = std::find(container.begin(), container.end(), value);
	if (iter == container.end())
		throw NoElementException();
	return (iter);
}

#endif
