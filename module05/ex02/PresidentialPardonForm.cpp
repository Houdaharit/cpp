#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : Form("PresidentialPardonForm", 25, 5)
{	
	std::cout << "PresidentialPardonForm default constructor called!" << std::endl;
	this->target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& p) : Form("PresidentialPardonForm", 25, 5)
{
	std::cout << "PresidentialPardonForm copy constructor called!" << std::endl;
	this->target = target;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& p)
{
	if (this != &p)
		this->target = p.target;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor called!" << std::endl;
}
