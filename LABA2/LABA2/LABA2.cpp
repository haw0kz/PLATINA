#include <iostream>
#include <fstream>
#include <cstdlib> 
#include <string>
#include <vector>
#include <iostream>
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
void deletePipe(vector<Pipe>& p)
{
	cout << "Введите индекс трубы: ";
	unsigned int index = GetCorrectNumber(1u, p.size());
	p.erase(p.begin() + index - 1);
}

void deleteCS(vector<CS>& k)
{
	cout << "Введите индекс КС: ";
	unsigned int index = GetCorrectNumber(1u, k.size());
	k.erase(k.begin() + index - 1);
}



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
	vector<int> result;
	for (int i = 0; i < pipe.size(); i++)
	{
		if (pipe[i].repaired == a)
		{
			result.push_back(i);
		}
	}
	return result;
}

string nameoffile()
{
	string name;
	cout << "Введите название file: ";
	cin.ignore(1, '\n');
	getline(cin, name);
	return name;
}

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



int main()
{
	vector <Pipe> pipegroup;
	vector <CS> CSgroup;
	setlocale(LC_ALL, "ru");

	bool cs_accept = false;
	bool pipe_accept = false;

	while (true)
	{

		menu();
		switch (GetCorrectNumber(0, 15))
		{
		case 1:
		{
			Pipe pipe;
			cin >> pipe;
			pipe_accept = true;
			pipegroup.push_back(pipe);
			break;
		}
		case 2:
		{
			CS cs;
			cin >> cs;
			cs_accept = true;
			CSgroup.push_back(cs);
			break;
		}
		case 3:
		{
			for (auto& pipe : pipegroup)
			cout << pipe;
			system("pause");
			break;
		}

		case 4:
		{
			for (auto& cs : CSgroup)
			cout << cs;	
			system("pause");
			break;
		}
		case 5:
		{
			if (pipe_accept == true)
			{
				repairpipe(SelectPipe(pipegroup));
				system("pause");
				break;
			}
			else
			{
				cout << "Вы не ввели данные для ТРУБЫ" << endl;
				system("pause");
				break;
			}
		}
		case 6:

		{
			if (cs_accept == true)
			{
				repairceh(SelectCS(CSgroup));
				system("pause");
				break;
			}
			else
			{
				cout << "Вы не ввели данные для ТРУБЫ" << endl;
				system("pause");
				break;
			}

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
					for (Pipe pipe : pipegroup)
					fout << pipe;
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
					int countofpipe;
					fin >> countofpipe;
					pipegroup.resize(countofpipe);
					for (Pipe& pipe : pipegroup)
					fin >> pipe;
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
					fout << CSgroup.size();
					for (CS cs : CSgroup)
					fout << cs;
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
					int countofCS;
					fin >> countofCS;
					CSgroup.resize(countofCS);
					for (CS& cs : CSgroup)
					fin >> cs;
					fin.close();
					break;
				}
		}

		case 11:
		{
			if (pipegroup.size() > 0)
			{
				deletePipe(pipegroup);
				break;
			}
			else
			{
				cout << "Вы забыли ввести трубы!\n" << endl;
				system("Pause");
				break;
			}
		}

		case 12:
		{
			if (CSgroup.size() > 0)
			{
				deleteCS(CSgroup);
				break;
			}
			else
			{
				cout << "Вы забыли ввести  CS!\n" << endl;
				system("Pause");
				break;
			}
		}

		case 13:
		{
			auto index = CSFilterofname(CSgroup);
			for (int i = 0; i < index.size(); i++)
			{
				cout << CSgroup[index[i]] << endl;
			}
			system("pause");
			break;
		}

		case 14:
		{
			auto index = CSFilterofprocent(CSgroup);
			for (int i = 0; i < index.size(); i++)
			{
				cout << CSgroup[index[i]] << endl;
			}
			system("pause");
			break;
		}

		case 15:
		{
			auto index = Pipefilterofrepair(pipegroup);
			for (int i = 0; i < index.size(); i++)
			{
				cout << pipegroup[index[i]] << endl;
			}
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


