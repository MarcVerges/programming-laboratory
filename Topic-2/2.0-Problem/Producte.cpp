//
//  Producte.cpp
//  Tema 2 - Exercici Herencia - S6 EXERCICI VOLUNTARI PUJAR NOTA EXERCICI CLASSE
//
//  Created by Marc Verges on 27/9/23.
//


#pragma once

#include "Producte.h"

float Producte::calculaDespesesEnviament()
{
    float despeses;

    if (m_preu < 100)
        despeses = 1.0;
    else
        despeses = 0.01 * m_preu;
    if (despeses > 5)
        despeses = 5;
    return despeses;
}


void Producte::mostra()
{
    cout << "Codi: " << m_codi << endl;
    cout << "Preu: " << m_preu << endl;
}






