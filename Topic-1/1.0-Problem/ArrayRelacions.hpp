//
//  ArrayRelacions.hpp
//  Tema 1 - Exercici 4.2
//
//  Created by Marc Verges on 21/9/23.
//


#include "Estudiant.h"
#include "Assignatura.h"
#include "Professor.h"
#include "Relacio.hpp"

#pragma once

template < typename T1,typename T2 = Assignatura, int MAX_RELACIONS = 10 >
class ArrayRelacions
{
public:
    ArrayRelacions() : m_nRelacions(0) {}
    void mostraRelacions(T1* valor1) const;
    void mostraRelacions(T2* valor1) const;
    bool afegeixRelacio(Professor* valor1, Assignatura* valor2);
private:
    
    Relacio <T1,T2> m_relacions [MAX_RELACIONS];
    int m_nRelacions;
    
};




template < typename T1,typename T2, int MAX_RELACIONS>
void ArrayRelacions <T1,T2> :: mostraRelacions(t1* valor1) const
{
    for (int i = 0; i < m_nRelacions; i++)
    {
        if (*valor1 == *m_relacions[i].getValor1())
            cout << *m_relacions[i].getValor2();
    }
}

template < typename T1,typename T2, int MAX_RELACIONS>
void ArrayRelacions <T1,T2>::mostraRelacions(Assignatura* valor2) const
{
    for (int i = 0; i < m_nRelacions; i++)
    {
        if (*valor2 == *m_relacions[i].getValor2())
            cout << *m_relacions[i].getValor1();
    }
}

template < typename T1,typename T2, int MAX_RELACIONS>
bool ArrayRelacions <T1,T2>::afegeixRelacio(Professor* valor1, Assignatura* valor2)
{
    bool correcte = false;
    if (m_nRelacions < MAX_RELACIONS)
    {
        correcte = true;
        m_relacions[m_nRelacions++] = Relacio <Professor, Assignatura>(valor1, valor2);
    }
    return correcte;
}



