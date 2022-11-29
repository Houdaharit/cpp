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
		ShrubberyCreationForm form("Birth certificate");
		form.beSigned(bureaucrat);
		bureaucrat.executeForm(form);
		RobotomyRequestForm form2("hehe");
		form2.beSigned(bureaucrat);
		bureaucrat.executeForm(form2);
		RobotomyRequestForm form3 = form2;
		std::cout << form << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}
	return (0);
}
