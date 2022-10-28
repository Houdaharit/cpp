#ifndef FORM_HPP
#define FORM_HPP
#include "Bureaucrat.hpp"

class Form
{
	const std::string name;
	bool is_signed;
	const int sign;
	const int exec;
	public:
	Form();
	Form(const Form&);
	Form& operator = (const Form&);
	~Form();
	std::string getName(void);
	bool getIsigned(void);
	void beSigned(const Bureaucrat&);
	class GradeTooLowException : public std::exception
	{
		vitrual const char* what() const throw();
	}too_low;
	class GradeTooHighException : public std::exception
	{
		vitrual const char* what() const throw();
	} too_high;
	friend std::ostream& operator << (std::ostream &os, const Form* form);
};

#endif
