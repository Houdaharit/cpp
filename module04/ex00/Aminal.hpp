#ifndef ANIMAL_HPP
# define ANIMAL_HPP

class Animal
{
	protected:
		std::string	type;
	public:
		Animal();
		Animal(const std::string&);
		Animal(Animal&);
		Animal& operator = (const Animal&);
		~Animal();
		void makeSound(void);
};
#endif
