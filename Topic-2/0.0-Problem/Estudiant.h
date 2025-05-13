//
//  Estudiant.h
//  Tema 2 - Exercici Herencia - EXERCICI VOLUNTARI PUJAR NOTA VIDEO PREVI CLASSE
//
//  Created by Marc Verges on 25/9/23.
//

#ifndef ESTUDIANT_H
#define ESTUDIANT_H

#include "Persona.h"
#include <string>
#include <iostream>

using namespace std;

class Estudiant : public Persona
{
public:
    Estudiant() : m_titulacio("") { cout << "Constructor Defecte Estudiant" << endl; }
    Estudiant(const string &niu, const string &nom, const string &titulacio) : Persona(niu, nom), m_titulacio(titulacio) { cout << "Constructor Parametres Estudiant" << endl; }
    Estudiant(const Estudiant& e) : Persona(e) { m_titulacio = e.m_titulacio; cout << "Constructor Copia Estudiant" << endl; }
    ~Estudiant() { cout << "Destructor Estudiant" << endl; }
    void setTitulacio(const string& titulacio) { m_titulacio = titulacio; }
    string getTitulacio() const { return m_titulacio; }
private:
    string m_titulacio;
};

#endif // ESTUDIANT_H

