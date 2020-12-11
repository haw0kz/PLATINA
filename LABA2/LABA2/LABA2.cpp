#include <iostream>
#include <fstream>
#include <cstdlib> 
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <typeinfo>
#include "Pipe.h"
#include "CS.h"
#include "utils.h"
using namespace std;

void menu()
{
	system("cls");
	cout << "1.Добавить трубу " << endl;
	cout << "2.Добавить CS " << endl;
	cout << "3.Просмотр всех труб:" << endl;
	cout << "4.Просмотр всех CS:" << endl;
	cout << "5.Редактировать трубу " << endl;
	cout << "6.Редактировать CS" << endl;
	cout << "7.Сохранить ТРУБЫ" << endl;
	cout << "8.Загрузить ТРУБЫ" << endl;
	cout << "9.Сохранить CS" << endl;
	cout << "10.Загрузить CS" << endl;
	cout << "11.Удалить трубу" << endl;
	cout << "12.Удалить CS" << endl;
	cout << "13.Поиск CS по названию:" << endl;
	cout << "14.Поиск CS по проценту незадействованных цехов:" << endl;
	cout << "15.Поиск трубы по признаку «в ремонте» " << endl;

	cout << "0.Выход" << endl;
}


template<typename PC, typename T>
using Filter = bool(*)(PC & pc, T param);

bool verificationNAME(CS& cs, string parametr)
{
	return cs.GET_Name() == parametr;
}

bool verificationREPAIR(Pipe& pipe, bool repair)
{
	return pipe.GET_Repair() == repair;
}

bool verificationCS(CS& cs, float percent)
{
	return abs(percent - ((float)(cs.GET_amount() - (float)cs.GET_amountworking()) / (float)cs.GET_amount() * 100)) < 1e-6;
}


template<typename PC, typename T>
vector<int> findpipeORcs(unordered_map<int, PC>& pc, Filter<PC, T> f, T param)
{
	vector <int> res;
	int i = 0;
	res.reserve(pc.size());
	for (auto& pipeorks : pc)
	{
		if (f(pipeorks.second, param))
			res.push_back(pipeorks.first);

	}
	return res;
}


/*

int GetCorrectNumber(int left, int right)
{
	int x;
	while (((cin >> x)).fail() || x<left || x>right)
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Ошибка при вводе" << endl << "Введите команду: ";
	}
	return x;

}

int inputInteger(string message)
{
	int value;
	cout << message;
	while ((cin >> value).fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Ошибка при вводе " << endl << message;

	}
	return value;
}

float inputFloat(string message)
{
	float value;
	cout << message;
	while ((cin >> value).fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Ошибка при вводе " << endl << message;
	}
	return value;
}
/*
void repairpipe(Pipe& pipe)
{	

 verification(pipe.repaired, "Ремонт: ");

}


void repairceh(CS& cs)
{

		int x = inputInteger("Введите : 1 - Запуск цеха ; 0 - Остановка цеха ");
		while (!(x == 0 || x == 1))
		{
			cout << " Вы ввели число не в том диапозоне " << endl;
			x = inputInteger("Введите : 1 - Запуск цеха ; 0 - Остановка цеха");
		}

		if (x == 1)
		{
			if (cs.amount <= cs.amountworking)
			{
				cout << "Ошибка, невозможно " << endl;
			}
			else
			{
				cs.amountworking++;
				cout << "Новое количество цехов " << cs.amountworking << endl;
			}

		}
		else
		{
			if (cs.amount < cs.amountworking)
			{
				cout << "Ошибка, невозможно " << endl;
			}
			else
			{
				if (cs.amountworking > 0)
				{
					cs.amountworking--;
					cout << "Новое количество цехов " << cs.amountworking << endl;
				}
				else
				{
					cout << "Ошибка, невозможно" << endl;
				}
			}

		}

}


/*
void vvod(Pipe& pipe, CS& cs)
{
	ifstream fin("text.txt");
	if (!fin.is_open())
		cout << "Файл не может быть открыт!\n";
	else
	{
		fin >> pipe.id >> pipe.length >> pipe.diam >> pipe.repaired;

		fin >> cs.id >> cs.name >> cs.amount >> cs.amountworking >> cs.efficiency;
	}
	fin.close();
}
*/

/*
void vivod(const Pipe& pipe, const CS& cs)
{
	// константые ссылки и один файл ввода-вывода
	ofstream outf("text.txt", ios::out);
	if (!outf.is_open())
		cout << "Файл не может быть открыт!\n";
	else
	outf << pipe1.id << endl;
	outf << pipe1.length << endl;
	outf << pipe1.diam << endl;
	outf << pipe1.repaired << endl;
	outf << cs1.id << endl;
	outf << cs1.name << endl;
	outf << cs1.amount << endl;
	outf << cs1.amountworking << endl;
	outf << cs1.efficiency << endl;
	outf.close();
}
 */

 /*
void prosmotrpipe(const Pipe& pipe)
{
	cout << "Индентификатор трубы:" << pipe.id << endl;
	cout << "Длина трубы:" << pipe.length << endl;
	cout << "Диаметр трубы:" << pipe.diam << endl;
	cout << "Находится ли труба на ремонте?:" << pipe.repaired << endl;

}


void prosmotrcs(const CS& cs)
{
	cout << "Индентификатор КС:" << cs.id << endl;
	cout << "Название КС:" << cs.name << endl;
	cout << "Количество КС:" << cs.amount << endl;
	cout << "Количество КС, находящихся на ремонте:" << cs.amountworking << endl;
	cout << "Эффективность КС:" << cs.efficiency << endl;

}
*/




void deletePipe(unordered_map<int, Pipe>& p)
{
	unsigned int index;
	do
	{
		cout << "Введите индекс трубы: ";
		index = verification(1u, Pipe::GET_MaxID(), "Введите индекс трубы: ");
	} while (p.find(index) == p.end());
	
	p.erase(p.find(index));
//	cout << typeid(p.find(index)).name();
	system("pause");


}

void deleteCS(unordered_map<int, CS>& k)
{
	unsigned int index;
	do {
		cout << "Введите индекс КС: ";
		index = verification(1u, CS::GET_MaxID(), "Введите индекс КС: ");
		k.erase(k.find(index));
	} while (k.find(index) == k.end());
	k.erase(k.find(index));

}

/*

Pipe& SelectPipe(vector<Pipe>& g)
{
	cout << "Enter index:";
	unsigned int index = GetCorrectNumber(1u, g.size());
	return g[index - 1];
}

CS& SelectCS(vector<CS>& g)
{
	cout << "Enter index:";
	unsigned int index = GetCorrectNumber(1u, g.size());
	return g[index - 1];
}



vector<int> Pipefilterofrepair(vector<Pipe>& pipe)
{
	cout << "1 - находится в ремонте, 0 - находится не в ремонте" << endl;
	int a;
	cin >> a;
	vector<int> result; // в вектор result собираем индексы
	for (int i = 0; i < pipe.size(); i++)
	{
		if (pipe[i].repaired == a)
		{
			result.push_back(i);
		}
	}
	return result;
}
*/

string nameoffile()
{
	string name;
	cout << "Введите название file: ";
	cin.ignore(1, '\n');
	getline(cin, name);
	return name;
}

/*

vector<int> CSFilterofprocent(vector<CS>& cs)
{
	cout << "Введите процент : ";
	vector<int> result;
	float g;
	cin >> g;
	for (int i = 0; i< cs.size(); i++)
	{
		float f;
		f = (((float)cs[i].amount - (float)cs[i].amountworking) / (float)cs[i].amount) * 100;
		if (abs(f - g) <= 1)
		{
			result.push_back(i);
		}
	}
	return result;
}

vector<int> CSFilterofname(vector<CS>& cs)
{
	cout << "Введите название CS: ";
	vector<int> result;
	string b;
	cin.ignore(1, '\n');
	getline(cin, b);
	for (int i = 0; i < cs.size(); i++)
	{
		if (cs[i].name == b)
		{
			result.push_back(i);
		}
	}
	return result;
}

*/


int main()
{
	unordered_map<int, Pipe> pipegroup;
	unordered_map<int, CS> CSgroup;
	setlocale(LC_ALL, "ru");

	//bool cs_accept = false;
	//bool pipe_accept = false;

	while (true)
	{

		menu();
		switch (verification(0, 15,"Введите команду MENU:"))

		{
		case 1:
		{
			Pipe pipe;
			cin >> pipe;
			pipegroup.insert(pair<int, Pipe> (pipe.GET_ID(), pipe));
			break;
		}
		case 2:
		{
			CS cs;
			cin >> cs;
			CSgroup.insert(pair<int, CS>(cs.GET_ID(),cs));
			break;
		}
		case 3:
		{
			if (pipegroup.size() > 0)
				for (auto iter = pipegroup.begin(); iter != pipegroup.end(); ++iter)
				{
					cout << iter->second;
					
				}
			else 
				cout << endl << "Вы забыли ввести данные трубы!\n";
			    system("Pause");
				break;
		}

		case 4:
		{
			if (CSgroup.size() > 0)
				for (auto iter = CSgroup.begin(); iter != CSgroup.end(); ++iter)
				{
					cout << iter->second;
				}
			else 
			cout << endl << "Вы забыли ввести данные трубы!\n";
			system("Pause");
			break;
			
		}

		case 5:
		{
			
			unordered_map <int, Pipe>::iterator number;
			if (pipegroup.size() > 0)
			{
				cout << "Введите ID Трубы: ";
				unsigned index = verification(1u, Pipe::GET_MaxID(), "Введите ID Трубы: ");
				number = pipegroup.find(index);
				number->second.edit_pipe();
			}
			else
			cout << "Вы забыли ввести данные КС!\n";
			system("Pause");
			break;
		}
		case 6:
		{
	
			unordered_map <int, CS>::iterator number;
			if (CSgroup.size() > 0)
			{
				cout << "Введите ID КС: ";
				unsigned index = verification(1u, CS::GET_MaxID(), "Введите ID КС: ");
				number = CSgroup.find(index);
				number->second.edit_CS();
			}
			else 
			cout << "Вы забыли ввести данные КС!\n";
			system("Pause");
			break;
		}
		
		case 7:
		{
			if (pipegroup.size() > 0)
			{
				ofstream fout;
				fout.open(nameoffile(), ios::out);
				if (!fout.is_open())
					cout << "Файл не может быть открыт!\n";
				else
				{
					fout << pipegroup.size();
					for (auto iter = pipegroup.begin(); iter != pipegroup.end(); ++iter)
						fout << iter->second;
					fout.close();
					break;
				}
			
			}
			else
			{
			    cout << "Вы забыли ввести данные для труб!\n" << endl;
				system("Pause");
				break;
			}
		}
		case 8:
		{
			{
				ifstream fin;
				fin.open(nameoffile(), ios::in);
				if (!fin.is_open())
					cout << "Файл не может быть открыт!\n";

				else
				{
					pipegroup.erase(pipegroup.begin(), pipegroup.end());
					int count;
					fin >> count;
					for (int i = 1; i <= count; ++i)
					{
						Pipe pipe;
						fin >> pipe;
						pipegroup.insert(pair<int, Pipe>(pipe.GET_ID(), pipe));
					}
					fin.close();
					break;
					
				}
			}
		
		}

		case 9:
		{
			if (CSgroup.size() > 0)
			{
				ofstream fout;
				fout.open(nameoffile(), ios::out);
				if (fout.is_open())
				{
					fout << CSgroup.size() << endl;
					for (auto iter = CSgroup.begin(); iter != CSgroup.end(); ++iter)
					fout << iter->second;
					fout.close();
				}	
				else
				{
					cout << "Файл не может быть открыт!\n";
				}
			}
			else
			{
				cout << "Вы забыли ввести данные для CS!\n" << endl;
				
			}
			system("Pause");
			break;

		}
		case 10:
		{
				ifstream fin;
				fin.open(nameoffile(), ios::in);
				if (!fin.is_open())
					cout << "Файл не может быть открыт!\n";
				else
				{
					CS cs;
					fin >> cs;
					CSgroup.insert(pair<int, CS>(cs.GET_ID(), cs));
					fin.close();
					break;
				}
		}

		case 11:
		{
			if (pipegroup.size() > 0)
			{
				deletePipe(pipegroup);
				
			}
			else
			{
				cout << "Вы забыли ввести трубы!\n" << endl;
				system("Pause");
				
			}
			break;
		}

		case 12:
		{
			if (CSgroup.size() > 0)
			{
				deleteCS(CSgroup);
				
			}
			else
			{
				cout << "Вы забыли ввести  CS!\n" << endl;
				system("Pause");
				
			}
			break;
		}

		case 13:
		{
			string name;
			cout << "Введите название CS для поиска: ";
			cin.ignore(1, '\n');
			getline(cin, name);
			if (CSgroup.size() != 0)
			{
				for (int i : findpipeORcs(CSgroup, verificationNAME, name))
					cout << CSgroup[i];
			}
			else cout << "Забыли добавить CS!" << endl;
			system("pause");
			break;
		}

		case 14:
		{
			float percent;
			cout << "Введите процент незадействованных CS для поиска:";
			cin >> percent;
			if (CSgroup.size() != 0)
			{

				for (int i : findpipeORcs(CSgroup, verificationCS, percent))
					cout << CSgroup[i];
			}
			else cout << "Забыли добавить CS!" << endl;
			system("pause");
			break;
		}

		case 15:
		{
			bool number;
			cout << "В ремонте труба? 1-да или 0-нет: ";
			number = verification(0, 1, "В ремонте труба? 1-да или 0-нет: ");
			if (pipegroup.size() != 0)
			{
				for (int i : findpipeORcs(pipegroup, verificationREPAIR, number))
					cout << pipegroup[i];
			}
			else cout << "Забыли добавить трубы!" << endl;
			system("pause");
			break;
		}

		case 0:
		{
			return 0;
		}
		}

	}

}


