//
// Created by Marc Verges on 24/10/23.
//
#include <iostream>
#include <stdlib.h>
#include <cstdio>
#include <vector>
#include "graf.h"

using namespace std;


int main()
{
    float grade = 0.0;
    int numNodes = 12;
    vector<string> noms_nodes;
    noms_nodes.resize(numNodes);
    noms_nodes = { "pg. principal","escola","estudis","info. academica","e. graus","grau e. inf.","calendari","pla estudis","guies docents","professorat","horaris","horaris inf."};

    vector<vector<int>> matAdj{
            { 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0 },
            { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
            { 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
            { 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0 },
            { 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0 },
            { 1, 0, 0, 0, 1, 0, 1, 1, 0, 0, 1, 0 },
            { 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0 },
            { 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0 },
            { 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0 },
            { 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1 },
            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
    };


    Graf g(noms_nodes,matAdj,numNodes);

    g.mostra();

    cout << "Comment :=>> inserim una aresta entre els nodes 0 i 8" << endl;
    g.inserirAresta(0, 8);
    g.mostra();
    vector<vector<int>>& matriu1 = g.getMatriu();
    if (matriu1[0][8] == 1) {
        grade += 5;
    }

    cout << "Comment :=>> eliminem una aresta entre els nodes 0 i 1" << endl;
    g.eliminarAresta(0, 1);
    g.mostra();

    if (matriu1[0][1] == 0) {
        grade += 5;
    }

    cout << "Comment :=>> " << endl << "Grade :=>> " << grade << endl;
}
