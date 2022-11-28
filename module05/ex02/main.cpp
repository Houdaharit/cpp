#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "RobotomyRequestForm.hpp"

int main ()
{
	//Bureaucrat bureaucrat("Hamid", 140);
	RobotomyRequestForm P("hehe");
	RobotomyRequestForm R = P;
	std::cout << R.getSignGrade() << std::endl;
	/*	Form form("Birth certificate", 150, 140);
		form.beSigned(bureaucrat);
		std::cout << form << std::endl;*/
	return (0);
}
