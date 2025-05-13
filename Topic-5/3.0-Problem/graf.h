//
// Created by Marc Verges on 8/11/23.
//
#ifndef GRAF_H
#define GRAF_H
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <string>
#include <cstdio>
using namespace std;

class Graf
{
public:
    Graf();
    Graf(const vector<string>& nodes, const vector<vector<size_t>>& parellesNodes, bool dirigit);
    Graf(const vector<string>& nodes, const vector<vector<size_t>>& parellesNodes, const vector<int>& pesos, bool dirigit);
    ~Graf();

    size_t getNumNodes() { return m_numNodes; }

    void mostra();
    void BFS(const string& nodeInicial, queue<string>& recorregut);
    void DFS(const string& nodeInicial, vector<string>& recorregut, bool utilitza_recursivitat = true);

    void DFSPila(size_t posInicial, vector<string>& recorregut);

private:
    vector<string> m_nodes;
    vector<vector<int>> m_matriuAdj;
    size_t m_numNodes;
    size_t m_numArestes;
    bool m_dirigit;

    void crearMatriu(const vector<vector<size_t>>& parelles);
    void crearMatriu(const vector<vector<size_t>>& parelles, const vector<int>& pesos);
    void DFSRec(size_t pos, vector<string>& recorregut, vector<bool>& visitat);

};

#endif

