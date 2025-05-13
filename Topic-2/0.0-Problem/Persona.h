//
//  Persona.h
//  Tema 2 - Exercici Herencia - EXERCICI VOLUNTARI PUJAR NOTA VIDEO PREVI CLASSE
//
//  Created by Marc Verges on 25/9/23.
//

#ifndef PERSONA_H
#define PERSONA_H

#include <string>
#include <iostream>

using namespace std;

class Persona
{
public:
    Persona() : m_niu(""), m_nom("") { cout << "Constructor Defecte Persona" << endl; }
    Persona(const string &niu, const string &nom): m_niu(niu), m_nom(nom) { cout << "Constructor Parametres Persona" << endl; }
    Persona(const Persona& p) { m_niu = p.m_niu; m_nom = p.m_nom; cout << "Constructor Copia Persona" << endl; }
    ~Persona() { cout << "Destructor Persona" << endl; }

    string getNiu() const { return m_niu; }
    string getNom() const { return m_nom; }
    void setNiu(const string& niu) { m_niu = niu; }
    void setNom(const string& nom) { m_nom = nom; }
private:
    string m_niu;
    string m_nom;

};


#endif // PERSONA_H


