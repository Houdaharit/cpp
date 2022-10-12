#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{
	char	c;
	int	i;
	int	j;

	i = 1;
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		while (i < argc)
		{
			j = 0;
			while (argv[i][j])
			{
				c = toupper(argv[i][j]);
				std::cout << c;
				j++;
			}
			i++;
		}
	}
	std::cout << std::endl;
	return (0);
}
