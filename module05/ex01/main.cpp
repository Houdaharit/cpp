#include "Bureaucrat.hpp"
#include "Form.hpp"

int main ()
{
	try
	{
		Bureaucrat bureaucrat("Hamid", 140);
		Form form("Birth certificate", 140, 140);
		form.beSigned(bureaucrat);
		std::cout << form << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}
	return (0);
}
