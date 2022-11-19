#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <iostream>
# include <string>

class WrongAnimal
{
	protected:
		std::string	type;
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal&);
		WrongAnimal& operator = (const WrongAnimal&);
		~WrongAnimal();
		void makeSound(void) const;
		std::string getType(void) const;
};
#endif
