//
//  Llibre.cpp
//  Tema 2 - Exercici Herencia - S6 EXERCICI VOLUNTARI PUJAR NOTA EXERCICI CLASSE
//
//  Created by Marc Verges on 27/9/23.
//

#include "Llibre.h"


float Llibre::calculaDespesesEnviament()
{
    float despeses = Producte::calculaDespesesEnviament();
    if (m_nPagines > 500)
        despeses += 1;
    return despeses;
}

float Llibre::calculaPreu(int nUnitats)
{
    float preu = (m_preu* nUnitats) + calculaDespesesEnviament();
    if (nUnitats > 10)
        preu -= 0.05 * preu;
    else
        if (nUnitats > 100)
            preu -= 0.1 * preu;
    return preu;
}

void Llibre::mostra()
{
    Producte::mostra();
    cout << "Titol: " << m_titol << endl;
    cout << "Autor: " << m_autor << endl;
    cout << "N. pagines: " << m_nPagines << endl;
}
