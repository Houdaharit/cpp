#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	const Animal *animal = new Cat();
	animal->makeSound();
}
