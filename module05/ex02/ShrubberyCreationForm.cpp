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

void ShrubberyCreationForm::asciiTree() const
{
	std::ofstream file;
	char str[] = "target_shrubbery";

	//file.open(this->target + "_shrubbery");
	file.open(str);
	if (!file)
		std::cerr << "file can't be opened!" << std::endl;

	file << "                       *                               " << std::endl;
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

void ShrubberyCreationForm::execute(Bureaucrat const& b) const 
{
	if (b.getGrade() >= this->exec_grade)
		throw Form::too_low;
	if (!is_signed)
		throw Form::not_signed;
	this->asciiTree();
}
