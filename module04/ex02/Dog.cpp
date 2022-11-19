#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog default constructor called!" << std::endl;
	type = "dog";
	brain = new Brain();
}

Dog::Dog(const Dog& dog)
{
	std::cout << "Dog copy constructor called!" << std::endl;
	type = dog.type;
	this->brain = new Brain;
	for (int i = 0; i < 100; i++)
		this->brain->setIdea(i, this->brain->getIdea(i));
}

Dog& Dog::operator = (const Dog& dog)
{
	if (this != &dog)
	{
		type = dog.type;
		for (int i = 0; i < 100; i++)
			this->brain->setIdea(i, dog.brain->getIdea(i));
	}
	return (*this);
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog destructor is called!" << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << "Dog is barking!" << std::endl;
}

void Dog::setBrain(Brain& brain)
{
	*this->brain = brain;
}
