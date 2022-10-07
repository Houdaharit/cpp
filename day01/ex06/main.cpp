#include "Harl.hpp"

int	cmp(const char *complain)
{
	if (!strcmp(complain, "debug"))
		return 1;
	if (!strcmp(complain, "info"))
		return 2;
	if (!strcmp(complain, "warning"))
		return 3;
	if (!strcmp(complain, "error"))
		return 4;
	return (0);
}

int main(int argc, char **argv)
{
	Harl	harl;

	if (argc != 2)
	{
		std::cout << "levels: \n";
		std::cout << "debug\tinfo\twarning\terror";
		return (1);
	}
	harl.filter((const char *)argv[1]);
}
