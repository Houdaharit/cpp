#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : Form("PresidentialPardonForm", 25, 5)
{	
	std::cout << "PresidentialPardonForm default constructor called!" << std::endl;
	this->target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& p) : Form("PresidentialPardonForm", 25, 5)
{
	std::cout << "PresidentialPardonForm copy constructor called!" << std::endl;
	this->target = p.target;
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

void PresidentialPardonForm::pardon() const
{
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox!" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
	if (executor.getGrade() > this->exec_grade)
		throw too_low;
	if (!this->is_signed)
		throw not_signed;
	this->pardon();
}
