//
//  Electrodomestic.cpp
//  Tema2 - Exercici Herencia - S5 EXERCICI VOLUNTARI PUJAR NOTA EXERCICI CLASSE
//
//  Created by Marc Verges on 26/9/23.
//

#include "Electrodomestic.h"
#include "math.h"

void Electrodomestic:: mostrarElectrodomestic () const
{
    Producte :: mostra();
    cout << m_marca << endl;
    cout << m_model << endl;
    cout << m_volum << endl;
}

float Electrodomestic:: calculEnviamentElectrodomestic () const
{
    float preu = Producte :: calculEnviament();
    
    if ( m_volum > 20)
    {
        return preu;
    }
    else
    {
        preu += ceil (m_volum / 20);
        return preu;
    }
}

float Electrodomestic:: calculaPreu (int nUnitats) const
{
    float preu = m_preu + calculEnviamentElectrodomestic();
    
    if (nUnitats > 1)
    {
        return (preu - (preu * 0.1));
    }
    return preu;
}



