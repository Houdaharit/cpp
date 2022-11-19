#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat default constructor is called!" << std::endl;
	type = "cat";
}

Cat::Cat(const Cat& cat)
{
	std::cout << "Cat copy constructor is called!" << std::endl;
	type = cat.type;
}

Cat& Cat::operator = (const Cat& cat)
{
	if (this != &cat)
		type = cat.type;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called!" << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << "Cat is meowing!" << std::endl;
}
