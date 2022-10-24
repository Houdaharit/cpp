#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <exception>

class Bureaucrat
{
	const std::string name;
	int grade; 
	public:
	Bureaucrat();
	~Bureaucrat();
	Bureaucrat(const Bureaucrat&);
	Bureaucrat& operator = (const Bureaucrat&);
	std::string getName(void);
	int	getGrade(void);
};
#endif
