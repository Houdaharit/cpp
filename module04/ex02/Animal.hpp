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
		Animal(const std::string&);
		Animal(const Animal&);
		Animal& operator = (const Animal&);
		~Animal();
		virtual void makeSound(void) const = 0;
		std::string getType(void) const;
};
#endif
