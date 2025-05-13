//
//  Persona.cpp
//  Tema 2 - Exercici Avaluable 4.3
//
//  Created by Marc Verges on 28/9/23.
//

#include "Persona.h"
#include <iostream>

ostream& operator<<(ostream &out, const Persona& p)
{
    out << "(" << p.m_nom << ", " << p.m_edat << ")";
    return out;
}

bool Persona :: operator== (const Persona& e) const
{
    if (m_nom == e.m_nom && m_edat == e.m_edat)
    {
        return true;
    }
    else
    {
        return false;
    }
}

