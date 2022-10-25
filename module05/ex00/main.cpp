#include "Bureaucrat.hpp"

int main ()
{
	Bureaucrat b("hamid", 180);
	Bureaucrat c(b);
	std::cout << b<< std::endl;
	return (0);
}
