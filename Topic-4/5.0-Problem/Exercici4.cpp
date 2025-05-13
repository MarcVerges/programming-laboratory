//
// Created by Marc Verges on 10/11/23.
//

#include <iostream>
#include <vector>

using namespace std;

int partlist(vector<int>& array, int indexInici, int indexFinal)
{
    int part = array[indexInici];
    int esq = indexInici, dre = indexFinal;
    int aux;

    while(esq < dre)
    {
        while(array[dre] > part)
        {
            dre--;
        }
        while((esq < dre) && (array[esq] <= part))
        {
            esq++;
        }
        if (esq < dre)
        {
            aux = array[esq];
            array[esq] = array[dre];
            array[dre] = aux;
        }
    }

    aux = array[dre];
    array[dre] = array[indexInici];
    array[indexInici] = aux;

    return dre;
}

void quicksort(vector<int>& v, int indexInici, int indexFinal)
{
    if (indexInici < indexFinal)
    {
        int pivot = partlist(v, indexInici, indexFinal);
        quicksort(v, indexInici, pivot - 1);
        quicksort(v, pivot + 1, indexFinal);

    }
}