#include "Form.hpp"

Form::Form() : name(""), sign_grade(150), exec_grade(150)
{
	std::cout << "Form constructor called!" << std::endl;
	this->is_signed = false;
}

Form::Form(const Form& form) : name(form.name), sign_grade(form.sign_grade), exec_grade(form.exec_grade)
{
	std::cout << "Form copy constructor called!" << std::endl;
	this->is_signed = form.is_signed;	
}

Form& Form::operator = (const Form& form)
{
	if (this != &form)
		this->is_signed = form.is_signed;
	return (*this);
}

Form::~Form()
{
	std::cout << "Form destructor called!" << std::endl;
}

std::string Form::getName(void) const
{
	return (this->name);
}	

int  Form::getSignGrade()
{
	return (this->sign_grade);
}

int Form::getExecGrade()
{
	return (this->exec_grade);
}

bool Form::getIsSigned(void)
{
	return (this->is_signed);
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	try
	{
		if (bureaucrat.getGrade() < 150)
			this->is_signed = true;
		else
			throw too_low;
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

/*std::ostream& operator << (std::ostream &os, const Form& form)
{
}*/
const char* Form::GradeTooHighException::what() const throw()
{
        return "Grade too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
        return "Grade too low!";
}
