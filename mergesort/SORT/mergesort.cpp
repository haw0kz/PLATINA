#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;


void mergesort2(vector<int>&a, vector<int>& b, size_t start, size_t end)
{
    if (end - start < 2)
        return;
    if (end - start == 2)
    {
        if (a[start] > a[start + 1])
            swap(a[start], a[start + 1]);
        return;
    }
    mergesort2(a,b, start, start + (end - start) / 2); 
    mergesort2(a,b, start + (end - start) / 2, end);
    size_t s1 = start; 
    size_t mid = start + (end - start) / 2; 
    size_t s2 = mid; 
    int i = 0;
    while (i < end - start)
    { 

        if (s1 >= mid || (s2 < end && a.at(s2) <= a.at(s1))) 
        {
            b.at(i)=a.at(s2);
            ++s2;
        }
        else
        {
            b.at(i) = a.at(s1);
            ++s1;
        }
        i++;
    }
    for (size_t i = start; i < end; ++i)
        a.at(i) = b.at(i - start);

}

vector<int>mrgsrtPULKOV(vector<int>a)
{
    vector<int>b(a.size(),0);
    mergesort2(a,b, 0, a.size());
    return a;

}


