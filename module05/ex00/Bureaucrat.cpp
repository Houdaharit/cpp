#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	std::cout << "Default constructor called!" << std::endl;
	this->name = "";
}

Bureaucrat::Bureaucrat(const Bureaucrat& bureaucrat)
{
	std::cout << "Copy constructor called!" << std::endl;
	this->name = bureaucrat.name;
	this->grade = bureaucrat.grade;
}

Bureaucrat& Bureaucrat::operator = (co)
