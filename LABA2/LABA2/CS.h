#pragma once
#include <string>
#include <iostream>
#include <fstream>
class CS
{
	int id;
	static int MaxID;
public:
	CS();
	
	std::string name;
	int amount;
	int amountworking;
	float efficiency;

friend std::ostream& operator << (std::ostream& out, const CS& cs);
friend std::istream& operator >> (std::istream& in, CS& cs);
friend std::ofstream& operator << (std::ofstream& fout, const CS& cs);
friend std::ifstream& operator >> (std::ifstream& fin, CS& cs);
};

