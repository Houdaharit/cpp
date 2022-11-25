#include "Bureaucrat.hpp"

int main ()
{
	Bureaucrat b("hamid", 150);
	Bureaucrat c(b);
	c.decreaseGrade();
	std::cout << b << std::endl;
	return (0);
}
