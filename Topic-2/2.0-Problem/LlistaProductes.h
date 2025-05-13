//
//  LlistaProductes.h
//  Tema 2 - Exercici Herencia - S6 EXERCICI VOLUNTARI PUJAR NOTA EXERCICI CLASSE
//
//  Created by Marc Verges on 27/9/23.
//

#pragma once
#include "Llibre.h"
#include "Electrodomestic.h"
#include <stdio.h>
#include <list>
#include <iostream>
using namespace std;

class LlistaProductes
{
private:
    list<Producte*> m_llistaProuctes;
public:
    void afegeixLlibre(const Llibre& l);
    void afegeixElectrodomestic(const Electrodomestic& e);
    bool eliminaProducte(const string& codi);
    float getPreuProducte(const string& codi, int nUnitats);
    void mostra() const;
    
};
