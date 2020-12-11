#pragma once
#include <string>
#include <iostream>
#include <fstream>
class Pipe
{
   int id;
   static int MaxID;
   public:
	
	Pipe();
	float length;
	float diam;
	bool repaired = false;
	void edit_pipe();
	int GET_ID();
	bool GET_Repair();
	static unsigned int GET_MaxID();
	
	friend std::ostream& operator << (std::ostream& out, const Pipe& pipe);
	friend std::istream& operator >> (std::istream& in, Pipe& pipe);
	friend std::ofstream& operator << (std::ofstream& fout, const Pipe& pipe);
	friend std::ifstream& operator >> (std::ifstream& fin, Pipe& pipe);
	

};

