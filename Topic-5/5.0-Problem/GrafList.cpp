//
// Created by Marc Verges on 19/11/23.
//
#include "GrafList.h"
#include <iomanip>

struct ComparaPair
{
    ComparaPair(int val) : m_valor(val) {}
    bool operator()(const std::pair<int, int>& elem) const
    {
        return m_valor == elem.first;
    }
    bool operator==(const std::pair<int, int>& elem) const
    {
        return m_valor == elem.first;
    }
private:
    int m_valor;
};

Graf::Graf(bool dirigit)
{
    m_numNodes = 0;
    m_numArestes = 0;
    m_dirigit = dirigit;
}

Graf::Graf(const vector<string>& nodes, const vector<vector<int>>& parNodes, bool dirigit)
{
    m_numNodes = nodes.size();
    m_nodes.resize(m_numNodes);
    m_veins.resize(m_numNodes);
    m_dirigit = dirigit;
    m_numArestes = parNodes.size();

    for (int i = 0; i < m_numNodes; i++)
    {
        m_nodes[i] = nodes[i];
    }
    for (int j = 0; j < parNodes.size(); j++)
    {
        if ((parNodes[j][0] < m_numNodes) && (parNodes[j][1] < m_numNodes) &&
            (parNodes[j][0] >= 0) && (parNodes[j][1]>= 0))
        {
            m_veins[parNodes[j][0]].emplace_back(pair<int,int>(parNodes[j][1],1));
            if (!dirigit)
            {
                m_veins[parNodes[j][1]].emplace_back(pair<int, int>(parNodes[j][0], 1));
            }
        }
    }
}
Graf::Graf(const vector<string>& nodes, const vector<vector<int>>& parNodes, const vector<int>& pesos,bool dirigit)
{
    m_numNodes = nodes.size();
    m_nodes.resize(m_numNodes);
    m_veins.resize(m_numNodes);
    m_dirigit = dirigit;
    m_numArestes = parNodes.size();

    for (int i = 0; i < m_numNodes; i++)
    {
        m_nodes[i] = nodes[i];
    }
    for (int j = 0; j < parNodes.size(); j++)
    {
        if ((parNodes[j][0] < m_numNodes) && (parNodes[j][1] < m_numNodes) &&
            (parNodes[j][0] >= 0) && (parNodes[j][1] >= 0))
        {
            m_veins[parNodes[j][0]].emplace_back(pair<int, int>(parNodes[j][1], pesos[j]));
            if (!dirigit)
            {
                m_veins[parNodes[j][1]].emplace_back(pair<int, int>(parNodes[j][0], pesos[j]));
            }
        }
    }
}
Graf::~Graf()
{
}

void Graf::inserirAresta(int posNode1, int posNode2)
{
    if ((posNode1 < m_numNodes) && (posNode2 < m_numNodes) && (posNode1 >= 0) && (posNode2 >= 0))
    {
        m_veins[posNode1].emplace_back(pair<int,int>(posNode2,1));
        if (!m_dirigit)
        {
            m_veins[posNode2].emplace_back(pair<int, int>(posNode1, 1));
        }
        m_numArestes++;
    }
}

void Graf::inserirAresta(int posNode1, int posNode2, int pes)
{
    if ((posNode1 < m_numNodes) && (posNode2 < m_numNodes)&& (posNode1 >=0) && (posNode2 >= 0))
    {
        m_veins[posNode1].emplace_back(pair<int, int>(posNode2, pes));
        if (!m_dirigit)
        {
            m_veins[posNode2].emplace_back(pair<int, int>(posNode1, pes));
        }
        m_numArestes++;
    }
}


void Graf::eliminarAresta(int posNode1, int posNode2)
{
    list<pair<int, int>>::iterator itAre = find_if(m_veins[posNode1].begin(), m_veins[posNode1].end(),ComparaPair(posNode2));
    if (itAre != m_veins[posNode1].end())
    {
        m_veins[posNode1].erase(itAre);
        m_numArestes--;
    }
    if (!m_dirigit)
    {
        itAre = find_if(m_veins[posNode2].begin(), m_veins[posNode2].end(), ComparaPair(posNode1));
        if (itAre != m_veins[posNode2].end())
        {
            m_veins[posNode2].erase(itAre);
        }
    }
}

void Graf::afegirNode(const string& node)
{
    m_nodes.push_back(node);
    m_numNodes++;
    m_veins.resize(m_numNodes);
}


void Graf::eliminarNode(const string& node)
{
    //busquem la posici� del node a esborrar
    vector<string>::iterator it;

    it = find(m_nodes.begin(), m_nodes.end(), node);
    //mirem si node existeix
    if (it != m_nodes.end())
    {
        //Obtenim index del node
        int nodeIndex = it - m_nodes.begin();

        // eliminem el node del vector de nodes
        m_nodes.erase(it);
        //Eliminem arestes desde el node
        m_veins.erase(m_veins.begin()+ nodeIndex);
        //Eliminem arestes cap al node

        for (int i = 0; i < m_veins.size(); i++)
        {//eliminem cada aresta sense ponderar
            m_veins[i].remove_if(ComparaPair(nodeIndex));
        }
        m_numNodes--;
    }
}

bool Graf::esVeiString(string node1, string node2)
{
    int i;
    int iVei;
    bool ret = false;

    obtenirIndex(node1, i);
    obtenirIndex(node2, iVei);
    for (auto it = m_veins[i].begin(); it != m_veins[i].end() && !ret; it++)
    {
        ret = (*it).first == iVei;
    }

    return ret;
}

bool Graf::esVeiInt(int i_node, int i_vei) {
    bool ret = false;

    for (auto it = m_veins[i_node].begin(); it != m_veins[i_node].end() && !ret; it++)
    {
        ret = ((*it).first == i_vei);
    }

    return ret;
}

bool Graf::obtenirIndex(string node, int& index)
{
    index = 0;
    bool trobat = (m_nodes[index] == node);
    while (!trobat)
    {
        index++;
        trobat = m_nodes[index] == node;
    }
    return trobat;
}

vector<string> Graf::cicles_node(vector<string>& in)
{
    return vector<string>();
}


vector<vector<string>> Graf::cicles()
{
    vector<vector<string>> cicles;
    for (int i = 0; i < m_numNodes; i++)
    {
        for (auto it = m_veins[i].begin(); it != m_veins[i].end(); it++)
        {
            if ((*it).first > i)
            {
                if (!m_dirigit)
                {
                    auto iter = it;
                    iter++;
                    for (; iter != m_veins[i].end(); iter++)
                    {
                        if (esVeiInt((*it).first, (*iter).first))
                            cicles.emplace_back(vector<string>{
                                    m_nodes[i],
                                    m_nodes[(*it).first],
                                    m_nodes[(*iter).first]
                            });
                    }
                }
                else
                {
                    for (auto iter = m_veins[(*it).first].begin(); iter != m_veins[(*it).first].end(); iter++)
                    {
                        if ((*iter).first > i && esVeiInt((*iter).first, i))
                            cicles.emplace_back(vector<string>{
                                    m_nodes[i],
                                    m_nodes[(*it).first],
                                    m_nodes[(*iter).first]
                            });
                    }
                }
            }
        }
    }
    return cicles;
}


int Graf::grauOutNode(string node)
{
    int index;
    obtenirIndex(node, index);
    return m_veins[index].size();
}

int Graf::grauInNode(string node)
{
    int index;
    int grau = 0;

    obtenirIndex(node, index);
    for (auto it = m_veins.begin(); it != m_veins.end(); it++)
    {
        for (auto jt = (*it).begin(); jt != (*it).end(); jt++)
        {
            grau = (*jt).first == index ? grau+1 : grau;
        }
    }

    return grau;
}

void Graf::afCamin(string node1, string node2, vector<list<string>>& camins,
                   list<string> cami, vector<bool> visitats)
{
    int i;
    obtenirIndex(node1, i);
    cami.push_back(node1);
    visitats[i] = true;

    if (node1 != node2)
    {
        for (auto it = m_veins[i].begin(); it != m_veins[i].end(); it++)
        {
            //crida recursiva

            if (!visitats[(*it).first])
            {
                afCamin(m_nodes[(*it).first], node2, camins, cami, visitats);
            }
        }
    }
    else
    {
        camins.push_back(cami);
    }
}

void Graf::caminsresp(string node1, string node2, vector<list<string>>& camins)
{
    int i;
    list<string> cami;
    vector<bool> visitats;

    obtenirIndex(node1, i);
    for (auto it = m_veins[i].begin(); it != m_veins[i].end(); it++)
    {
        //eliminem dades prexistents
        visitats.resize(0);
        cami.clear();

        visitats.resize(m_numNodes);
        visitats[i] = true;
        cami.push_back(node1);
        afCamin(m_nodes[(*it).first], node2, camins, cami, visitats);
    }
}

void Graf::mostra()
{
    // imprimim el nom dels v�rtexs
    cout << "Graf: NUMNODES: " << m_numNodes << " ; NUMARESTES: " << m_numArestes << ":" << endl;
    cout << "=====NODES=====" << endl;
    for (int i = 0; i < m_numNodes; i++)
    {
        int espai = 20;
        if (i == 0) espai--;
        for (int dig = i; dig > 0; dig /= 10)
        {
            espai -= 1;
        }
        cout << i << ":" << setw(espai) << m_nodes[i] << " ";
        for (list<pair<int,int>>::iterator it = m_veins[i].begin(); it != m_veins[i].end(); it++)
        {
            cout << "-----> ( " << m_nodes[(*it).first] <<"," << (*it).second << " )  ";
        }
        cout << endl;
    }
}

