#include <vector>
using namespace std;

vector<int> GenerateData(int size, int max_value = INT_MAX)
{
	//generate random data or read data from your file
	vector<int> data(size);
	for (int& d : data)
		d = rand() % max_value;
	return data;
}

vector<double> GenerateDoubleData()
{
	return { 1, 3, 2 };
}