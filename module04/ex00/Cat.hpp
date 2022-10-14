#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(const std::string&);
		Cat(Cat&);
		Cat& operator = (const Cat&);
		~Cat();
		void makeSound(void);
};
#endif
