//
// Created by Marc Verges on 24/10/23.
//
#include "graf.h"
#include <iostream>
#include <iomanip>
using namespace std;


Graf::Graf()
{
    m_numNodes = 0;
}

Graf::Graf(vector<string>& nodes, vector<vector<int>>& matriu, int numNodes)
{
    m_numNodes = numNodes;

    m_nodes = nodes;
    m_matriuAdj = matriu;

}

Graf::~Graf()
{
}

void Graf::inserirAresta(int posNode1, int posNode2)
{
   m_matriuAdj[posNode1][posNode2] = 1;

}

void Graf::eliminarAresta(int posNode1, int posNode2)
{
    m_matriuAdj[posNode1][posNode2] = 0;
}


void Graf::mostra()
{

    // imprimim el nom dels vèrtexs
    for (int j = 0; j < m_numNodes; j++)
    {
        cout << "Comment :=>> " << m_nodes[j] << endl;
    }
    cout << "Comment :=>> " << endl;

    for (int i = 0; i < m_numNodes; i++)
    {
        cout << "Comment :=>> " << m_nodes[i] << endl;
        for (int j = 0; j < m_numNodes; j++)
        {
            cout << "Comment :=>>     " << m_matriuAdj[i][j] << endl;
        }
        cout << "Comment :=>> " << endl;
    }
}
