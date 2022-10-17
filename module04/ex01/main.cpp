#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	Cat cat;
	const Animal *animal = &cat;
	animal->makeSound();
	return 0;
}
