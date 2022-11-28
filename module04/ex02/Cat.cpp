#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat default constructor is called!" << std::endl;
	this->type = "cat";
	this->brain = new Brain();
}

Cat::Cat(const Cat& cat)
{
	std::cout << "Cat copy constructor is called!" << std::endl;
	type = cat.type;
	this->brain = new Brain;
	for (int i = 0; i < 100; i++)
		this->brain->setIdea(i, cat.brain->getIdea(i));
}

Cat& Cat::operator = (const Cat& cat)
{
	if (this != &cat)
	{
		this->type = cat.type;
		for (int i = 0; i < 100; i++)
			this->brain->setIdea(i, cat.brain->getIdea(i));
	}
	return (*this);
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Cat destructor called!" << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << "Cat is meowing!" << std::endl;
}

void Cat::setBrain(Brain& brain)
{
	*this->brain = brain;
}

