#include "PmergeMe.hpp"

int main()
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
}
