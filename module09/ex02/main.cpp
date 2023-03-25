#include "PmergeMe.hpp"

int main()
{
    std::vector<int> array;

	std::cout << "Vector: " << std::endl;
    for(int i = 0;i<10;i++)
        array.push_back(rand() % 100 + 1);
    std::vector<int> temp(array.size(), 0);
	std::deque<int> d;
for(int i = 0;i<10;i++)
        d.push_back(rand() % 100 + 1);

	std::deque<int> temp_d(d.size(), 0);
    mergesort_v(array,temp, 0, 9,2);
    for(int i = 0; i<10; i++)
        std::cout << array[i] << std::endl;
 mergesort_d(d,temp_d, 0, 9,2);
 std::cout << "Deque: " << std::endl;
    for(int i = 0; i<10; i++)
        std::cout << d[i] << std::endl;

    return 0;
}
