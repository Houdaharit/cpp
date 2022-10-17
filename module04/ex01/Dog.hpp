#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	Brain *brain;
	public:
		Dog();
		Dog(const std::string&);
		Dog(const Dog&);
		Dog& operator = (const Dog&);
		~Dog();
		void makeSound() const;
};
#endif
