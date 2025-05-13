//
//  Persona.cpp
//  Tema 1 - Exercici Avaluable 5
//
//  Created by Marc Verges on 28/9/23.
//

#include "Persona.h"

ostream& operator<<(ostream &out, const Persona& p)
{
    out << "(" << p.m_nom << ", " << p.m_edat << ")";
    return out;
}

