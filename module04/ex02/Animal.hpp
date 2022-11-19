#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>
# include <string>

class Animal
{
	protected:
		std::string	type;
	public:
		Animal();
		Animal(const Animal&);
		Animal& operator = (const Animal&);
		virtual	~Animal();
		virtual void makeSound(void) const = 0;
		std::string getType(void) const;
};
#endif
