//
//  Professor.h
//  Tema 2 - Exercici Herencia - EXERCICI VOLUNTARI PUJAR NOTA VIDEO PREVI CLASSE
//
//  Created by Marc Verges on 25/9/23.
//

#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "Persona.h"
#include <string>
#include <iostream>

using namespace std;

class Professor: public Persona
{
public:
    Professor() : m_departament("") { cout << "Constructor Defecte Professor" << endl; }
    Professor(const string &niu, const string &nom, const string &departament) : Persona(niu,nom), m_departament(departament) { cout << "Constructor Parametres Professor" << endl; }
    Professor(const Professor& p) : Persona(p), m_departament(p.m_departament) { cout << "Constructor Copia Professor" << endl;    }
    ~Professor() { cout << "Destructor Professor" << endl; }
    
    
    

    void setDepartament(const string& departament) { m_departament = departament; }
    string getDepartament() const { return m_departament; }
private:
    
    string m_departament;
};

#endif // PROFESSOR_H


