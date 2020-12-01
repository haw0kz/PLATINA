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
    out << "��������������: " << cs.id << endl;
    out << "��������: " << cs.name << endl;
    out << "���������� : " << cs.amount << endl;
    out << "���������� ����������: " << cs.amountworking << endl;
    out << "�������������: " << cs.efficiency << endl;
    return out;
}
istream& operator >> (istream& in, CS& cs)
{
    cout << "������� ��������:";
    cin >> cs.name;
    verification(cs.amount, "������� ���������� �����:");
    do
    {
      verification(cs.amountworking, "������� ���������� ���������� �����:");
    } while (cs.amountworking > cs.amount);
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