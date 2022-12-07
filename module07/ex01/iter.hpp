#ifndef ITER_HPP
#define ITER_HPP
#include <iostream>
#include <cstdlib>

template <typename T>
void iter(T array[], int length, void(*fct)(T&))
{
	for (int i = 0; i < length; i++)
		(*fct)(array[i]);
}
#endif
