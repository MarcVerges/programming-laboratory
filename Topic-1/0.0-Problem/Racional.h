//
//  Racional.h
//  Tema 1 - Exercici 1.4
//
//  Created by Marc Verges on 19/9/23.
//

#pragma once
#include <iostream>
using namespace std;

class Racional
{
public:
    Racional() { m_numerador = 0; m_denominador = 0; }
    ~Racional() {}
    void setNumerador(const int valor) { m_numerador = valor; }
    void setDenominador(const int valor) { m_denominador = valor; }
    int getNumerador() const { return m_numerador; }
    int getDenominador() const { return m_denominador; }
    bool operator == (const Racional& ret);
    friend ostream& operator << (ostream& output, const Racional& e);
    
private:
    int m_numerador;
    int m_denominador;
};
