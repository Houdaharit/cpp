#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	/*const Animal* j = new Dog();
	  const Animal* i = new Cat();

	  i->getType();
	  j->getType();*/
	Animal *animal[10];
	for(int i = 0; i < 5; i++)
		animal[i] = new Cat();
	for (int i = 0; i < 5; i++)
		animal[i] = new Dog();
	/*delete j;//should not create a leak 
	  delete i;*/
	for (int i = 0; i < 10; i++)
		delete animal[i];
	return 0;
}
