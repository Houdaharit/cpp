#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <exception>
#include <string>

class Bureaucrat
{
	const std::string name;
	int grade; 
	public:
	int GradeTooHighException;
	int GradeTooLowException;
	Bureaucrat();
	Bureaucrat(const std::string&, int);
	Bureaucrat(const Bureaucrat&);
	~Bureaucrat();
	Bureaucrat& operator = (const Bureaucrat&);
	std::string getName(void) const;
	int	getGrade(void) const;
	void setName(const std::string&) const;
	void increaseGrade(void);
	void decreaseGrade(void);
	friend std::ostream& operator << (std::ostream &os, const Bureaucrat &bureaucrat);
};

#endif
