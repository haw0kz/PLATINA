#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

template<typename T>
void mergesort(T* a, T* b, size_t start, size_t end)
{
    if (end - start < 2)
        return;
    if (end - start == 2)
    {
        if (a[start] > a[start + 1])
            swap(a[start], a[start + 1]);
        return;
    }
    mergesort(a, b, start, start + (end - start) / 2);
    mergesort(a, b, start + (end - start) / 2, end);
    size_t s1 = start;
    size_t mid = start + (end - start) / 2;
    size_t s2 = mid;
    int i = 0;
    while (i < end - start)
    {

        if (s1 >= mid || (s2 < end && a[s2] <= a[s1]))
        {
            b[i] = a[s2];
            ++s2;
        }
        else
        {
            b[i] = a[s1];
            ++s1;
        }
        i++;
    }
    for (size_t i = start; i < end; ++i)
        a[i] = b[i - start];

}

vector<int>mergeSort_by_Pulkov(vector<int>a)
{
    vector<int>b(a.size(), 0);
    mergesort(&a[0], &b[0], 0, a.size());
    return a;

}


vector<double>mergeSort_by_Pulkov(vector<double>a)
{
    vector<double>b(a.size(), 0);
    mergesort(&a[0], &b[0], 0, a.size());
    return a;

}