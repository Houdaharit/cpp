#include "Form.hpp"

Form::Form() : name(""), sign(150), exec(150)
{
	std::cout << "Form constructor called!" << std::endl;
	this->is_signed = false;
}

Form::Form(const Form& form) : name(form.name), sign(form.sign), exec(form.exec)
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
	return (this->sign);
}

int Form::getExecGrade()
{
	return (this->exec);
}

bool Form::getIsSigned(void)
{
	return (this->is_signed);
}

void Form::beSigned(Bureaucrat &bureaucrat)
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
