#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern default constructor called!" << std::endl;
}

Form Intern::makeForm(const std::string& form_name, const std::string& target)
{
}

Intern::~Intern()
{
	std::cout << "Intern destructor called!" << std::endl;
}
