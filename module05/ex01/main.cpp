#include "Bureaucrat.hpp"
#include "Form.hpp"

int main ()
{
/*	Bureaucrat b("hamid", 150);
	Bureaucrat c(b);
	c.decreaseGrade();
	std::cout << b<< std::endl;*/
	Form form("Birth certificate", true, 180, 140);
	//std::cout << form.getIsSigned() << std::endl;
	std::cout << form << std::endl;
	return (0);
}
