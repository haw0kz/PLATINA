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
    cout<< "Введите новое количество работающих цехов: ";
    amountworking = verification(0, amount, "Введите новое количество работающих цехов: ");
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
    cout << "Индентификатор CS: " << cs.id << endl;
    cout << "Название CS: " << cs.name << endl;
    cout << "Количество CS : " << cs.amount << endl;
    cout << "Количество работающих: CS " << cs.amountworking << endl;
    cout << "Эффективность CS: " << cs.efficiency << endl;
    return out;
}
istream& operator >> (istream& in, CS& cs)
{
    cout << "Введите название:";
    cin.ignore(1, '\n');
    getline(cin, cs.name);
    cout << "Введите количество цехов : " <<  endl;
    cs.amount=verification(0,100, "Введите количество цехов:");
    cout << "Введите количество работающих цехов:" << endl;
    cs.amountworking=verification(0,cs.amount, "Введите количество работающих цехов:");
    cout << "Введите эффективность:" << endl;
    cs.efficiency=verification(0.0,1.0, "Введите эффективность:");
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