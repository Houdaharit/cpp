#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include "Form.hpp"
#include <cstdlib>

class RobotomyRequestForm : public Form
{
	std::string target;
	public:
	RobotomyRequestForm(const std::string&);
	RobotomyRequestForm(const RobotomyRequestForm&);
	RobotomyRequestForm& operator=(const RobotomyRequestForm&);
	~RobotomyRequestForm();
	void execute(Bureaucrat const&) const;
	void robotize() const;
	std::string getTarget() const;
};

#endif
