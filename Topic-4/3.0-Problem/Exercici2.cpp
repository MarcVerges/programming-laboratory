//
// Created by Marc Verges on 9/11/23.
//
#include <vector>

using namespace std;

int posMin(vector<int> v, int indexInici, int indexFinal)
{
    for (int i = indexInici; i <= indexFinal; i++)
    {
        if (v[i] < v[indexInici])
        {
            v[indexInici] = v[i];
            indexInici = i;
        }
    }
    return indexInici;
}

void ordenaArray(vector<int>& v, int indexInici, int indexFinal)
{
    if (indexInici < indexFinal)
    {
        int posMinim = posMin(v,indexInici, indexFinal);

        int inv = v[indexInici];
        v[indexInici] = v[posMinim];
        v[posMinim] = inv;
        ordenaArray(v, indexInici + 1, indexFinal);
    }
}




