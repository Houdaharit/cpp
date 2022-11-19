#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	Brain *brain;
	public:
	Cat(const Cat&);
	Cat& operator = (const Cat&);
	~Cat();
	void makeSound(void) const;
};
#endif
