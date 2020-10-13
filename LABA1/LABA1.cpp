#include <iostream>
#include <fstream>
#include <cstdlib> 
using namespace std;

void menu()
{
	system("cls");
	cout << "1.Добавить трубу " << endl;
	cout << "2.Добавить КС " << endl;
	cout << "3.Просмотр всех объектов" << endl;
	cout << "4.Редактировать трубу " << endl;
	cout << "5.Редактировать КС" << endl;
	cout << "6.Сохранить" << endl;
	cout << "7.Загрузить" << endl;
	cout << "8.Выход" << endl;
}

void check()
{
	do
	{
		cin.clear();
		cin.ignore(1000, '/n');
		int number;
		cin >> number;
	} while (cin.fail());
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
void repairpipe(Pipe& pipe1)
{
	cout << endl;
	cout << "В ремонте труба?" << endl;
	cin >> pipe1.repaired;

}

void repairceh(CS& cs1)
{
	if (cs1.accept == true)
	{
		int x;
		cout << "Введите : 1 - Запуск цеха ; 0 - Остановка цеха " << endl;
		cin >> x;
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
	ifstream fin("vvod.txt");
	//pipe1.exist = true;
	//cs1.exist = true;
	if (!fin.is_open())
		cout << "Файл не может быть открыт!\n";
	else
	{
		fin >> pipe1.id >> pipe1.length >> pipe1.diam >> pipe1.repaired;
		fin >> cs1.id >> cs1.name >> cs1.amount >> cs1.amountworking >> cs1.efficiency;
	}
}


void vivod(Pipe& pipe1, CS& cs1)
{
	
	ofstream outf("VIVOD.txt", ios::app);
	outf << "Индентификатор трубы:" << pipe1.id << endl;
	outf << "Длина трубы:" << pipe1.length << endl;
	outf << "Диаметр трубы:" << pipe1.diam << endl;
	outf << "Находится ли труба на ремонте?:" << pipe1.repaired << endl;
	outf << endl;
	outf << "Индентификатор КС:" << cs1.id << endl;
	outf << "Название КС:" << cs1.name << endl;
	outf << "Количество КС:" << cs1.amount << endl;
	outf << "Количество КС, находящихся на ремонте:" << cs1.amountworking << endl;
	outf << "Эффективность КС:" << cs1.efficiency << endl;
	outf << endl;
}

void prosmotr(Pipe pipe1, CS cs1)
{
	cout << "Индентификатор трубы:" << pipe1.id << endl;
	cout << "Длина трубы:" << pipe1.length << endl;
	cout << "Диаметр трубы:" << pipe1.diam << endl;
	cout << "Находится ли труба на ремонте?:" << pipe1.repaired << endl;
	cout << endl;
	cout << "Индентификатор КС:" << cs1.id << endl;
	cout << "Название КС:" << cs1.name << endl;
	cout << "Количество КС:" << cs1.amount << endl;
	cout << "Количество КС, находящихся на ремонте:" << cs1.amountworking << endl;
	cout << "Эффективность КС:" << cs1.efficiency << endl;

}


void addpipe(Pipe& pipe1 )
{
	
	cout << "Введите id " << endl;
	cin >> pipe1.id;
	cout << "Введите длину " << endl;
	cin >> pipe1.length;
	cout << "Введите диаметр " << endl;
	cin >> pipe1.diam;
	cout << "На ремонте? Введите 0 - НЕТ, 1 - ДА " << endl;
	cin >> pipe1.repaired;
	pipe1.accept = true;

}

void addCS(CS& cs1)
{

	cout << "Введите id " << endl;
	cin >> cs1.id;
	cout << "Введите название КС " << endl;
	cin >> cs1.name;
	cout << "Введите количество " << endl;
	cin >> cs1.amount;
	cout << "Количество в работе " << endl;
	cin >> cs1.amountworking;
	cout << "Эффективность " << endl;
	cin >> cs1.efficiency;
	cs1.accept = true;

}

int main()
{ 
	Pipe pipe1;
	CS cs1;

	while (true)
	{

		setlocale(LC_ALL, "ru");
		menu();
		int number;
		cin >> number;
		{
			
			switch (number)
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
					prosmotr(pipe1, cs1);
					system("pause");
					break;
				}
				case 4:
				{
					repairpipe(pipe1);
					system("pause");
					break;
				}
				case 5:
				{
					repairceh(cs1);
					system("pause");
					break;
				}
				case 6:
				{
					vivod(pipe1,cs1);
					system("pause");
					break;
				}
				case 7:
				{
					vvod(pipe1,cs1);
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

}






