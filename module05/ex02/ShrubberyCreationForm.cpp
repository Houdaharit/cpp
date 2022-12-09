#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", 145, 137)
{
	std::cout << "ShrubberyCreationForm default constructor called!" << std::endl;
	this->target = "";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : Form("ShrubberyCreationForm", 145, 137)
{
	std::cout << "ShrubberyCreationForm constructor called!" << std::endl;
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

void ShrubberyCreationForm::asciiTree() const
{
	std::ofstream file;

	file.open(this->target + "_shrubbery");
	if (!file)
		std::cerr << "file can't be opened!" << std::endl;

	file << "                       *                               " << std::endl;
	file << "                       0                               " << std::endl;
	file << "                      101                              " << std::endl;
	file << "                     01010                             " << std::endl;
	file << "                    1010101                            " << std::endl;
	file << "                   010101010                           " << std::endl;
	file << "                  10101010101                          "<< std::endl;
	file << "                 0101010101010                         " << std::endl;
	file << "                101010101010101                        " << std::endl;	 
	file << "                   010101010                           " << std::endl; 
	file << "                  10101010101                          " << std::endl;
	file << "                 0101010101010                         " << std::endl;
	file << "                101010101010101                        " << std::endl;
	file << "               01010101010101010                       " << std::endl;
	file << "              1010101010101010101                      " << std::endl;
	file << "             010101010101010101010                     " << std::endl;
	file << "            10101010101010101010101                    " << std::endl;
	file << "                   010101010                           " << std::endl;
	file << "                  10101010101                          " << std::endl;
	file << "                 0101010101010                         " << std::endl;
	file << "                101010101010101                        " << std::endl;
	file << "               01010101010101010                       " << std::endl;
	file << "              1010101010101010101                      " << std::endl;
	file << "             010101010101010101010                     " << std::endl;
	file << "            10101010101010101010101                    " << std::endl;
	file << "           0101010101010101010101010                   " << std::endl;
	file << "          101010101010101010101010101                  " << std::endl;
	file << "         01010101010101010101010101010                 " << std::endl;
	file << "        1010101010101010101010101010101                " << std::endl;
	file << "                   010101010                           " << std::endl;
	file << "                  10101010101                          " << std::endl;
	file << "                 0101010101010                         " << std::endl;
	file << "                101010101010101                        " << std::endl;
	file << "               01010101010101010                       " << std::endl;
	file << "              1010101010101010101                      " << std::endl;
	file << "             010101010101010101010                     " << std::endl;
	file << "            10101010101010101010101                    " << std::endl;
	file << "           0101010101010101010101010                   " << std::endl;
	file << "          101010101010101010101010101                  " << std::endl;
	file << "         01010101010101010101010101010                 " << std::endl;
	file << "        1010101010101010101010101010101                " << std::endl;
	file << "       010101010101010101010101010101010               " << std::endl;
	file << "      10101010101010101010101010101010101              " << std::endl;
	file << "     0101010101010101010101010101010101010             " << std::endl;
	file << "                     01010                             " << std::endl;
	file << "                     01010                             " << std::endl;
	file << "                     01010                             " << std::endl;
	file << "                     01010                             " << std::endl;
	file.close();
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const 
{
	if (executor.getGrade() >= this->exec_grade)
		throw Form::too_low;
	if (!this->is_signed)
		throw Form::not_signed;
	this->asciiTree();
}
