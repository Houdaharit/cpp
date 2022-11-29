#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int main ()
{
	try
	{
		Bureaucrat bureaucrat("Hamid", 30);
		ShrubberyCreationForm S("j");
		S.beSigned(bureaucrat);
		bureaucrat.executeForm(S);
			RobotomyRequestForm P("hehe");
			P.beSigned(bureaucrat);
			bureaucrat.executeForm(P);
		/*	RobotomyRequestForm R = P;
			std::cout << R.getSignGrade() << std::endl;
			Form form("Birth certificate", 150, 140);
			form.beSigned(bureaucrat);
			std::cout << form << std::endl;*/
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}
	return (0);
}
