#include "Base.hpp"
#include "B.hpp"
#include "A.hpp"
#include "C.hpp"

Base* generate(void)
{
	srand(time(NULL));
	int random = rand() % 3;
	if (random == 1)
		return new A();
	if (random == 2)
		return new B();
	return new C();
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "The type of the object pointed to by p is: A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "The type of the object pointed to by p is: B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "The type of the object pointed to by p is: C" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A& a_ref = dynamic_cast<A&>(p);
		std::cout << "The type of the object pointed to by p is: A" << std::endl;
		(void)a_ref;
		return;
	}
	catch(std::exception& e)
	{
		try
		{
			B& b_ref = dynamic_cast<B&>(p);
			std::cout << "The type of the object pointed to by p is: B" << std::endl;
			(void)b_ref;
			return;
		}
		catch(std::exception& e)
		{
			try
			{
				C& c_ref = dynamic_cast<C&>(p);
				std::cout << "The type of the object pointed to by p is: C" << std::endl;
				(void)c_ref;
			}
			catch(std::exception& e)
			{
				std::cout << e.what() << std::endl;
			}
		}
	}
}
