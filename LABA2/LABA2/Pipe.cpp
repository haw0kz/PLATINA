#include "Pipe.h"
#include "utils.h"
using namespace std;

int Pipe::MaxID = 0;

Pipe::Pipe()
{
	id = ++MaxID;
}

unsigned int Pipe::GET_MaxID()
{
	return MaxID;
}

void Pipe::edit_pipe()
{
	repaired = !repaired;
	cout << "Труба находится в ремонте? : " << repaired << endl;
}

int Pipe::GET_ID()
{
	return id;
}
bool Pipe::GET_Repair()
{
	return repaired;
}


ostream& operator << (ostream& out, const Pipe& pipe)
{
	
	cout << "Индентификатор ТРУБЫ: "<< pipe.id << endl;
	cout << "Длина ТРУБЫ: "<< pipe.length << endl;
	cout << "Диаметр ТРУБЫ: "<< pipe.diam << endl;
	cout << "В ремонте ТРУБА?  "<< pipe.repaired << endl;
	return out;
}
istream& operator >> (istream& in, Pipe& pipe)
{
	cout << "Введите длину ТРУБЫ: " <<  endl;
	pipe.length = verification(0,1000, "Введите длину ТРУБЫ: ");
	cout << "Введите диаметр ТРУБЫ: " << endl;
	pipe.diam=verification(0,1000, "Введите диаметр ТРУБЫ: ");
	cout << "В ремонте ТРУБА?: " << endl;
	pipe.repaired=verification(0,1, "В ремонте ТРУБА?: ");
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