#pragma once
#include <vector>

template <typename T>
using Participant = std::vector<T>(*)(std::vector<T>);

std::vector<int> std_sort(std::vector<int>);
std::vector<double> sort_for_integers_only(std::vector<double> data);


//place your method name here
//------------------------Team Simonov---------------------------
std::vector <int> quicksort_By_Simonov(std::vector<int> data);
std::vector <double> quicksort_By_Simonov(std::vector<double> data);
std::vector <int> shellsort_By_Chiganov(std::vector<int> data);
std::vector <double> shellsort_By_Chiganov(std::vector<double> data);
std::vector <int> mergeSort_by_Pulkov(std::vector<int> data);
std::vector <double> mergeSort_by_Pulkov(std::vector<double> data);

//---------------------------------------------------------------
//place your method name here

