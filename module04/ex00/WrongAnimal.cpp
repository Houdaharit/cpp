#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal default constructor called!" << std::endl;
	this->type = "";
}

WrongAnimal::WrongAnimal(const WrongAnimal& wronganimal)
{
	std::cout << "WrongAnimal copy constructor called!" << std::endl;
	this->type = wronganimal.type;
}

WrongAnimal& WrongAnimal::operator = (const WrongAnimal& wronganimal)
{
	if (this != &wronganimal)
		this->type = wronganimal.type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called!" << std::endl;
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "WrongAnimal is making a sound!" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
	return (this->type);
}
