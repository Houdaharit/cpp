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
