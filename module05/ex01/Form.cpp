#include "Form.hpp"

Form::Form() : name(""), sign_grade(150), exec_grade(150)
{
	std::cout << "Form constructor called!" << std::endl;
	this->is_signed = false;
}

Form::Form(const std::string& name, int sign, int exec) : name(name), sign_grade(sign), exec_grade(exec)
{
	std::cout << "Form constructor is called!" << std::endl;
    try
    {
        if (sign < 1)
            throw too_high;
        else if (sign > 150)
            throw too_low;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
   	try
    {
        if (exec < 1)
            throw too_high;
        else if (exec > 150)
            throw too_low;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
	}
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

int  Form::getSignGrade() const
{
	return (this->sign_grade);
}

int Form::getExecGrade() const
{
	return (this->exec_grade);
}

bool Form::getIsSigned(void) const
{
	return (this->is_signed);
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	try
	{
		if (bureaucrat.getGrade() <= this->sign_grade)
			this->is_signed = true;
		else
			throw too_low;
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

std::ostream& operator << (std::ostream &os, const Form& form)
{
	os << form.getName();
	if (form.getIsSigned())
		os << " is signed! ";
	else
		os << " is not signed! ";
	os << "Sign grade is " << form.getSignGrade();
	os << " and exec grade is " << form.getExecGrade();
	return os;
}

const char* Form::GradeTooHighException::what() const throw()
{
        return "Grade too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
        return "Grade too low!";
}
