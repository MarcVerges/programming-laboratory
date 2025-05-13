//
//  Racional.h
//  Tema 1 - Exercici Voluntari
//
//  Created by Marc Verges on 18/9/23.
//

#pragma once
#include <iostream>
using namespace std;

class Racional
{
public:
    Racional() { m_numerador = 0; m_denominador = 0; }
    Racional(int num,int denom) { m_numerador = num; m_denominador = denom; }
    ~Racional() {}
    void setNumerador(const int valor) { m_numerador = valor; }
    void setDenominador(const int valor) { m_denominador = valor; }
    int getNumerador() const { return m_numerador; }
    int getDenominador() const { return m_denominador; }
    bool operator==(const Racional& r) const { return (m_numerador == r.m_numerador) && (m_denominador == r.m_denominador);  }
    friend ostream& operator << (ostream& out, const Racional&r);
private:
    int m_numerador;
    int m_denominador;
};
