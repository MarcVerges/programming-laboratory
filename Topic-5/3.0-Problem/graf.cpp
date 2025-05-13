//
// Created by Marc Verges on 8/11/23.
//
#include "graf.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;


Graf::Graf()
{
    m_numNodes = 0;
    m_numArestes = 0;
    m_dirigit = false;
}

Graf::Graf(const vector<string>& nodes, const vector<vector<size_t>>& parellesNodes, bool dirigit)
{
    m_nodes = nodes;
    m_numNodes = m_nodes.size();
    m_dirigit = dirigit;
    crearMatriu(parellesNodes);
}

Graf::Graf(const vector<string>& nodes, const vector<vector<size_t>>& parellesNodes, const vector<int>& pesos, bool dirigit)
{
    m_nodes = nodes;
    m_numNodes = m_nodes.size();
    m_dirigit = dirigit;
    crearMatriu(parellesNodes, pesos);
}


Graf::~Graf()
{
}

void Graf::crearMatriu(const vector<vector<size_t>>& parelles)
{
    m_matriuAdj.resize(m_numNodes);
    for (size_t i=0; i<m_numNodes;i++)
    {
        m_matriuAdj[i].resize(m_numNodes,0);
    }

    for (size_t i = 0; i < parelles.size(); i++)
    {
        m_matriuAdj[parelles[i][0]][parelles[i][1]] = 1;
        if (!m_dirigit)
            m_matriuAdj[parelles[i][1]][parelles[i][0]] = 1;
    }
}

void Graf::crearMatriu(const vector<vector<size_t>>& parelles, const vector<int>& pesos)
{
    m_matriuAdj.resize(m_numNodes);
    for (auto &it : m_matriuAdj)
    {
        it.resize(m_numNodes);
    }

    for (size_t i = 0; i < parelles.size(); i++)
    {
        m_matriuAdj[parelles[i][0]][parelles[i][1]] = pesos[i];
        if (!m_dirigit)
            m_matriuAdj[parelles[i][1]][parelles[i][0]] = pesos[i];
    }
}

void Graf::mostra()
{
    int mida_c = 4;
    // imprimim el nom dels v�rtexs
    cout << setw(mida_c) << " ";
    for (size_t j = 0; j < m_numNodes; j++)
    {

        cout << setw(mida_c) << m_nodes[j] << " ";
    }
    cout << endl;

    for (size_t i = 0; i < m_numNodes; i++)
    {
        cout << setw(10) << m_nodes[i] << " ";
        for (size_t j = 0; j < m_numNodes; j++)
        {
            cout << setw(mida_c) << m_matriuAdj[i][j] << " ";
        }
        cout << endl;
    }
}


//Exercici 1
void Graf::DFSPila(size_t posInicial, vector<string>& recorregut)
{
    stack<size_t> pila;
    vector<bool> visitat(m_numNodes, false);
    pila.push(posInicial);

    while (!pila.empty()) {
        size_t actual = pila.top();
        pila.pop();

        if (!visitat[actual]) {
            recorregut.push_back(m_nodes[actual]);
            visitat[actual] = true;

            for (size_t i = 0; i < m_numNodes; ++i) {
                if (m_matriuAdj[actual][i] == 1 && !visitat[i]) {
                    pila.push(i);
                }
            }
        }
    }
}


//Exercici 2
void Graf::DFSRec(size_t pos, vector<string>& recorregut, vector<bool>& visitat)
{
    recorregut.push_back(m_nodes[pos]);
    visitat[pos] = true;

    for (size_t i = 0; i < m_numNodes; ++i) {
        if (m_matriuAdj[pos][i] == 1 && !visitat[i]) {
            DFSRec(i, recorregut, visitat);
        }
    }
}

//Exercici 1 - 2
void Graf::DFS(const string& nodeInicial, vector<string>& recorregut, bool utilitza_recursivitat)
{
    // OMPLIR
    size_t posicioInicial = -1;

    for (size_t i = 0; i < m_numNodes; ++i) {
        if (m_nodes[i] == nodeInicial) {
            posicioInicial = i;
            break;
        }
    }

    // FER: Buscar posicioInicial

    if (posicioInicial == -1) {
        throw "No existeix el node " + nodeInicial + " dins del graf.";
    }

    if (!utilitza_recursivitat) {
        DFSPila(posicioInicial, recorregut);
    }
    else {
        vector<bool> visitat;
        visitat.resize(m_numNodes, false);
        DFSRec(posicioInicial, recorregut, visitat);
    }
}

//Exercici 2
void Graf::BFS(const string& nodeInicial, queue<string>& recorregut)
{
    size_t posicioInicial = -1;

    for (size_t i = 0; i < m_numNodes; ++i) {
        if (m_nodes[i] == nodeInicial) {
            posicioInicial = i;
            break;
        }
    }

    if (posicioInicial == -1) {
        throw "No existeix el node " + nodeInicial + " dins del graf.";
    }

    vector<bool> visitat(m_numNodes, false);
    queue<size_t> cua;
    cua.push(posicioInicial);

    while (!cua.empty()) {
        size_t actual = cua.front();
        cua.pop();

        if (!visitat[actual]) {
            recorregut.push(m_nodes[actual]);
            visitat[actual] = true;

            for (size_t i = 0; i < m_numNodes; ++i) {
                if (m_matriuAdj[actual][i] == 1 && !visitat[i]) {
                    cua.push(i);
                }
            }
        }
    }
}

