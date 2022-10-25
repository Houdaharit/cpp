#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("")
{
	std::cout << "Default constructor called!" << std::endl;
	this->grade = 150;
}

Bureaucrat::Bureaucrat(const Bureaucrat& bureaucrat) : name(bureaucrat.name)
{
	std::cout << "Copy constructor called!" << std::endl;
	this->grade = bureaucrat.grade;
}

Bureaucrat::Bureaucrat(const std::string& name, int& grade) : name(name)
{
	this->grade = grade;
}

Bureaucrat& Bureaucrat::operator = (const Bureaucrat& bureaucrat)
{
	if (this != &bureaucrat)
		this->grade = bureaucrat.grade;
	return (*this);
}

std::string Bureaucrat::getName(void) const
{
	return (this->name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->grade);
}

std::ostream& operator << (std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.name << " ,bureaucrat grade " << bureaucrat.grade;
	return (os);
}

void Bureaucrat::increaseGrade() const
{

}
