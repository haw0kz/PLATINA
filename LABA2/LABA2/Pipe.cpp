#include "Pipe.h"
#include "utils.h"
using namespace std;

int Pipe::MaxID = 0;

Pipe::Pipe()
{
	id = ++MaxID;
}

ostream& operator << (ostream& out, const Pipe& pipe)
{
	
	out << "Индентификатор: "<< pipe.id << endl;
	out << "Длина: "<< pipe.length << endl;
	out << "Диаметр: "<< pipe.diam << endl;
	out << "В ремонте?  "<< pipe.repaired << endl;
	return out;
}
istream& operator >> (istream& in, Pipe& pipe)
{
	verification(pipe.length, "Введите длину трубы: ");
	verification(pipe.diam, "Введите диаметр трубы: ");
	verification(pipe.repaired, "В ремонте?: ");
	return in;
}


ofstream& operator << (ofstream& fout, const Pipe& pipe)
{
	fout << endl << pipe.id << endl << pipe.length << endl << pipe.diam << endl << pipe.repaired;
	return fout;
}

ifstream& operator >> (ifstream& fin, Pipe& pipe)
{
	fin >> pipe.id >> pipe.length >> pipe.diam >> pipe.repaired;
	return fin;
}