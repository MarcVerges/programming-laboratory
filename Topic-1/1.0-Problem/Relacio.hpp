//
//  Relacio.hpp
//  Tema 1 - Exercici 4.2
//
//  Created by Marc Verges on 21/9/23.
//

#pragma once
#include <iostream>
#include "ArrayRelacions.hpp"

using namespace std;



template <typename t1,typename t2>
class Relacio
{
public:
    Relacio() : m_valor1(nullptr), m_valor2(nullptr) {}
    Relacio(t1 * valor1, t2 * valor2) : m_valor1(valor1), m_valor2(valor2) {}

    void setValors(t1* valor1, t2* valor2) { m_valor1 = valor1; m_valor2 = valor2; }
    t1* getValor1() const { return m_valor1; }
    t2* getValor2() const { return m_valor2; }
    void mostrarRelacions ( Relacio <t1,t2> e[], t1* et, int num_relacions);
    void mostrarRelacions ( Relacio  <t1,t2> e[], t2* et, int num_relacions);
private:
    t1* m_valor1;
    t2* m_valor2;
};


template <typename t1,typename t2>
void Relacio <t1,t2> :: mostrarRelacions  (Relacio <t1,t2> e[], t1* et, int num_relacions)
{
    //enfocat a t1
    
    for (int  i = 0; i < num_relacions; i++ )
    {
        if (*e[i].getValor1() == *et)
        {
            cout << *e[i].getValor2() << endl;
        }
    }
}



template <typename t1,typename t2>
void Relacio <t1,t2> :: mostrarRelacions (Relacio <t1,t2> e[], t2* et, int num_relacions)
{
    //enfocat a t2
    
    for (int  i = 0; i < num_relacions; i++ )
    {
        if (e[i].getValor2() == *et)
        {
            cout << *e[i].getValor1() << endl;
        }
    }
}

