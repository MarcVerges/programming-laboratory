//
// Created by Marc Verges on 24/10/23.
//
#ifndef GRAF_H
#define GRAF_H

#include <vector>
#include <string>
#include <cstdio>
using namespace std;

class Graf
{
public:
    Graf();
    Graf(vector<string>& nodes, vector<vector<int>>& matriu_adj, int numNodes);
    ~Graf();

    int getNumNodes() { return m_numNodes; }
    void setNumNodes(int numNodes) { m_numNodes = numNodes; }

    void inserirAresta(int posNode1, int posNode2);
    void eliminarAresta(int posNode1, int posNode2);

    void afegirNode(string node);
    void eliminarNode(string node);
    void mostra();

    vector<vector<int>>& getMatriu() { return m_matriuAdj; }

private:
    vector<string> m_nodes;
    vector<vector<int>> m_matriuAdj;
    int m_numNodes;

};


#endif   // GRAF_H

