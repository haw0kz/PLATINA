#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

/*


void mergesort2(vector<int>&a, size_t start, size_t end)
{
    if (end - start < 2)
        return;
    if (end - start == 2)
    {
        if (a[start] > a[start + 1])
            swap(a[start], a[start + 1]);
        return;
    }
    mergesort2(a, start, start + (end - start) / 2);
    mergesort2(a, start + (end - start) / 2, end);
    vector<int>b;
    size_t s1 = start;
    size_t e1 = start + (end - start) / 2;
    size_t s2 = e1;
    int i = 0;
    while (b.size() < end - start)
    {

        if (s1 >= e1 || (s2 < end && a[s2] <= a[s1]))
        {
            b.push_back(a[s2]);
            ++s2;
        }
        else
        {
            b.push_back(a[s1]);
            ++s1;
        }
    }
    for (size_t i = start; i < end; ++i)
        a[i] = b[i - start];
   
}
*/

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
    size_t e1 = start + (end - start) / 2;
    size_t s2 = e1;
    int i = 0;
    while (i < end - start)
    {

        if (s1 >= e1 || (s2 < end && a.at(s2) <= a.at(s1)))
        {
            b[i]=a.at(s2);
            ++s2;
        }
        else
        {
            b[i] = a.at(s1);
            ++s1;
        }
        i++;
    }
    for (size_t i = start; i < end; ++i)
        a[i] = b.at(i - start);

}

vector<int>mrgsrtPULKOV(vector<int>a)
{
    vector<int>b(a.size(),0);
    vector<int>res(a.begin(), a.end());
    mergesort2(res,b, 0, res.size());
    return res;

}


