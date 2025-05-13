//
// Created by Marc Verges on 19/11/23.
//
#include "graf.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;


Graf::Graf()
{
    m_numNodes = 0;
}

Graf::Graf(const vector<string>& nodes, const vector<vector<int>>& parellesNodes, bool dirigit)
{
    m_nodes = nodes;
    m_numNodes = m_nodes.size();
    m_dirigit = dirigit;
    crearMatriu(parellesNodes);
}

Graf::Graf(const vector<string>& nodes, const vector<vector<int>>& parellesNodes, const vector<int>& pesos, bool dirigit)
{
    m_nodes = nodes;
    m_numNodes = m_nodes.size();
    m_dirigit = dirigit;
    crearMatriu(parellesNodes, pesos);
}


Graf::~Graf()
{
}

void Graf::crearMatriu(const vector<vector<int>>& parelles)
{
    m_matriuAdj.resize(m_numNodes);
    for (int i=0; i<m_numNodes;i++)
    {
        m_matriuAdj[i].resize(m_numNodes,0);
    }

    for (int i = 0; i < parelles.size(); i++)
    {
        m_matriuAdj[parelles[i][0]][parelles[i][1]] = 1;
        if (!m_dirigit)
            m_matriuAdj[parelles[i][1]][parelles[i][0]] = 1;
    }
}

void Graf::crearMatriu(const vector<vector<int>>& parelles, const vector<int>& pesos)
{
    m_matriuAdj.resize(m_numNodes);
    for (auto &it : m_matriuAdj)
    {
        it.resize(m_numNodes);
    }

    for (int i = 0; i < parelles.size(); i++)
    {
        m_matriuAdj[parelles[i][0]][parelles[i][1]] = pesos[i];
        if (!m_dirigit)
            m_matriuAdj[parelles[i][1]][parelles[i][0]] = pesos[i];
    }
}

void Graf::inserirAresta(int posNode1, int posNode2)
{
    m_matriuAdj[posNode1][posNode2] = 1;
    if (!m_dirigit)
        m_matriuAdj[posNode2][posNode1] = 1;
}

void Graf::inserirAresta(int posNode1, int posNode2, int pes)
{
    m_matriuAdj[posNode1][posNode2] = pes;
    if (!m_dirigit)
        m_matriuAdj[posNode2][posNode1] = pes;
}


void Graf::eliminarAresta(int posNode1, int posNode2)
{
    m_matriuAdj[posNode1][posNode2] = 0;
    if (!m_dirigit)
        m_matriuAdj[posNode2][posNode1] = 0;
}

void Graf::afegirNode(const string& node)
{
    //m_nodes.resize(m_numNodes);
    m_nodes.push_back(node);

    // add a row
    m_matriuAdj.push_back(std::vector<int>(m_numNodes));

    m_numNodes++;

    //m_matriuAdj.resize(m_numNodes);
    for (int i = 0; i < m_numNodes; i++) m_matriuAdj[i].push_back(0);
}

void Graf::eliminarNode(const string& node)
{
    //busquem la posicio del node a esborrar
    vector<string>::iterator it;

    it = find(m_nodes.begin(), m_nodes.end(), node);

    //eliminem el node del vector de nodes i de la matriu d'adjacencia
    if (it != m_nodes.end())
    {
        int pos = distance(m_nodes.begin(), it);
        // eliminem el node del vector de nodes
        //m_nodes.erase(m_nodes.begin() + pos);
        m_nodes.erase(it);

        // eliminem la fila i la columna de la matriu d'adjacencia corresponents a aquest node
        m_matriuAdj.erase(m_matriuAdj.begin() + pos);

        for (int i = 0; i < m_numNodes; i++)
        {
            m_matriuAdj[i].erase(m_matriuAdj[i].begin() + pos);
        }
        m_numNodes--;
    }
}

void Graf::mostra()
{
    int mida_c = 4;
    // imprimim el nom dels vertexs
    cout << setw(mida_c) << " ";
    for (int j = 0; j < m_numNodes; j++)
    {

        cout << setw(mida_c) << m_nodes[j] << " ";
    }
    cout << endl;

    for (int i = 0; i < m_numNodes; i++)
    {
        cout << setw(10) << m_nodes[i] << " ";
        for (int j = 0; j < m_numNodes; j++)
        {
            cout << setw(mida_c) << m_matriuAdj[i][j] << " ";
        }
        cout << endl;
    }
}


void Graf::BFS(const string& nodeInicial, queue<string>& recorregut)
{
    vector<string>::iterator itNode = find(m_nodes.begin(), m_nodes.end(), nodeInicial);
    vector<bool> visitat;
    visitat.resize(m_numNodes, false);
    queue<int> pendents;

    if (itNode != m_nodes.end())
    {
        int pos = distance(m_nodes.begin(), itNode);
        visitat[pos] = true;
        pendents.push(pos);

        while (!pendents.empty())
        {
            int nodeActual = pendents.front();
            pendents.pop();
            recorregut.push(m_nodes[nodeActual]);

            // posem a la cua tots els nodes adjacents a nodeActual no visitats
            for (int col=0; col<m_numNodes; col++)
            {
                if((m_matriuAdj[nodeActual][col]!=0)&& (!visitat[col]))
                {
                    pendents.push(col);
                    visitat[col] = true;
                }
            }
        }
    }
}


void Graf::BFS(const string& nodeInicial, const string& nodeFinal, queue<string>& recorregut, stack<string>& cami)
{
    //declarem varaibles

    vector<string> :: iterator it = find (m_nodes.begin(), m_nodes.end(),nodeInicial);
    vector<string>::iterator it2= find(m_nodes.begin(), m_nodes.end(), nodeFinal);
    vector<bool> visit;
    vector<int> original;
    queue<int> pend;

    visit.resize(m_numNodes, false);
    original.resize(m_numNodes, -1);


    if (it != m_nodes.end() && it2 != m_nodes.end())
    {
        int pos = distance(m_nodes.begin(), it);
        visit[pos] = true;
        pend.push(pos);
        while (!pend.empty())
        {
            int nodeActual = pend.front();
            pend.pop();
            recorregut.push(m_nodes[nodeActual]);

            if (m_nodes[nodeActual] == nodeFinal)
            {
                break;
            }

            for (int col = 0; col < m_numNodes; col++)
            {
                if ((m_matriuAdj[nodeActual][col] != 0) && (!visit[col]))
                {
                    pend.push(col);
                    visit[col] = true;
                    original[col] = nodeActual;
                }
            }
        }

        int desti = distance(m_nodes.begin(), it2);
        int i = original[desti];

        if (i != -1)
        {
            cami.push(m_nodes[desti]);
            while (i != -1)
            {
                cami.push(m_nodes[i]);
                i = original[i];
            }
        }
    }
}


void Graf::BFS(const string& nodeInicial, int distancia, queue<string>& recorregut)
{
    vector<bool> visit;
    queue<int> pen;
    vector<string> :: iterator it = find (m_nodes.begin(),m_nodes.end(),nodeInicial);


    visit.resize(m_numNodes, false);

    if (it != m_nodes.end())
    {
        int pos = distance(m_nodes.begin(), it);
        visit[pos] = true; pen.push(pos);

        while (!pen.empty())
        {
            int nodeActual = pen.front();
            pen.pop();
            recorregut.push(m_nodes[nodeActual]);

            for (int col=0; col<m_numNodes; col++)
            {
                if((m_matriuAdj[nodeActual][col]!=0)&& (!visit[col]))
                {
                    pen.push(col);
                    visit[col] = true;
                }
            }
        }
    }
}



int Graf::BFS(const string& nodeInicial, const string& nodeFinal, queue<string>& recorregut)
{
    vector<string>::iterator it = find(m_nodes.begin(), m_nodes.end(), nodeInicial);
    vector<bool> visit;
    vector<int> pasos;
    queue<int> pendents;

    visit.resize(m_numNodes, false);
    pasos.resize(m_numNodes, 0);

    if (it != m_nodes.end())
    {

        int pos = distance(m_nodes.begin(), it);

        visit[pos] = true;
        pasos[pos] = 0;
        pendents.push(pos);

        while (!pendents.empty())
        {
            int actu = pendents.front();
            pendents.pop();
            recorregut.push(m_nodes[actu]);
            if (m_nodes[actu] == nodeFinal)
                return pasos[actu];

            for (int col = 0; col < m_numNodes; col++)
            {
                if ((m_matriuAdj[actu][col] != 0) && (!visit[col]))
                {
                    pendents.push(col);
                    visit[col] = true;
                    pasos[col] = pasos[actu] + 1;
                }
            }
        }
    }
    return -1;
}

