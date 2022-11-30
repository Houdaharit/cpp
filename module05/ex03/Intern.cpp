#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern default constructor called!" << std::endl;
}

Form* Intern::RobotMaker(const std::string& target)
{
	return new RobotomyRequestForm(target);
}

Form* Intern::ShrubberyMaker(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}

Form* Intern::PardonMaker(const std::string& target)
{
	return new PresidentialPardonForm(target);
}

Form* Intern::makeForm(const std::string& form_name, const std::string& target)
{
	Form *form;
	const char *str[3] = {"robotomy request", "shrubbery creation", "presidential pardon"};
	Form* (Intern::*forms[3])(const std::string& target) = {&Intern::RobotMaker, &Intern::ShrubberyMaker, &Intern::PardonMaker};

	for (int i = 0; i < 3; i++)
	{
		if (str[i] == form_name)
		{
			form = (this->*forms[i])(target);
			std::cout << "Intern creates " << form->getName() << std::endl;
			return (form);
		}
	}
	throw invalid_form_request;
	return NULL;
} 

const char* Intern::InvalidFormRequestException::what() const throw()
{
	return "Invalid form request!";
}

Intern::~Intern()
{
	std::cout << "Intern destructor called!" << std::endl;
}


