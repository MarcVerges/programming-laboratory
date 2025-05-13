//
// Created by Marc Verges on 9/11/23.
//
#include "graf.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;

const int Graf::DISTMAX{ numeric_limits<int>::max() };

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
    m_numArestes = parellesNodes.size();
    m_dirigit = dirigit;
    crearMatriu(parellesNodes);
}

Graf::Graf(const vector<string>& nodes, const vector<vector<size_t>>& parellesNodes, const vector<int>& pesos, bool dirigit)
{
    m_nodes = nodes;
    m_numNodes = m_nodes.size();
    m_numArestes = parellesNodes.size();
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

void Graf::crearMatriu(const vector<vector<size_t>>& parelles,const vector<int>& pesos)
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
    // imprimim el nom dels vèrtexs
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


size_t Graf::minDistance(const vector<int>& dist, const vector<bool>& visitat) const
{
    // Initialize min value
    int min = DISTMAX;
    size_t minIndex = -1;


    for (int i = 0; i < m_numNodes; i++)
    {
        if (!visitat[i] && dist[i] <= min)
        {
            min = dist[i];
            minIndex = i;
        }
    }

    return minIndex;
}

void Graf::dijkstra(size_t node, vector<int>& dist)
{
    dist.resize(m_numNodes, DISTMAX);
    vector<bool> visitat;
    visitat.resize(m_numNodes, false);
    dist[node] = 0;

    for (int i = 0; i < m_numNodes-1; i++)
    {
        int posOb = minDistance(dist, visitat);

        visitat[posOb] = true;
        for (int posVei = 0; posVei < m_numNodes; posVei++)
        {
            if (m_matriuAdj[posOb][posVei]!=0)
            {
                if (!visitat[posVei])
                {
                    if (dist[posOb]+m_matriuAdj[posOb][posVei]<dist[posVei])
                    {
                        dist[posVei] = dist[posOb] + m_matriuAdj[posOb][posVei];
                    }
                }
            }
        }
    }
}

void Graf::dijkstra(size_t node,vector<int>& dist,vector<size_t>& anterior) //paràmetre nou exercici 2
{

    dist.resize(m_numNodes, DISTMAX);
    vector<bool> visitat;
    visitat.resize(m_numNodes, false);
    anterior.resize(m_numNodes, -1);
    dist[node] = 0;
    anterior[node]=node;
    for (int count = 0; count < m_numNodes-1; count++)
    {
        int posVeiAct = minDistance(dist, visitat);


        visitat[posVeiAct] = true;
        for (int posOb = 0; posOb < m_numNodes; posOb++)
        {
            if (m_matriuAdj[posVeiAct][posOb]!=0)
            {
                if (!visitat[posOb])
                {
                    if (dist[posVeiAct]+m_matriuAdj[posVeiAct][posOb]<dist[posOb])
                    {
                        dist[posOb] = dist[posVeiAct] + m_matriuAdj[posVeiAct][posOb];
                        anterior[posOb] = posVeiAct;
                    }
                }

            }
        }
    }
}

void Graf::camiMesCurt(const string& node1, const string& node2, stack<string>& cami)
{
    vector<string>::iterator it1 = find(m_nodes.begin(), m_nodes.end(), node1);
    vector<string>::iterator it2 = find(m_nodes.begin(), m_nodes.end(), node2);

    if ((it1 != m_nodes.end()) && (it2 != m_nodes.end()))
    {
        int pos1 = distance(m_nodes.begin(), it1);
        int pos2 = distance(m_nodes.begin(), it2);
        vector<size_t> past;
        vector<int> vDist;

        dijkstra(pos1, vDist, past);
        int it = pos2;
        cami.push(m_nodes[pos2]);

        while (it != pos1)
        {
            cami.push(m_nodes[past[it]]);
            it = past[it];
        }
    }

}

void Graf::dijkstraModif(size_t node1, size_t node2, vector<int>& dist, vector<size_t>& anterior)
{
    dist.resize(m_numNodes, DISTMAX);
    vector<bool> visitat;
    visitat.resize(m_numNodes, false);
    anterior.resize(m_numNodes, -1);
    dist[node1] = 0;
    anterior[node1] = node1;
    for (int i = 0; i < m_numNodes-1; i++)
    {
        int veiAct = minDistance(dist, visitat);
        visitat[veiAct] = true;

        if (veiAct==node2) return;
        for (int posVei = 0; posVei < m_numNodes; posVei++)
        {
            if (m_matriuAdj[veiAct][posVei]!=0)
            {
                if (!visitat[posVei])
                {
                    if (dist[veiAct]+m_matriuAdj[veiAct][posVei]<dist[posVei])
                    {
                        dist[posVei] = dist[veiAct] + m_matriuAdj[veiAct][posVei];
                        anterior[posVei] = veiAct;
                    }
                }
            }
        }
    }
}
