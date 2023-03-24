#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <iostream>
#include <vector>

void mergesort(std::vector<int>& arr, std::vector<int>& temp, int l, int r, int threshold);
void merge(std::vector<int>& arr, std::vector<int>& temp, int l, int m, int r);
void insertion_sort(std::vector<int>& vec, int l, int r);
#endif
