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
    //busquem la posici� del node a esborrar
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
    // imprimim el nom dels v�rtexs
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

void Graf::DFSRec(int pos, vector<string>& recorregut, vector<bool>& visitat)
{
    visitat[pos] = true;
    recorregut.push_back(m_nodes[pos]);

    // Recur for all the vertices adjacent
    // to this vertex
    for (int col=0; col<m_numNodes;col++)
        if ((m_matriuAdj[pos][col]!=0) &&(!visitat[col]))
            DFSRec(col, recorregut, visitat);
}


void Graf::DFSRec(int pos, vector<string>& recorregut, vector<bool>& visitat, stack<string>& ordre)
{
    visitat[pos] = true;
    recorregut.push_back(m_nodes[pos]);

    // Recur for all the vertices adjacent
    // to this vertex
    for (int col=0; col<m_numNodes;col++)
        if ((m_matriuAdj[pos][col]!=0) &&(!visitat[col]))
            DFSRec(col, recorregut, visitat, ordre);

    ordre.push(m_nodes[pos]);
}


void Graf::DFS(const string& nodeInicial, vector<string>& recorregut)
{
    vector<string>::iterator itNode = find(m_nodes.begin(), m_nodes.end(), nodeInicial);
    vector<bool> visitat;
    visitat.resize(m_numNodes, false);

    if (itNode != m_nodes.end())
    {
        int pos = distance(m_nodes.begin(), itNode);
        DFSRec(pos, recorregut, visitat);
    }
}

void Graf::DFS(const string& nodeInicial, vector<string>& recorregut, stack<string>& ordre)
{
    vector<string>::iterator itNode = find(m_nodes.begin(), m_nodes.end(), nodeInicial);
    vector<bool> visitat;
    visitat.resize(m_numNodes, false);

    if (itNode != m_nodes.end())
    {
        int pos = distance(m_nodes.begin(), itNode);
        DFSRec(pos, recorregut, visitat, ordre);
    }

}


//no avaluable
void Graf::Tarjan(std::vector<std::vector<string>>& components) {
    // Exemple de sortida 'components': [[A,B,C], [D,E]]
    // TODO
}




void Graf::Kosaraju(std::vector<std::vector<string>>& components)
{
    vector<string> cami;
    stack<string> order;
    const string nInic = m_nodes[0];
    this ->DFS(nInic,cami, order);
    vector<bool> part;

    part.resize(m_numNodes, false);
    Graf mNova = (*this);

    for (int i = 0; i < m_numNodes; i++)
    {
        for (int j = 0; j < m_numNodes; j++)
        {
            mNova.m_matriuAdj[i][j] = m_matriuAdj[j][i];
        }
    }

    while(!order.empty())
    {
        string node = order.top();
        order.pop();
        if (!part [distance(m_nodes.begin(), find(m_nodes.begin(), m_nodes.end(),node))])
        {
             vector<string> aux;
             vector<string> cami2;
             mNova.DFS(node, aux);

             for (int i = 0; i < aux.size(); i++)
             {
                if (!part[distance(m_nodes.begin(), find(m_nodes.begin(),m_nodes.end(), aux[i]))])
                {
                     cami2.push_back(aux[i]);
                }
                part[distance(m_nodes.begin(), find(m_nodes.begin(),m_nodes.end(), aux[i]))] = true;
             }
             components.push_back(cami2);
        }
    }
}
