#ifndef INTERN_HPP
#define INTERN_HPP
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	class InvalidFormRequestException : public std::exception
	{
		virtual const char* what() const throw();
	}invalid_form_request;

	public:
	Intern();
	~Intern();
	Form* makeForm(const std::string&, const std::string&);
	Form* ShrubberyMaker(const std::string& target);
	Form* PardonMaker(const std::string& target);
	Form* RobotMaker(const std::string& target);
};

#endif
