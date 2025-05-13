#include <iostream>
#include <stdlib.h>
#include <cstdio>
#include <vector>
#include<string>
#include "graf.h"

using namespace std;

bool comparaTasques(vector<string>& resultatEsperat, vector<string>& resultatObtingut)
{

    bool iguals = (resultatEsperat.size() == resultatObtingut.size());
    size_t i = 0;
    while (iguals && (i < resultatEsperat.size()))
    {
        size_t j = 0;
        iguals = false;
        while (!iguals && (j < resultatObtingut.size()))
        {
            if (resultatEsperat[i] == resultatObtingut[j])
                iguals = true;
            else
                j++;
        }
        i++;
    }
    return iguals;
}

int main()
{
    float grade = 0.0;
    bool valid = true;

    cout << endl << endl;
    cout << "Comment :=>>            Iniciant test dels exercicis sessio 15                 " << endl;
    cout << "Comment :=>> ==================================================================" << endl;
    cout << "Comment :=>> ==================================================================" << endl;

    size_t numNodes;

    vector<string> nomsNodes;
    vector<vector<size_t>> arestes;
    vector<int> pesos;
    vector<string> recorregut;
    queue<string> recorregutBFS;

    /**************************************/
    // GRAF DE TASQUES
    /**************************************/

    numNodes= 11;
    nomsNodes.resize(numNodes);
    nomsNodes = {"Tasca 1","Tasca 2","Tasca 3","Tasca 4","Tasca 5","Tasca 6","Tasca 7","Tasca 8","Tasca 9","Tasca 10","Tasca 11"};

    arestes = { {0,1},{0,2},{0,3},{2,1},{2,3},{1,4},{1,5},{3,5},{3,6},{5,4},{5,6},{4,7},{4,8},{6,8},{6,9},{7,8},
                {8,9},{7,10},{8,10},{9,10} };

    pesos = {5,5,5,7,7,10,10,4,4,6,6,3,3,9,9,1,8,2,8,4}; //20 pesos

    Graf gTasquesDirigit(nomsNodes, arestes,true);
    gTasquesDirigit.mostra();

    cout << "Comment :=>> =====================================================================" << endl;
    cout << "Comment :=>> Graf de tasques dirigit creat                                        " << endl;
    cout << "Comment :=>> =====================================================================" << endl;

    // DFS - Pila
    cout << "Comment :=>> =======================================================================" << endl;
    cout << "Comment :=>> Mostra graf simetric no ponderat DFS utilitzant Pila a partir de Tasca 1             " << endl;
    cout << "Comment :=>> ======================================================================" << endl;
    recorregut.clear();
    gTasquesDirigit.DFS("Tasca 1", recorregut, false);
    vector<string> resultatObtingutDFSPila;
    for (size_t i = 0; i < recorregut.size(); i++) {
        std::cout << recorregut[i] << " --> ";
        resultatObtingutDFSPila.push_back(recorregut[i]);
    }

    //DFS - Recursivitat
    cout << "Comment :=>> ================================================================================" << endl;
    cout << "Comment :=>> Mostra graf simetric no ponderat DFS utilitzant Recursivitat a partir de Tasca 1             " << endl;
    cout << "Comment :=>> ================================================================================" << endl;
    recorregut.clear();
    gTasquesDirigit.DFS("Tasca 1", recorregut);
    vector<string> resultatObtingutDFSRec;
    for (size_t i = 0; i < recorregut.size(); i++) {
        std::cout << recorregut[i] << " --> ";
        resultatObtingutDFSRec.push_back(recorregut[i]);
    }

    cout << endl;
    cout << "Comment :=>> " << endl;

    vector<string> resultatEsperat = { "Tasca 1", "Tasca 2", "Tasca 5", "Tasca 8","Tasca 9", "Tasca 10", "Tasca 11",
                                       "Tasca 6", "Tasca 7", "Tasca 3", "Tasca 4"};
    cout << "Comment :=>> Resultat esperat: " << endl;
    for (size_t i = 0; i < resultatEsperat.size(); i++)
    {
        cout << resultatEsperat[i] << " --> " ;
    }

    cout << endl;
    cout << "Comment :=>> ---" << endl;
    if (comparaTasques(resultatEsperat, resultatObtingutDFSPila)) {
        cout << "Comment :=>> CORRECTE DFS PILA" << endl;
        grade += 2;
    }
    else {
        cout << "Comment :=>> ERROR DFS AMB PILA" << endl;
        valid = false;
    }

    if (comparaTasques(resultatEsperat, resultatObtingutDFSRec)) {
        cout << "Comment :=>> CORRECTE DFS RECURSIVITAT" << endl;
        grade += 3;
    }
    else {
        cout << "Comment :=>> ERROR DFS RECURSIU" << endl;
        valid = false;
    }

    /**************************************/
    //GRAF DE CONNEXIONS
    /**************************************/
    numNodes = 13;
    nomsNodes.resize(numNodes);
    nomsNodes = {"Tu", "Marta", "Maria", "Jordi", "Berta", "Aritz", "Nikita", "Joshua", "Marc", "Mar", "Umair", "Neus", "LA persona"};

    arestes = { { 0,2 },{ 0,3 },{0,8}, { 1,2 },{2,3},{2,5},{ 3,4 },{ 4,6 },{4,7},{ 5,6 },{ 7,12 },{ 8,9 },{ 8,10 },{ 10,11 },{ 10,12 },{ 11,12 }};
    Graf gConnexionsNoDirigit(nomsNodes, arestes, false);

    cout << "Comment :=>> =====================================================================" << endl;
    cout << "Comment :=>> Graf de connexions no dirigit creat                                  " << endl;
    cout << "Comment :=>> =====================================================================" << endl;

    //BFS
    cout << "Comment :=>> =====================================================================" << endl;
    cout << "Comment :=>> Mostra graf simetric no ponderat BFS a partir de Tasca Tu            " << endl;
    cout << "Comment :=>> =====================================================================" << endl;

    gConnexionsNoDirigit.BFS("Tu", recorregutBFS);
    vector<string> resultatObtingutBFS;
    while (!recorregutBFS.empty())
    {
        cout << recorregutBFS.front() << " --> ";
        resultatObtingutBFS.push_back(recorregutBFS.front());
        recorregutBFS.pop();
    }
    cout << endl;
    cout << "Comment :=>> " << endl;

    vector<string> resultatEsperatBFS = { "Tu", "Maria", "Jordi", "Marc","Marta", "Aritz", "Berta","Mar", "Umair",
                                          "Nikita", "Joshua", "Neus","LA persona"};
    cout << "Comment :=>> Resultat esperat BFS: " << endl;
    for (size_t i = 0; i < resultatEsperatBFS.size(); i++)
    {
        cout << resultatEsperatBFS[i] << " --> ";
    }

    cout << endl;
    cout << "Comment :=>> ---" << endl;

    if (comparaTasques(resultatEsperatBFS, resultatObtingutBFS)) {
        cout << "Comment :=>> CORRECTE" << endl;
        grade += 5;
    }
    else {
        cout << "Comment :=>> ERROR" << endl;
        valid = false;
    }

    cout << "Comment :=>> =====================================================================" << endl;
    if (valid)
        cout << "Comment :=>> Final del test sense errors" << endl;

    cout << "Comment :=>> " << endl << "Grade :=>> " << grade << endl;

    return 0;
}
