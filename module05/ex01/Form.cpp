#include "Form.hpp"

Form::Form()
{
	std::cout << "Form constructor called!" << std::endl;
	this->name = "";
	this->is_signed = FALSE;
	this->sign = 150;
	this->exec = 150;
}

Form::Form(const Form& form)
{
	std::cout << "Form copy constructor called!" << std::endl;
}

