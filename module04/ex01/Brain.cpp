#include "Brain.hpp"

Brain::Brain()
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "";
	std::cout << "Brain constructor is called!" << std::endl;
}

Brain::Brain(const std::string ideas[])
{
	std::cout << "Brain constructor is called!" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = ideas[i];
}

Brain::Brain(const Brain& brain)
{
	std::cout << "Brain constructor is called!" << std::endl;
	if (this != &brain)
	{
		for(int i = 0; i < 100; i++)
			ideas[i] = brain.ideas[i];
	}
}

Brain& Brain::operator = (const Brain& brain)
{
	if (this != &brain)
	{
		for(int i = 0; i < 100; i++)
			ideas[i] = brain.ideas[i];
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destructor is called!" << std::endl;
}
