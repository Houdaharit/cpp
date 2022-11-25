#include "Bureaucrat.hpp"

int main ()
{
	Bureaucrat b("hamid", 200);
	Bureaucrat c(b);
	c.increaseGrade();
	std::cout << c.getGrade( << std::endl;
	return (0);
}
