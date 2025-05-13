//
//  Electrodomestic.cpp
//  Tema 2 - Exercici Herencia - S6 EXERCICI VOLUNTARI PUJAR NOTA EXERCICI CLASSE
//
//  Created by Marc Verges on 27/9/23.
//

#include "Electrodomestic.h"


float Electrodomestic::calculaDespesesEnviament()
{
    float despeses = Producte::calculaDespesesEnviament();
    despeses += floor(m_volum / 20) + 1;
    return despeses;
}

float Electrodomestic::calculaPreu(int nUnitats)
{
    float preu = (m_preu * nUnitats) +calculaDespesesEnviament();
    if (nUnitats > 1)
        preu -= 0.1 * preu;
    return preu;
}

void Electrodomestic::mostra()
{
    Producte::mostra();
    cout << "Marca: " << m_marca << endl;
    cout << "Model: " << m_model << endl;
    cout << "Volum: " << m_volum << endl;
}
