#ifndef FORM_HPP
#define FORM_HPP
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	protected:
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
	virtual ~Form();
	std::string getName(void) const;
	bool getIsSigned(void) const;
	int getSignGrade(void) const;
	int getExecGrade(void) const;
	void beSigned(const Bureaucrat&);
	virtual void execute(Bureaucrat const&) const = 0;
};

std::ostream& operator << (std::ostream &os, const Form& form);
#endif
