#include "Dog.hpp"

Dog::Dog()
{
	type = "dog";
	brain = NULL;
	std::cout << "Dog constructor called!" << std::endl;
}

Dog::Dog(const std::string& type)
{
	std::cout << "Dog constructor called!" << std::endl;
	brain = NULL;
	this->type = type;
}

Dog::Dog(const Dog& dog)
{
	std::cout << "Dog constructor called!" << std::endl;
	type = dog.type;
	brain = dog.brain;
}

Dog& Dog::operator = (const Dog& dog)
{
	if (this != &dog)
	{
		brain = dog.brain;
		type = dog.type;
	}
	return (*this);
}

Dog::~Dog()
{
}

void	Dog::makeSound(void) const
{
	std::cout << "Dog is barking!" << std::endl;
}
