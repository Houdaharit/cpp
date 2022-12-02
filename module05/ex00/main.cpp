#include "Bureaucrat.hpp"

int main ()
{
	try
	{
		Bureaucrat d;
		Bureaucrat b("hamid", 200);
		Bureaucrat c(b);
		c.increaseGrade();
		std::cout << c.getGrade() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}
	return (0);
}
