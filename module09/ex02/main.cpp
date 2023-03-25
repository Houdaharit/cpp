#include "PmergeMe.hpp"

int	check_input(int argc, char **argv)
{
	int i = 1;
	while (i < argc)
	{
		if (!isdigit(argv[i][0]))
		{
			std::cerr << "Error" << std::endl;
			return (-1);
		}
		i++;
	}
	return (0);
}

void	insert_vector(std::vector<int> &v, int argc, char **argv)
{
	int i = 1;

	while (i < argc)
	{
		v.push_back(atoi(argv[i]));
		i++;
	}
}

void	insert_deque(std::deque<int> &q, int argc, char **argv)
{
	int i = 1;

	while (i < argc)
	{
		q.push_back(atoi(argv[i]));
		i++;
	}
}

int main(int argc, char **argv)
{
	std::vector<int> v;
	std::deque<int> d;

	if (argc > 1)
	{
		if (check_input(argc, argv) == -1)
			return 1;
		insert_vector(v, argc, argv);
		insert_deque(d, argc, argv);
		std::vector<int> temp_v(v.size(), 0);
		std::deque<int> temp_d(d.size(), 0);
		mergesort_v(v, temp_v, 0, v.size() - 1, 2);
		mergesort_d(d, temp_d, 0, d.size() - 1, 2);
		std::cout << "Vector: " << std::endl;
		for(size_t i = 0; i < v.size(); i++)
			std::cout << v[i] << " ";
		std::cout << std::endl;
		std::cout << "Deque: " << std::endl;
		for(size_t i = 0; i < d.size(); i++)
			std::cout << d[i] << " ";
		std::cout << std::endl;
	}
	return 0;	
}
