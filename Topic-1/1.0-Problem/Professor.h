//
//  Professor.h
//  Tema 1 - Exercici 4.2
//
//  Created by Marc Verges on 21/9/23.
//

#pragma once
#include <iostream>
#include <string>
using namespace std;

class Professor
{
public:
    Professor() {}
    Professor(const string& niu, const string& nom, const string& departament) : m_niu(niu), m_nom(nom), m_departament(departament) {}
    string getNIU() const { return m_niu; }
    string getNom() const { return m_nom; }
    string getDepartament() const { return m_departament; }
    bool operator==(const Professor& p) const { return m_niu == p.m_niu; }
    friend ostream& operator<< (ostream& out, const Professor& p);
private:
    string m_niu;
    string m_nom;
    string m_departament;
};
