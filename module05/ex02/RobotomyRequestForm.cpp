#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string&) : Form("RobotomyRequestForm", 72, 45)
{
	std::cout << "RobotomyRequestForm constructor called!" << std::endl;
	this->target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& r) : Form("RobotomyRequestForm", 72, 45)
{
	std::cout << "RobotomyRequestForm copy constructor called!" << std::endl;
	this->target = target;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& r)
{
	if (this != &r)
		this->target = r.target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called!" << std::endl;
}
