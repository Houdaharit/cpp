#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat constructor is called!" << std::endl;
	type = "cat";
	brain = new Brain();
}

Cat::Cat(const std::string& type)
{
	std::cout << "Cat constructor is called!" << std::endl;
	this->type = type;
	brain = new Brain();
}

Cat::Cat(const Cat& cat)
{
	std::cout << "Cat constructor is called!" << std::endl;
	type = cat.type;
	brain = cat.brain;
}

Cat& Cat::operator = (const Cat& cat)
{
	if (this != &cat)
	{
		type = cat.type;
		brain = cat.brain;
	}
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "Cat is meowing!" << std::endl;
}
