#include "Harl.hpp"

int	level(std::string level)
{
	const char *s1[] = { "debug", "info", "warning", "error"};
	const char *s2[] = { "DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++)
	{
		if (level == s1[i] || level == s2[i])
			return (i + 1);
	}
	return (0);
}

int main(int argc, char **argv)
{
	Harl	harl;

	if (argc != 2)
	{
		std::cout << "levels: \n";
		std::cout << "1) DEBUG\n2) INFO\n3) WARNING\n4) ERROR";
		return (1);
	}
	harl.filter(argv[1]);
}
