//
// Created by Marc Verges on 19/11/23.
//
#ifndef GRAF_LIST
#define GRAF_LIST
#include <algorithm>
#include <list>
#include <vector>
#include <string>
#include <cstdio>
#include <iostream>
using namespace std;

class Graf
{
public:
    Graf(bool dirigit);
    Graf(const vector<string>& nodes, const vector<vector<int>>& parellesNodes, bool dirigit);
    Graf(const vector<string>& nodes, const vector<vector<int>>& parellesNodes, const vector<int>& pesos, bool dirigit);
    ~Graf();
    int getNumNodes() { return m_numNodes; }

    void inserirAresta(int posNode1, int posNode2);
    void inserirAresta(int posNode1, int posNode2, int pes);
    void eliminarAresta(int posNode1, int posNode2);

    void afegirNode(const string& node);
    void eliminarNode(const string& node);

    vector<vector<string>> cicles();
    int grauOutNode(string node);
    int grauInNode(string node);

    //funcions extra (es necesiten per el funcionament)
    bool esVeiString(string node1, string node2);
    bool esVeiInt(int i_node, int i_vei);
    bool obtenirIndex(string node, int& index);
    vector<string> cicles_node(vector<string>& in);
    void afCamin(string node1, string node2, vector<list<string>>& camins,
                       list<string> cami, vector<bool> visitats);
    void caminsresp(string node1, string node2, vector<list<string>>& camins);

    void mostra();

private:
    //Aqui a string podem posar TNode per tenir nodes de qualsevol tipus
    vector<list<pair<int,int>>> m_veins;
    vector<string> m_nodes;
    int m_numNodes;
    int m_numArestes;
    bool m_dirigit;
};

#endif