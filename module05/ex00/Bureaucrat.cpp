#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name(""), GradeTooHighException(1), GradeTooLowException(150)
{
	std::cout << "Default constructor called!" << std::endl;
	this->grade = 150;
}

Bureaucrat::Bureaucrat(const Bureaucrat& bureaucrat) : name(bureaucrat.name)
{
	std::cout << "Copy constructor called!" << std::endl;
	this->grade = bureaucrat.grade;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name)
{
	try
	{
		if (grade < 1)
			throw GradeTooHighException;
		else if (grade > 150)
			throw GradeTooLowException;
		else this->grade = grade;
	}
	catch (...)
	{
	}
}

Bureaucrat& Bureaucrat::operator = (const Bureaucrat& bureaucrat)
{
	if (this != &bureaucrat)
		this->grade = bureaucrat.grade;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor called!" << std::endl;
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
	os << bureaucrat.name << ", bureaucrat grade " << bureaucrat.grade;
	return (os);
}

void Bureaucrat::increaseGrade()
{
	if (this->grade < 150)
		this->grade += 1;
}

void Bureaucrat::decreaseGrade()
{
	if (this->grade > 1)
		this->grade -= 1;
}
