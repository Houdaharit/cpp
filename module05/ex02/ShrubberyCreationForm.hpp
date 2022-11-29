#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include <iostream>
#include <cstring>
#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
	std::string target;
	public:
	ShrubberyCreationForm(const std::string&);
	ShrubberyCreationForm(const ShrubberyCreationForm&);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm&);
	~ShrubberyCreationForm();
	void execute(Bureaucrat const&) const;
	void asciiTree() const;
	std::string getTarget() const;
};

#endif
