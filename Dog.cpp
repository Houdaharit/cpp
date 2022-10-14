#include "Dog.hpp"

Dog::Dog() : type("dog")
{
	std::cout << "Dog constructor called!" << std::endl;
}

Dog::Dog(const std::string& type)
{
	std::cout << "Dog constructor called!" << std::endl;
	this->type = type;
}

Dog::Dog(Dog& dog)
{
	std::cout << "Dog constructor called!" << std::endl;
	type = dog.type;
}

Dog& Dog::operator = (const Dog& dog)
{
}
