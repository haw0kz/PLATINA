#include <vector>
#include <algorithm>

using namespace std;

vector<int> std_sort(vector<int> data)
{
	sort(data.begin(), data.end());
	return data;
}
vector<double> sort_for_integers_only(vector<double> data)
{
	//return unsorted vector if data doesn't match your method
	return { 1,0 };
}