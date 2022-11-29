#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : Form("RobotomyRequestForm", 72, 45)
{
	std::cout << "RobotomyRequestForm constructor called!" << std::endl;
	this->target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& r) : Form("RobotomyRequestForm", 72, 45)
{
	std::cout << "RobotomyRequestForm copy constructor called!" << std::endl;
	this->target = r.target;
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

void RobotomyRequestForm::robotize() const
{
	std::cout << this->target << " has been robotized!" << std::endl; 
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	if (executor.getGrade() >= this->exec_grade)
		throw too_low;
	if (!this->is_signed)
		throw not_signed;
	this->robotize();
}
