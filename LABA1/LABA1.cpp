#include <iostream>
#include <fstream>
#include <cstdlib> 
#include <string>
using namespace std;

void menu()
{
	system("cls");
	cout << "1.Добавить трубу " << endl;
	cout << "2.Добавить КС " << endl;
	cout << "3.Просмотр всех труб:" << endl;
	cout << "4.Просмотр всех КС:" << endl;
	cout << "5.Редактировать трубу " << endl;
	cout << "6.Редактировать КС" << endl;
	cout << "7.Сохранить" << endl;
	cout << "8.Загрузить" << endl;
	cout << "9.Выход" << endl;
}

struct Pipe
{
	int id;
	float length;
	float diam;
	bool repaired = false;
	bool accept = false;
};

struct CS
{
	int id;
	string name;
	int amount;
	int amountworking;
	float efficiency;
	bool accept = false;

};

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

void repairpipe(Pipe& pipe1)
{
	int repair = inputInteger(" Введите 1 : труба в ремонте; 0 : труба не в ремонте ");
	while (!(repair == 0 || repair == 1))
	{
		cout << " Вы ввели число не в том диапозоне " << endl;
		repair = inputInteger("Введите 1 : труба в ремонте; 0 : труба не в ремонте ");
	}
	pipe1.repaired = repair;

}

int correct(int left, int right)
{
	int x;
	while ((cin >> x).fail() || x<left || x>right)
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << endl;
		cout << "Ошибка при вводе" << endl << "Введите команду: ";
	}
	return x;
}

void repairceh(CS& cs1)
{
	if (cs1.accept == true)
	{
		int x = inputInteger("Введите : 1 - Запуск цеха ; 0 - Остановка цеха ");
		while (!(x == 0 || x == 1))
		{
			cout << " Вы ввели число не в том диапозоне " << endl;
			x = inputInteger("Введите : 1 - Запуск цеха ; 0 - Остановка цеха");

		}


		if (x == 1)
		{
			if (cs1.amount <= cs1.amountworking)
			{
				cout << "Ошибка, невозможно " << endl;
			}
			else
			{
				cs1.amountworking++;
				cout << "Новое количество цехов " << cs1.amountworking << endl;
			}

		}
		else
		{
			if (cs1.amount < cs1.amountworking)
			{
				cout << "Ошибка, невозможно " << endl;
			}
			else
			{
				if (cs1.amountworking > 0)
				{
					cs1.amountworking--;
					cout << "Новое количество цехов " << cs1.amountworking << endl;
				}
				else
				{
					cout << "Ошибка, невозможно" << endl;
				}
			}

		}

	}
	else
	{
		cout << "Вы забыли ввести данные" << endl;
	}

}

void vvod(Pipe& pipe1, CS& cs1)
{
	ifstream fin("text.txt");
	if (!fin.is_open())
		cout << "Файл не может быть открыт!\n";
	else
	{
		fin >> pipe1.id >> pipe1.length >> pipe1.diam >> pipe1.repaired;

		fin >> cs1.id >> cs1.name >> cs1.amount >> cs1.amountworking >> cs1.efficiency;
	}
	fin.close();
}


void vivod(const Pipe& pipe1, const CS& cs1)
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

void prosmotrpipe(Pipe pipe1)
{
	cout << "Индентификатор трубы:" << pipe1.id << endl;
	cout << "Длина трубы:" << pipe1.length << endl;
	cout << "Диаметр трубы:" << pipe1.diam << endl;
	cout << "Находится ли труба на ремонте?:" << pipe1.repaired << endl;

}

void prosmotrcs(CS cs1)
{
	cout << "Индентификатор КС:" << cs1.id << endl;
	cout << "Название КС:" << cs1.name << endl;
	cout << "Количество КС:" << cs1.amount << endl;
	cout << "Количество КС, находящихся на ремонте:" << cs1.amountworking << endl;
	cout << "Эффективность КС:" << cs1.efficiency << endl;

}


void addpipe(Pipe& pipe1)
{
	pipe1.id = inputInteger("Введите идентификатор:");
	pipe1.length = inputFloat("Введите длину: ");
	pipe1.diam = inputFloat("Введите диаметр:");
	int repair = inputInteger("Введите 1 : труба в ремонте; 0 : труба не в ремонте ");
	while (!(repair == 0 || repair == 1))
	{
		cout << "Вы ввели число не в том диапозоне " << endl;
		repair = inputInteger("Введите 1 : труба в ремонте; 0 : труба не в ремонте ");
	}
	pipe1.repaired = repair;
	pipe1.accept = true;
}

void addCS(CS& cs1)
{
	cs1.id = inputInteger("Введите идентификатор :");
	cout << "Введите название КС: " << endl;
	cin.ignore();
	getline(cin, cs1.name);
	cs1.amount = inputInteger("Введите количество труб:");
	cs1.amountworking = inputInteger("Введите количество рабочих труб:");
	float efficiency = inputFloat("Эффективность в диапазоне от 0 до 1 :");
	while (efficiency > 1 || efficiency < 0)
	{
		cout << "Вы ввели число не в том диапозоне " << endl;
		efficiency = inputFloat("Эффективность в диапазоне от 0 до 1 : ");
	}
	cs1.efficiency = efficiency;
	cs1.accept = true;
}

int main()
{
	Pipe pipe1;
	CS cs1;
	setlocale(LC_ALL, "ru");

	while (true)
	{

		menu();
		switch (correct(0, 8))
		{
		case 1:
		{
			addpipe(pipe1);
			break;
		}
		case 2:
		{
			addCS(cs1);
			break;
		}
		case 3:
		{
			prosmotrpipe(pipe1);
			
			break;
		}

		case 4:
		{
		
			prosmotrcs(cs1);
			
			break;
		}
		case 5:
		{
			repairpipe(pipe1);
			
			break;
		}
		case 6:
		{
			repairceh(cs1);
			
			break;
		}
		case 7:
		{
			vivod(pipe1, cs1);
			
			break;
		}
		case 8:
		{
			vvod(pipe1, cs1);
		
			break;
		}

		case 0:
		{
			return 0;
		}


		}

	}

}



