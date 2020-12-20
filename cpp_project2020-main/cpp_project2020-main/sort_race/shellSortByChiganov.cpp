#include <vector>
using namespace std;

template<typename T>
void shellsort(T* mas, int size)
    {
    size--;
        int h;
        for (h = 1; h <= size; h = 3 * h + 1);

        for (; h > 0; h /= 3)
            for (auto i = h; i <= size; i++)
            {
                int j = i;
                T vector = mas[i];
                while (j >= h && vector < mas[j - h])
                {
                    mas[j] = mas[j - h];
                    j -= h;
                }
                mas[j] = vector;
            }
    }

vector<int> shellsort_By_Chiganov(vector<int> data)
{
    shellsort(&data[0], data.size());
    return data;
}

vector<double> shellsort_By_Chiganov(vector<double> data)
{
    shellsort(&data[0], data.size());
    return data;
}