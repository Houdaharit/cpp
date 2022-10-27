#ifndef FORM_HPP
#define FORM_HPP
#include "Bureaucrat.hpp"

class Form
{
	const std::string name;
	bool is_signed;
	public:
		Form();
		Form(const Form&);
		Form& operator = (const Form&);
		~Form();
};
#endif
