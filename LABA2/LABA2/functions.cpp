#include <iostream>
#include <vector>
#include <iostream>
#include <unordered_map>
#include "Pipe.h"
#include "CS.h"
#include "utils.h"
#include "functions.h"
using namespace std;

string nameoffile()
{
	string name;
	cout << "Введите название file: ";
	cin.ignore(1, '\n');
	getline(cin, name);
	return name;
}

void depth_first_search(int v, unordered_map<int, vector<pairofCS>>& g, unordered_map<int, bool>& count, vector<int>& answer) // добавляет ребро 
{
	count[v] = true;
	vector<pairofCS> array;
	if (g.find(v) != g.end()) {

		array = g[v];
		for (auto& unit : array) {
			int to = unit.id_CS;

			if (!count[to])
				depth_first_search(to, g, count, answer);
		}
	}
	answer.push_back(v);
}


bool depth_first_search_for_cycle(int v, unordered_map<int, vector<pairofCS>>& g, unordered_map<int, int>& cl, int& cycle_st) // проверка на цикличность 
{
	if (g.find(v) == g.end())
	{
		return false;
	}
	cl[v] = 1;
	for (size_t i = 0; i < g[v].size(); ++i) {
		int to;

		to = g[v][i].id_CS;
		if (cl[to] == 0) {
			if (depth_first_search_for_cycle(to, g, cl, cycle_st))  return true;
		}
		else if (cl[to] == 1) {
			cycle_st = to;
			return true;
		}
	}
	cl[v] = 2;
	return false;
}

unordered_map<int, int> visitedCS(unordered_map<int, vector<pairofCS>>& g) // 0-не посетили, 1-посетили, 2-при выходе из вершины 
{
	unordered_map<int, int> visitedArray;
	for (auto& unit : g)
	{
		visitedArray[unit.first] = 0;
		for (auto& p : unit.second)
		{
			visitedArray[p.id_CS] = 0;
		}
	}
	return visitedArray;
}

bool searchforcycle(unordered_map<int, vector<pairofCS>>& g)
{
	unordered_map<int, int> p;
	int cycle_st, cycle_end;
	p = visitedCS(g);
	cycle_st = -1;
	for (auto& unit : p)
		if (depth_first_search_for_cycle(unit.first, g, p, cycle_st)) break;
	if (cycle_st == -1) return false;
	else return true;
}

unordered_map<int, bool> usedCS(unordered_map<int, vector<pairofCS>>& g)
{
	unordered_map<int, bool>usedArray;
	for (auto& unit : g)
	{
		usedArray[unit.first] = false;
		for (auto& p : unit.second)
		{
			usedArray[p.id_CS] = false;
		}
	}
	return usedArray;
}

void topologicalsort(unordered_map<int, vector<pairofCS>>& g, unordered_map<int, bool>& count, vector<int>& answer) // топологическая сортировка 
{
	count = usedCS(g);
	answer.clear();
	for (auto& unit : count)
		if (!unit.second)
			depth_first_search(unit.first, g, count, answer);
	reverse(answer.begin(), answer.end());
}

void fillinggraph(unordered_map<int, vector<pairofCS>>& graph, unordered_map<int, CS>& CSgroup, unordered_map<int, Pipe>& pipegroup, int indexpipe, int indexks1, int indexks2)
{
	pairofCS g;
	g.id_pipe = indexpipe;
	g.id_CS = indexks2;
	graph[indexks1].push_back(g);
}

void displayofnetwork(unordered_map<int, vector<pairofCS>>& graph, unordered_map<int, CS>& CSgroup, unordered_map<int, Pipe>& pipegroup)

{
	for (auto& unit : graph)
	{
		cout << "КС с ID " << unit.first << " соединен с КС'ми ID: ";
		for (auto cs = unit.second.begin(); cs != unit.second.end(); cs++)
		{
			cout << cs->id_CS << " трубой длиной " << pipegroup[cs->id_pipe].length;
			if (cs + 1 != unit.second.end()) cout << ", ";
		}
		cout << endl;
	}
}


void downloadtofile(unordered_map<int, vector<pairofCS>> g)

{
	ofstream fout;
	fout.open(nameoffile(), ios::out);
	if (!fout.is_open())
		cout << "Файл не может быть открыт!" << endl;
	else
	{
		for (auto& unit : g)
		{
			fout << unit.second.size() << " ";
			fout << unit.first << " ";
			for (auto cs = unit.second.begin(); cs != unit.second.end(); cs++)
			{
				fout << cs->id_CS << " " << cs->id_pipe << " ";
			}
			fout << endl;
		}
		cout << "Данные были выведены в file!" << endl;
		fout.close();
	}
}

void unloadfromfile(unordered_map<int, vector<pairofCS>>& g)
{
	ifstream fin(nameoffile(), ios::out);
	if (!fin.is_open())
		cout << "Файл не может быть открыт!" << endl;
	else
	{
		int buff;
		while (fin >> buff)
		{
			int CSid1;
			fin >> CSid1;
			for (int i = 0; i < buff; i++)
			{
				int CSid2;
				fin >> CSid2;
				int pipeid;
				fin >> pipeid;
				pairofCS pair1;
				pair1.id_CS = CSid2;
				pair1.id_pipe = pipeid;
				g[CSid1].push_back(pair1);
			}
		}
		cout << "Данные были введены в file!" << endl;
		fin.close();
	}
}

bool verificationofdelete(unordered_map<int, vector<pairofCS>>& k, unordered_map<int, CS>& CSgroup, unordered_map<int, Pipe>& pipegroup, int& idCS)
{

	bool exist = false;
	vector<int> todelete;
	if (k.find(idCS) != k.end())
	{
		k.erase(idCS);
		exist = true;
	}
	for (auto unit = k.begin(); unit != k.end(); unit++)
	{
		for (auto i = 0; i < unit->second.size(); i++)
		{
			if (unit->second[i].id_CS == idCS) {
				unit->second.erase(unit->second.begin() + i);
				exist = true;
				todelete.push_back(unit->first);
			}
		}
	}
	for (auto& i : todelete)
	{
		if (k[i].size() == 0) k.erase(i);
	}
	return exist;
}


void removeofconnection(unordered_map<int, vector<pairofCS>>& k, unordered_map<int, CS> CSgroup, unordered_map<int, Pipe>& pipegroup)
{
	cout << "Введите ID КС: ";
	int idCS = verification(0, 200, "Введите ID КС: ");

	while (CSgroup.find(idCS) == CSgroup.end())
	{
		cout << "Введите еще раз, такой КС нет в сети" << endl;
		cout << "Введите ID КС: ";
		idCS = verification(0, 200, "Введите ID КС: ");
	}
	if (verificationofdelete(k, CSgroup, pipegroup, idCS))
	{
		cout << "Удален!" << endl;;
	}
	else
	{
		cout << "Не сток!";
	}


}
