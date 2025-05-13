//
//  Llibre.cpp
//  Tema2 - Exercici Herencia - S5 EXERCICI VOLUNTARI PUJAR NOTA EXERCICI CLASSE
//
//  Created by Marc Verges on 26/9/23.
//

#include "Llibre.h"

void Llibre :: mostra () const
{
    Producte :: mostra();
    cout << m_titol << endl;
    cout << m_autor << endl;
    cout << m_nPag << endl;
}

float Llibre:: calculEnviamentLlibre () const
{
    float preu =  Producte :: calculEnviament();
    
    if (m_nPag > 500)
    {
        preu += 1;
    }
    return preu;
}

float Llibre :: calculaPreu (int nUnitats) const
{
    float preu = m_preu + calculEnviamentLlibre();
    
    if (nUnitats > 100)
    {
        return (preu - (preu * 0.1));
    }
    else
    {
        if (nUnitats > 10)
        {
            return (preu - (preu * 0.05));
        }
        else
        {
            return preu;
        }
    }
}


