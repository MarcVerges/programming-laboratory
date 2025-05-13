//
//  Producte.h
//  Tema 2 - Exercici Herencia - S6 EXERCICI VOLUNTARI PUJAR NOTA EXERCICI CLASSE
//
//  Created by Marc Verges on 27/9/23.
//

#pragma once
#include <string>
#include <iostream>
using namespace std;

class Producte
{
public:
    Producte(): m_codi(""), m_preu(0) {}
    Producte(const string& codi, float preu) : m_codi(codi), m_preu(preu) {}
    Producte(const Producte& p) { m_codi = p.m_codi; m_preu = p.m_preu; }
    virtual ~Producte() {}

    void setCodi(const string& codi) { m_codi = codi; }
    void setPreu(float preu) { m_preu = preu; }
    string getCodi() { return m_codi; }
    float getPreu() { return m_preu; }

    float calculaDespesesEnviament();
    virtual void mostra();
    virtual float calculaPreu(int nUnitats) = 0;
private:
    string m_codi;
protected:
    float m_preu;
};
