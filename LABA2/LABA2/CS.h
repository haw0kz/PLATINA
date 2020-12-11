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
	void edit_CS();
	int GET_ID();
	static unsigned int GET_MaxID();
	int GET_amount();
	int GET_amountworking();
	std::string GET_Name();

friend std::ostream& operator << (std::ostream& out, const CS& cs);
friend std::istream& operator >> (std::istream& in, CS& cs);
friend std::ofstream& operator << (std::ofstream& fout, const CS& cs);
friend std::ifstream& operator >> (std::ifstream& fin, CS& cs);
};

