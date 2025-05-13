//
//  LlistaProductes.cpp
//  Tema 2 - Exercici Herencia - S6 EXERCICI VOLUNTARI PUJAR NOTA EXERCICI CLASSE
//
//  Created by Marc Verges on 27/9/23.
//

#include "LlistaProductes.h"

void LlistaProductes:: afegeixLlibre(const Llibre& l)
{
    Llibre *a = new Llibre (l);
    m_llistaProuctes.push_back(a);
}

void LlistaProductes:: afegeixElectrodomestic(const Electrodomestic& e)
{
    Electrodomestic* a = new Electrodomestic (e);
    m_llistaProuctes.push_back(a);
}

bool LlistaProductes :: eliminaProducte(const string& codi)
{
    std:: list<Producte*> :: iterator iter = m_llistaProuctes.begin();
    
    bool esta = false;
    
    while ((iter != m_llistaProuctes.end()) && (!esta))
    {
        if ((*iter)->getCodi() == codi)
        {
            delete *iter;
            m_llistaProuctes.erase(iter);
            esta = true;
        }
        else
        {
            iter ++;
        }
    }
    return esta;
}

float LlistaProductes:: getPreuProducte(const string& codi, int nUnitats)
{
    std:: list<Producte*> :: iterator iter = m_llistaProuctes.begin();
    
    bool esta = false;
    
    while ((iter != m_llistaProuctes.end()) && (!esta))
    {
        if ((*iter)->getCodi() == codi)
        {
            return (*iter) ->calculaPreu(nUnitats);
        }
        else
        {
            iter ++;
        }
    }
    
    return 0;
  
}

void LlistaProductes :: mostra() const
{
    std:: list<Producte*> :: const_iterator iter;
    
    for (iter = m_llistaProuctes.begin(); iter != m_llistaProuctes.end(); iter++)
    {
        (*iter)->mostra();
    }
}
