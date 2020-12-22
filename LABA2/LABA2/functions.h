#pragma once
#include <iostream>
#include <vector>
#include <iostream>
#include <unordered_map>
#include "Pipe.h"
#include "CS.h"
#include "utils.h"
#include "functions.h"
using namespace std;

struct pairofCS
{
    int id_CS;
    int id_pipe;
};

string nameoffile();

unordered_map<int, int> visitedCS(unordered_map<int, vector<pairofCS>>& g);

unordered_map<int, bool> usedCS(unordered_map<int, vector<pairofCS>>& g);

void fillinggraph(unordered_map<int, vector<pairofCS>>& graph, unordered_map<int, CS>& CSgroup, unordered_map<int, Pipe>& pipegroup, int indexpipe, int indexks1, int indexks2);

void displayofnetwork(unordered_map<int, vector<pairofCS>>& graph, unordered_map<int, CS>& CSgroup, unordered_map<int, Pipe>& pipegroup);

void depth_first_search(int v, unordered_map<int, vector<pairofCS>>& g, unordered_map<int, bool>& count, vector<int>& answer);

bool depth_first_search_for_cycle(int v, unordered_map<int, vector<pairofCS>>& g, unordered_map<int, int>& cl, int& cycle_st);

void topologicalsort(unordered_map<int, vector<pairofCS>>& g, unordered_map<int, bool>& count, vector<int>& answer);

bool searchforcycle(unordered_map<int, vector<pairofCS>>& g);

void downloadtofile(unordered_map<int, vector<pairofCS>> g);

void unloadfromfile(unordered_map<int, vector<pairofCS>>& g);

void removeofconnection(unordered_map<int, vector<pairofCS>>& k, unordered_map<int, CS> CSgroup, unordered_map<int, Pipe>& pipegroup);

bool verificationofdelete(unordered_map<int, vector<pairofCS>>& k, unordered_map<int, CS>& CSgroup, unordered_map<int, Pipe>& pipegroup, int& idCS);






