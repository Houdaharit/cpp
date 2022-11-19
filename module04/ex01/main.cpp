#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	/*const Animal* j = new Dog();
	  const Animal* i = new Cat();

	  i->getType();
	  j->getType();*/
	Animal *animal[4];
	for(int i = 0; i < 2; i++)
		animal[i] = new Cat();
	for (int i = 2; i < 4; i++)
		animal[i] = new Dog();
	for (int i = 0; i < 4; i++)
		delete animal[i];
	/*delete j;//should not create a leak 
	  delete i;*/
	return 0;
}
