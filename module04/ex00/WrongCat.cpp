#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat default constructor is called!" << std::endl;
	type = "wrongcat";
}

WrongCat::WrongCat(const WrongCat& wrongcat)
{
	std::cout << "WrongCat copy constructor is called!" << std::endl;
	type = wrongcat.type;
}

 WrongCat& WrongCat::operator = (const WrongCat& wrongcat)
{
	if (this != &wrongcat)
		type = wrongcat.type;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called!" << std::endl;
}

void	WrongCat::makeSound(void) const
{
	std::cout << "WrongCat is meowing!" << std::endl;
}
