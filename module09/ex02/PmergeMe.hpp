#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <iostream>
#include <vector>
#include <deque>
#include <sys/time.h>
#include <cstdlib>

void merge_insert_v(std::vector<int>& arr, std::vector<int>& temp, int l, int r, int threshold);
void merge_v(std::vector<int>& arr, std::vector<int>& temp, int l, int m, int r);
void insert_sort_v(std::vector<int>& vec, int l, int r);
void merge_insert_d(std::deque<int>& arr, std::deque<int>& temp, int l, int r, int threshold);
void merge_d(std::deque<int>& arr, std::deque<int>& temp, int l, int m, int r);
void insert_sort_d(std::deque<int>& vec, int l, int r);
void sort_vector(int argc, char **argv);
void sort_deque(int argc, char **argv);
void display_vector(std::vector<int>& v);
void display_deque(std::deque<int>& q);
int check_input(int argc, char **argv);
#endif
