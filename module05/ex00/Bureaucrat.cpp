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

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name)
{
	try
	{
		if (grade < 1)
			throw too_high;
		else if (grade > 150)
			throw too_low;
		else this->grade = grade;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
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
	try
	{
		if (grade == 1)
			throw too_low;
		else this->grade += 1;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void Bureaucrat::decreaseGrade()
{
	try
	{
		if (grade == 150)
			throw too_low;
		else this->grade += 1;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low!";
}
