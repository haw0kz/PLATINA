#include "CS.h"
#include "utils.h"
using namespace std;

int CS::MaxID = 0;

CS::CS()
{
	id = ++MaxID;
}
void CS::edit_CS()
{
    cout<< "������� ����� ���������� ���������� �����: ";
    amountworking = verification(0, amount, "������� ����� ���������� ���������� �����: ");
}

int CS::GET_ID()
{
    return id;
}

unsigned int CS::GET_MaxID()
{
    return MaxID;
}
int CS::GET_amount()
{
    return amount;
}

int CS::GET_amountworking()
{
    return amountworking;
}

std::string CS::GET_Name()
{
    return name;
}

ostream& operator << (ostream& out, const CS& cs)
{
    cout << "�������������� CS: " << cs.id << endl;
    cout << "�������� CS: " << cs.name << endl;
    cout << "���������� CS : " << cs.amount << endl;
    cout << "���������� ����������: CS " << cs.amountworking << endl;
    cout << "������������� CS: " << cs.efficiency << endl;
    return out;
}
istream& operator >> (istream& in, CS& cs)
{
    cout << "������� ��������:";
    cin.ignore(1, '\n');
    getline(cin, cs.name);
    cout << "������� ���������� ����� : " <<  endl;
    cs.amount=verification(0,100, "������� ���������� �����:");
    cout << "������� ���������� ���������� �����:" << endl;
    cs.amountworking=verification(0,cs.amount, "������� ���������� ���������� �����:");
    cout << "������� �������������:" << endl;
    cs.efficiency=verification(0.0,1.0, "������� �������������:");
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