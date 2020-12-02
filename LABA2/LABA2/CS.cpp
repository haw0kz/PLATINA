#include "CS.h"
#include "utils.h"
using namespace std;

int CS::MaxID = 0;

CS::CS()
{
	id = ++MaxID;
}

ostream& operator << (ostream& out, const CS& cs)
{
    out << "�������������� CS: " << cs.id << endl;
    out << "�������� CS: " << cs.name << endl;
    out << "���������� CS : " << cs.amount << endl;
    out << "���������� ����������: CS " << cs.amountworking << endl;
    out << "������������� CS: " << cs.efficiency << endl;
    return out;
}
istream& operator >> (istream& in, CS& cs)
{
    cout << "������� ��������:";
    cin.ignore(1, '\n');
    getline(cin, cs.name);
    verification(cs.amount, "������� ���������� �����:");
    verification(cs.amountworking, "������� ���������� ���������� �����:");
    verification(cs.efficiency, "������� �������������:");
    return in;
}

ofstream& operator << (ofstream& fout, const CS& cs)
{
    fout << endl << cs.id << endl << cs.name << endl << cs.amount << endl << cs.amountworking << endl << cs.efficiency;
    return fout;
}

ifstream& operator >> (ifstream& fin, CS& cs)
{
    fin >> cs.id>> cs.name >> cs.amount >> cs.amountworking>> cs.efficiency;
    return fin;
}