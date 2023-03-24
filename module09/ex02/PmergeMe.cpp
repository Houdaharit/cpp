#include <iostream>
#include <vector>

void insertion_sort(std::vector<int>& vec, int l, int r)
{
    for (int i = l; i <= r; i++)
    {
        double tmp = vec[i];
        int j = i;
        while ((j > l) && (vec[j - 1] > tmp))
        {
             vec[j] = vec[j - 1];
             j--;
        }
        vec[j] = tmp;
    }
}

void merge(std::vector<int>& arr, std::vector<int>& temp, int l, int m, int r)
{
    int i = l;
    int j = m + 1;
    int k = l;

	std::vector<int>::iterator it;
    while ((i <= m) && (j <= r))
    {
        if (arr[i] < arr[j])
        {
            temp[k] =  arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }
        for (; j <= r; j++, k++)
            temp[k] = arr[j];

        for (; i <= m; i++, k++)
            temp[k] = arr[i];

        for (i = l; i <= r; i++)
            arr[i] = temp[i];
}

void mergesort(std::vector<int>& arr, std::vector<int>& temp, int l, int r, int threshold)
{
    if (l < r)
    {
        if ((r - l) <= threshold)
            insertion_sort(arr, l, r);
        else
        {
            int m = (l + r) / 2;
            mergesort(arr, temp, l, m, threshold);
            mergesort(arr, temp, m + 1, r, threshold);
            merge(arr, temp, l, m, r);
        }
    }
}
/*int main()
{
	std::vector<int> array;

    for(int i = 0;i<10;i++)
        array.push_back(rand() % 100 + 1);

	std::vector<int> temp(array.size(), 0);
    mergesort(array,temp, 0, 9,2);
	for(int i = 0; i<10; i++)
		std::cout << temp[i] << std::endl;
    //delete[] temp;

    return 0;
}*/
