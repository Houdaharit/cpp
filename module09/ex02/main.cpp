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
	size_t j = 0;
	int input;

	while (i < argc)
	{
		j = 0;
		input = atoi(argv[i]);
		while(j < v.size() && v[j] != input)
			j++;
		if (j == v.size())
			v.push_back(input);
		i++;
	}
}

void	insert_deque(std::deque<int> &q, int argc, char **argv)
{
	int i = 1;
	int input;
	size_t j;

	while (i < argc)
	{
		j = 0;
		input = atoi(argv[i]);
		while(j < q.size() && q[j] != input)
			j++;
		if (j == q.size())
			q.push_back(input);
		i++;
	}
}

void	display_vector(std::vector<int>& v)
{
	if (v.size() > 20)
	{
		for(size_t i = 0; i < 20; i++)
			std::cout << v[i] << " ";
		std::cout << " [...]" << std::endl;
	}
	else
	{
		for(size_t i = 0; i < v.size(); i++)
			std::cout << v[i] << " ";
		std::cout << std::endl;
	}
}

void	sort_vector(int argc, char **argv)
{
	std::vector<int> v;
	struct timeval start;
	struct timeval end_t;
	size_t time;

	insert_vector(v, argc, argv);
	std::cout << "Before: "; 
	display_vector(v);
	std::vector<int> temp(v.size(), 0);
	gettimeofday(&start, NULL);
	merge_insert_v(v, temp, 0, v.size() - 1, 2);
	gettimeofday(&end_t, NULL);
	time = ((end_t.tv_sec * 1000000) + end_t.tv_usec) - ((start.tv_sec * 1000000) + start.tv_usec);
	std::cout << "After: "; 
	display_vector(v);
	std::cout << "Time to process a range of " << v.size() << " elements with std::vector: " << time << " us" << std::endl;
}

void	sort_deque(int argc, char **argv)
{
	std::deque<int> d;
	struct timeval start;
	struct timeval end_t;
	size_t time;

	insert_deque(d, argc, argv);
	std::deque<int> temp(d.size(), 0);
	gettimeofday(&start, NULL);
	merge_insert_d(d, temp, 0, d.size() - 1, 2);
	gettimeofday(&end_t, NULL);
	time = ((end_t.tv_sec * 1000000) + end_t.tv_usec) - ((start.tv_sec * 1000000) + start.tv_usec);
	std::cout << "Time to process a range of " << d.size() << " elements with std::deque: " << time << " us" << std::endl;
}

int main(int argc, char **argv)
{
	std::vector<int> v;

	if (argc > 1)
	{
		if (check_input(argc, argv) == -1)
			return 1;
		sort_vector(argc, argv);
		sort_deque(argc, argv);
	}
	return 0;	
}
