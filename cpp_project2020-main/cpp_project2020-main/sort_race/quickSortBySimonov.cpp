#include <vector>
using namespace std;

//http://mindhalls.ru/quick-sort-c-cpp/
template<typename T>
void quicksort(T* mas, int size) {
    int i = 0;
    int j = size - 1;

    T mid = mas[size / 2];

    do {
        while (mas[i] < mid) {
            i++;
        }
        while (mas[j] > mid) {
            j--;
        }

        if (i <= j) {
            T tmp = mas[i];
            mas[i] = mas[j];
            mas[j] = tmp;

            i++;
            j--;
        }
    } while (i <= j);

    if (j > 0)
        quicksort(mas, j + 1);
    if (i < size)
        quicksort(&mas[i], size - i);
}

vector<int> quicksort_By_Simonov(vector<int> data)
{
    quicksort(&data[0], data.size());
    return data;
}

vector<double> quicksort_By_Simonov(vector<double> data)
{
    quicksort(&data[0], data.size());
    return data;
}