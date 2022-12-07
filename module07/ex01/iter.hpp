#ifndef ITER_HPP
#define ITER_HPP
#include <iostream>
#include <cstdlib>

template <typename T>
void iter(T array[], size_t length, void(*fct)(T&))
{
	for (size_t i = 0; i < length; i++)
		(*fct)(array[i]);
}
#endif
