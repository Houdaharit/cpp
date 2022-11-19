#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal default constructor called!" << std::endl;
	this->type = "";
}

Animal::Animal(const Animal& animal)
{
	std::cout << "Animal copy constructor called!" << std::endl;
	this->type = animal.type;
}

Animal& Animal::operator = (const Animal& animal)
{
	if (this != &animal)
		this->type = animal.type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destructor called!" << std::endl;
}

void	Animal::makeSound(void)
{
	std::cout << "Animal is making a sound!" << std::endl;
}

std::string Animal::getType(void) const
{
	return (this->type);
}
