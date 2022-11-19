#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal default constructor called!" << std::endl;
	type = "";
}

Animal::Animal(const Animal& animal)
{
	std::cout << "Animal copy constructor called!" << std::endl;
	type = animal.type;
}

Animal& Animal::operator = (const Animal& animal)
{
	if (this != &animal)
		type = animal.type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destructor called!" << std::endl;
}

void	Animal::makeSound(void) const
{
	std::cout << "Animal is making a sound!" << std::endl;
}

std::string Animal::getType(void) const
{
	return (type);
}
