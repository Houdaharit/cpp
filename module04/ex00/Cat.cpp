#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat constructor is called!" << std::endl;
	type = "cat";
}

Cat::Cat(const std::string& type)
{
	std::cout << "Cat constructor is called!" << std::endl;
	this->type = type;
}

Cat::Cat(Cat& cat)
{
	std::cout << "Cat constructor is called!" << std::endl;
	type = cat.type;
}

Cat& Cat::operator = (const Cat& cat)
{
	if (this != &cat)
		type = cat.type;
	return (*this);
}

void	Cat::makeSound(void)
{
	std::cout << "Cat is meowing!" << std::endl;
}
