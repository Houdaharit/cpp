#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include "Form.hpp"

class PresidentialPardonForm : public Form
{
	std::string target;
	public:
	PresidentialPardonForm(const std::string);
	PresidentialPardonForm(const PresidentialPardonForm&);
	PresidentialPardonForm& operator=(const PresidentialPardonForm&);
	~PresidentialPardonForm();
	void execute(Bureaucrat const&) const;
	void pardon() const;
};

#endif
