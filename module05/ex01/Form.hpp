#ifndef FORM_HPP
#define FORM_HPP
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	const std::string name;
	bool is_signed;
	const int sign_grade;
	const int exec_grade;
	class GradeTooLowException : public std::exception
	{
		virtual const char* what() const throw();
	}too_low;
	class GradeTooHighException : public std::exception
	{
		virtual const char* what() const throw();
	} too_high;
	public:
	Form();
	Form(const Form&);
	Form(const std::string&, int, int);
	Form& operator = (const Form&);
	~Form();
	std::string getName(void) const;
	bool getIsSigned(void) const;
	int getSignGrade(void) const;
	int getExecGrade(void) const;
	void beSigned(const Bureaucrat&);
};

std::ostream& operator << (std::ostream &os, const Form& form);
#endif
