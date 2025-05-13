//
// Created by Marc Verges on 10/11/23.
//
#include <list>
using namespace std;


int MaxElsRec(list<int>::iterator it, list<int>::iterator end)
{
    if(it==end)
    {
        return 0;
    }
    else
    {
        int max=MaxElsRec(next(it), end);
        return std::max(*it, max);
    }
}

int MaxElementsLlista(list<int> &l)
{
    if(!l.empty())
    {
        return MaxElsRec(l.begin(), l.end());
    }
    else
    {
        return 0;
    }
}







