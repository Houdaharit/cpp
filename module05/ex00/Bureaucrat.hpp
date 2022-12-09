#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <exception>
#include <string>

class Bureaucrat
{
	const std::string name;
	int grade; 
	class GradeTooHighException : public std::exception
	{
		virtual const char* what() const throw();
	} too_high;
	class GradeTooLowException : public std::exception
	{
		virtual const char* what() const throw();
	} too_low;
	public:
	Bureaucrat();
	Bureaucrat(const std::string&, int);
	Bureaucrat(const Bureaucrat&);
	~Bureaucrat();
	Bureaucrat& operator = (const Bureaucrat&);
	std::string getName(void) const;
	int	getGrade(void) const;
	void increaseGrade(void);
	void decreaseGrade(void);
};

std::ostream& operator << (std::ostream &os, const Bureaucrat &bureaucrat);
#endif
