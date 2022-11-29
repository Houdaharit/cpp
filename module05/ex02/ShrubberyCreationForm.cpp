#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : Form("ShrubberyCreationForm", 145, 137)
{
	std::cout << "ShrubberyCreationForm default constructor called!" << std::endl;
	this->target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& s)
{
	std::cout << "ShrubberyCreationForm copy constructor called!" << std::endl;
	this->target = s.target;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& s)
{
	if (this != &s)
		this->target = s.target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called!" << std::endl;
}

std::string ShrubberyCreationForm::getTarget() const
{
	return (this->target);
}

void ShrubberyCreationForm::execute(Bureaucrat const& b) const
{
	std::fstream file;
	std::string file_name(target + "_shrubbery");

	file.open(file_name);
	if (!file)
		std::cerr << "file can't be opened!" << std::endl;
}
