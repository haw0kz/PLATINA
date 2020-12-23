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

int Shortlength(unordered_map<int, vector<pairofCS>>& g, unordered_map<int, Pipe>& pipegroup, const int& id_CS1, const int& id_CS2)
{
	unordered_map<int, bool> u = usedCS(g);
	int n = u.size();
	int s = id_CS1; 

	unordered_map<int, int> d;
	for (auto& el : g)
	{
		d[el.first] = 1e5;
		for (auto& el2 : el.second)
		{
			d[el2.id_CS] = 1e5;
		}
	}
	unordered_map<int, int> p;
	for (auto& el : g)
	{
		p[el.first] = 0;
		for (auto& el2 : el.second)
		{
			p[el2.id_CS] = 0;
		}
	}
	d[s] = 0;


	for (auto i1 = u.begin(); i1 != u.end(); i1++) {

		int v = -1;

		for (auto j1 = u.begin(); j1 != u.end(); j1++) {
			int j = j1->first;
			if (!u[j] && (v == -1 || d[j] < d[v]))
				v = j;
		}
		if (d[v] == 1e5)
			break;
		u[v] = true;

		for (auto j = g[v].begin(); j != g[v].end(); ++j) {
			
			int to = j->id_CS,
				len = pipegroup[j->id_pipe].length;
			if (d[v] + len < d[to]) {
				d[to] = d[v] + len;
				p[to] = v;
			}
		}
	}

	return d[id_CS2];
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



bool verificationofdelete(unordered_map<int, vector<pairofCS>>& g, unordered_map<int, CS>& CSgroup, unordered_map<int, Pipe>& pipegroup, int& idCS)
{

	bool exist = false;
	vector<int> todelete;
	if (g.find(idCS) != g.end())
	{
		g.erase(idCS);
		exist = true;
	}
	for (auto unit = g.begin(); unit != g.end(); unit++)
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
		if (g[i].size() == 0) g.erase(i);
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
