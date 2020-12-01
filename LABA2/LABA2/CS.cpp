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
    out << "Индентификатор: " << cs.id << endl;
    out << "Название: " << cs.name << endl;
    out << "Количество : " << cs.amount << endl;
    out << "Количество работающих: " << cs.amountworking << endl;
    out << "Эффективность: " << cs.efficiency << endl;
    return out;
}
istream& operator >> (istream& in, CS& cs)
{
    cout << "Введите название:";
    cin >> cs.name;
    verification(cs.amount, "Введите количество цехов:");
    do
    {
      verification(cs.amountworking, "Введите количество работающих цехов:");
    } while (cs.amountworking > cs.amount);
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