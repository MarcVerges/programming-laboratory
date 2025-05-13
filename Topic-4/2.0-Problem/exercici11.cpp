//
// Created by Marc Verges on 24/10/23.
//
#include <list>
#include <stack>
#include <string>

#include <iostream>
using namespace std;

bool cercaRecursiva(list<int>& l, list<int>::iterator& itL, int valor)
{
    // A MODIFICAR

    if (itL == l.end())
    {
        return false;
    }
    else
    {
        if ((*itL) == valor)
        {
            return true;
        }
        else
        {
            return cercaRecursiva(l,++itL,valor);
        }
    }


    return false;
}

bool cerca(list<int>& l, int valor)
{
    // A MODIFICAR
    list <int> :: iterator iter = l.begin();
    return cercaRecursiva(l,iter,valor);
}


void escriuLlistaInversaRec(list<string>& l, list<string>::iterator& itL, list<string>& lRes)
{
    if (itL != l.end())
    {
        list <string > :: iterator itAct = itL;
        escriuLlistaInversaRec(l,++itL,lRes);
        lRes.push_back(*itAct);
    }
}
void escriuLlistaInversa(list<string>& l, list<string>& lRes)
{
    list <string> :: iterator iter = l.begin();
    escriuLlistaInversaRec(l,iter,lRes);
}

void escriuLlistaInversaIt(list<string>& l, list<string>& lRes)
{
    // A MODIFICAR

    list <string> :: iterator iter = l.begin();

    while (iter != l.end())
    {
        lRes.push_front(*iter);
        iter ++;
    }
}
