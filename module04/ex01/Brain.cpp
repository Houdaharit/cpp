#include "Brain.hpp"

Brain::Brain()
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "";
	std::cout << "Brain constructor is called!" << std::endl;
}

Brain::Brain(const Brain& brain)
{
	std::cout << "Brain copy constructor is called!" << std::endl;
	if (this != &brain)
	{
		for(int i = 0; i < 100; i++)
			this->ideas[i] = brain.ideas[i];
	}
}

Brain& Brain::operator = (const Brain& brain)
{
	if (this != &brain)
	{
		for(int i = 0; i < 100; i++)
			this->ideas[i] = brain.ideas[i];
	}
	return (*this);
}

void Brain::setIdea(int index, const std::string& idea)
{
	this->ideas[index] = idea;
}

std::string Brain::getIdea(int index) const
{
	return this->ideas[index];
}

Brain::~Brain()
{
	std::cout << "Brain destructor is called!" << std::endl;
}
