#include "PmergeMe.hpp"

void insertion_sort_v(std::vector<int>& vec, int l, int r)
{
	double	tmp;
	int		j;

	for (int i = l; i <= r; i++)
	{
		tmp = vec[i];
		j = i;
		while ((j > l) && (vec[j - 1] > tmp))
		{
			vec[j] = vec[j - 1];
			j--;
		}
		vec[j] = tmp;
	}
}

void merge_v(std::vector<int>& arr, std::vector<int>& temp, int l, int m, int r)
{
	int i = l;
	int j = m + 1;
	int k = l;

	while ((i <= m) && (j <= r))
	{
		if (arr[i] < arr[j])
			temp[k] =  arr[i++];
		else
			temp[k] = arr[j++];
		k++;
	}
	while(j <= r)
		temp[k++] = arr[j++];
	while(i <= m)
		temp[k++] = arr[i++];
	for (i = l; i <= r; i++)
		arr[i] = temp[i];
}

void mergesort_v(std::vector<int>& arr, std::vector<int>& temp, int l, int r, int threshold)
{
	if (l < r)
	{
		if ((r - l) <= threshold)
			insertion_sort_v(arr, l, r);
		else
		{
			int m = (l + r) / 2;
			mergesort_v(arr, temp, l, m, threshold);
			mergesort_v(arr, temp, m + 1, r, threshold);
			merge_v(arr, temp, l, m, r);
		}
	}
}

void insertion_sort_d(std::deque<int>& vec, int l, int r)
{
	double	tmp;
	int		j;

	for (int i = l; i <= r; i++)
	{
		tmp = vec[i];
		j = i;
		while ((j > l) && (vec[j - 1] > tmp))
		{
			vec[j] = vec[j - 1];
			j--;
		}
		vec[j] = tmp;
	}
}

void merge_d(std::deque<int>& arr, std::deque<int>& temp, int l, int m, int r)
{
	int i = l;
	int j = m + 1;
	int k = l;

	std::vector<int>::iterator it;
	while ((i <= m) && (j <= r))
	{
		if (arr[i] < arr[j])
			temp[k] =  arr[i++];
		else
			temp[k] = arr[j++];
		k++;
	}
	while(j <= r)
		temp[k++] = arr[j++];
	while(i <= m)
		temp[k++] = arr[i++];
	for (i = l; i <= r; i++)
		arr[i] = temp[i];
}

void mergesort_d(std::deque<int>& arr, std::deque<int>& temp, int l, int r, int threshold)
{
	if (l < r)
	{
		if ((r - l) <= threshold)
			insertion_sort_d(arr, l, r);
		else
		{
			int m = (l + r) / 2;
			mergesort_d(arr, temp, l, m, threshold);
			mergesort_d(arr, temp, m + 1, r, threshold);
			merge_d(arr, temp, l, m, r);
		}
	}
}
