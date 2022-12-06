#include <iostream>
#include "serialization.hpp"

int main()
{
	Data* d = new Data();
	d->value = 10;
	uintptr_t ptr = serialize(d);
	Data* dser = deserialize(ptr);
	std::cout << dser->value << std::endl;


}
