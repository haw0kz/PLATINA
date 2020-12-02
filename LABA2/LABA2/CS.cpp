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
    out << "Индентификатор CS: " << cs.id << endl;
    out << "Название CS: " << cs.name << endl;
    out << "Количество CS : " << cs.amount << endl;
    out << "Количество работающих: CS " << cs.amountworking << endl;
    out << "Эффективность CS: " << cs.efficiency << endl;
    return out;
}
istream& operator >> (istream& in, CS& cs)
{
    cout << "Введите название:";
    cin.ignore(1, '\n');
    getline(cin, cs.name);
    verification(cs.amount, "Введите количество цехов:");
    verification(cs.amountworking, "Введите количество работающих цехов:");
    verification(cs.efficiency, "Введите эффективность:");
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