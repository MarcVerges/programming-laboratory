//
// Created by Marc Verges on 19/10/23.
//
#pragma once

#include <iostream>
using namespace std;


// EXERCICI 1 ////////////////////////////////////////////////////////////////

float potenciaRec(float x, int n)
{
    float ret;

    if (n == 0)
    {
        ret = 1;
    }
    else
    {
        ret = (x * potenciaRec(x,n-1));
    }

    return ret;
}

float potencia(float x, int n)
{
    if (n >= 0)
    {
        return potenciaRec(x,n);
    }
    else
    {
        return potenciaRec(1/x,- n);
    }
}

// EXERCICI 2 ////////////////////////////////////////////////////////////////

int QueFa(int v[], int n)
{
    if (n == 0)
    {
        cout << "RESULTAT queFa n= " << n << " Retorna = " << 0 << endl;
        return 0;
    }

    cout << "RESULTAT queFa n= " << n << " Retorna = QueFa ( ";
    for (int i = 0; i < n; i++)
        cout << v[i];
    cout << " , " << n - 1 << " )  * 10 + " << v[n - 1] << endl;
    return QueFa(v, n - 1) * 10 + v[n - 1];
}

int   QueFaIteratiu(int v[], int n)
{
    int ret = 0;

    for (int i = 0; i < n;i++)
    {
        ret = ret*10 + v[i];
    }
    return ret;

}

// EXERCICI 3 ////////////////////////////////////////////////////////////////

int invertirNumeroRec(int n, int& potencia)
{
    int ret;
    if (n < 10)
    {
        return n;
    }

    ret = invertirNumeroRec(n/10, potencia);
    potencia *= 10;
    ret += (n%10)*potencia;
    return ret;

}

int invertirNumero(int n)
{
    int a = 1;
    int res = invertirNumeroRec(n,a);
    return res;

}
