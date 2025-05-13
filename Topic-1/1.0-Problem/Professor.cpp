//
//  Professor.cpp
//  Tema 1 - Exercici 4.2
//
//  Created by Marc Verges on 21/9/23.
//
#include "Professor.h"

ostream& operator<< (ostream& out, const Professor& p)
{
    out << "Dades del professor" << endl;
    out << "NIU: " << p.m_niu << endl;
    out << "Nom: " << p.m_nom << endl;
    out << "Departament: " << p.m_departament << endl;
    return out;
}

