#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>
class NoElementException : public std::exception
{
	public:
		const char* what() const throw()
		{
			return "No such element in the container!";
		}
};

template <typename T>
typename T::iterator easyfind(T& container, int value);
#include "easyfind.tpp"
#endif
