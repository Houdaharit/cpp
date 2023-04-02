#include "PmergeMe.hpp"

void insert_sort_v(std::vector<int>& vec, int f, int l)
{
	double	tmp;
	int		j;

	for (int i = f; i <= l; i++)
	{
		tmp = vec[i];
		j = i;
		while ((j > f) && (vec[j - 1] > tmp))
		{
			vec[j] = vec[j - 1];
			j--;
		}
		vec[j] = tmp;
	}
}

void merge_v(std::vector<int>& vec, std::vector<int>& temp, int f, int m, int l)
{
	int i = f;
	int j = m + 1;
	int k = f;

	while ((i <= m) && (j <= l))
	{
		if (vec[i] < vec[j])
			temp[k] =  vec[i++];
		else
			temp[k] = vec[j++];
		k++;
	}
	while(j <= l)
		temp[k++] = vec[j++];
	while(i <= m)
		temp[k++] = vec[i++];
	for (i = f; i <= l; i++)
		vec[i] = temp[i];
}

void merge_insert_v(std::vector<int>& vec, std::vector<int>& temp, int f, int l, int k)
{
	if (f < l)
	{
		if ((l - f) <= k)
			insert_sort_v(vec, f, l);
		else
		{
			int m = (f + l) / 2;
			merge_insert_v(vec, temp, f, m, k);
			merge_insert_v(vec, temp, m + 1, l, k);
			merge_v(vec, temp, f, m, l);
		}
	}
}

void insert_sort_d(std::deque<int>& deq, int f, int l)
{
	double	tmp;
	int		j;

	for (int i = f; i <= l; i++)
	{
		tmp = deq[i];
		j = i;
		while ((j > f) && (deq[j - 1] > tmp))
		{
			deq[j] = deq[j - 1];
			j--;
		}
		deq[j] = tmp;
	}
}

void merge_d(std::deque<int>& deq, std::deque<int>& temp, int f, int m, int l)
{
	int i = f;
	int j = m + 1;
	int k = f;

	while ((i <= m) && (j <= l))
	{
		if (deq[i] < deq[j])
			temp[k] =  deq[i++];
		else
			temp[k] = deq[j++];
		k++;
	}
	while(j <= l)
		temp[k++] = deq[j++];
	while(i <= m)
		temp[k++] = deq[i++];
	for (i = f; i <= l; i++)
		deq[i] = temp[i];
}

void merge_insert_d(std::deque<int>& deq, std::deque<int>& temp, int f, int l, int threshold)
{
	if (f < l)
	{
		if ((l - f) <= threshold)
			insert_sort_d(deq, f, l);
		else
		{
			int m = (f + l) / 2;
			merge_insert_d(deq, temp, f, m, threshold);
			merge_insert_d(deq, temp, m + 1, l, threshold);
			merge_d(deq, temp, f, m, l);
		}
	}
}
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

void	display_deque(std::deque<int>& deq)
{
	if (deq.size() > 20)
	{
		for(size_t i = 0; i < 20; i++)
			std::cout << deq[i] << " ";
		std::cout << " [...]" << std::endl;
	}
	else
	{
		for(size_t i = 0; i < deq.size(); i++)
			std::cout << deq[i] << " ";
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
