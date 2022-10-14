#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(const std::string&);
		Dog(Dog&);
		Dog& operator = (const Dog&);
		~Dog();
};
#endif
