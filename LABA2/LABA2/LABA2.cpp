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
#include "functions.h"
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
	cout << "16.Создать газотранспортную сеть" << endl;
	cout << "17.Сортировка сети" << endl;
	cout << "18.Вывод в файл" << endl;
	cout << "19.Загрузка из файла"  << endl;
	cout << "20.Удалить вершину из графа (СТОК)" << endl;
	cout << "21.Удалить газотранспортную сеть" << endl;
	cout << "22.Посмотреть газотранспортную сеть" << endl;

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


int main()
{
	unordered_map<int, Pipe> pipegroup;
	unordered_map<int, CS> CSgroup;
	unordered_map<int, vector<pairofCS>> k;
	setlocale(LC_ALL, "ru");

	//bool cs_accept = false;
	//bool pipe_accept = false;

	while (true)
	{

		menu();
		switch (verification(0, 22,"Введите команду MENU:"))

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
			    ofstream fout;
				fout.open(nameoffile(), ios::out);
				if (fout.is_open())
				{
					if (CSgroup.size() > 0)
					{
						fout << CSgroup.size();
						for (auto iter = CSgroup.begin(); iter != CSgroup.end(); ++iter)
						fout << iter->second;
					}
					else
					{
						cout << "Вы забыли ввести данные для КС!" << endl;
						fout.close();
					}
					
				}	
				else
				{
					cout << "Файл не может быть открыт!\n";
				}
			
			
			system("Pause");
			break;

		}
		case 10:
		{
			ifstream fin;
			fin.open(nameoffile(), ios::in);
			if (fin.is_open())
			{
				CSgroup.erase(CSgroup.begin(), CSgroup.end());
				int count;
				fin >> count;
				for (int i = 1; i <= count; ++i)
				{
					CS cs;
					fin >> cs;
					CSgroup.insert(pair<int, CS>(cs.GET_ID(), cs));
				}

				fin.close();
			}
			else 
			cout << "Файл не может быть открыт!" << endl;
			break;
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

		case 16:
		{
			unordered_map<int, bool> usedpipes;

			for (auto& unit : pipegroup)
			{
				usedpipes.insert(make_pair(unit.first, false));
			}

			k.clear();
			int time, indexpipe, indexks1, indexks2;
			cout << "Сколько раз введете КС и трубу?";
			time = verification(0, 200, "Сколько раз введете КС и трубу?");
			while (time--)
			{
				cout << "Введите индекс трубы ";
				indexpipe = verification(0, 200, "Введите индекс трубы ");
				while (usedpipes[indexpipe]) {
					cout << "Уже использовали" << endl;
					cout << "Введите индекс трубы ";
					indexpipe = verification(0, 200, "Введите индекс трубы ");
				}
				usedpipes[indexpipe] = true;
				cout << "Введите индекс КС1, от которой ";
				indexks1 = verification(0, 200, "Введите индекс КС1, от которой ");
				cout << "Введите индекс КС2, к которой ";
				indexks2 = verification(0, 200, "Введите индекс КС2, к которой ");
				fillinggraph(k, CSgroup, pipegroup, indexpipe, indexks1, indexks2);
			}
			displayofnetwork(k, CSgroup, pipegroup);
			system("pause");
			break;
		}

		case 17:
		{
			if (!searchforcycle(k))
			{
				unordered_map<int, bool> count;
				vector<int> answer;
				topologicalsort(k, count, answer);
				for (auto i = answer.begin(); i != answer.end(); i++)
				{
					cout << *i;
					if (i + 1 != answer.end()) cout << " ---->> ";
				}
				cout << endl;
				system("pause");
			}
			else
			{
				cout << "Граф оказался цикличным! ";
			}
			system("pause");
			break;
		}

		case 18:
		{
			downloadtofile(k);
			system("pause");
			break;
		}

		case 19:
		{
			unloadfromfile(k);
			system("pause");
			break;
		}

		case 20:
		{
			removeofconnection(k, CSgroup, pipegroup);
			system("pause");
			break;
		}

		case 21:
		{
			k.clear();
			cout << "Граф удалён!" << endl;
			system("pause");
			break;
		}

		case 22:
		{
			displayofnetwork(k, CSgroup, pipegroup);
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


