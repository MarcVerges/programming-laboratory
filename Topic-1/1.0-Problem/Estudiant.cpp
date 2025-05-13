//
//  Estudiant.cpp
//  Tema 1 - Exercici 4.2
//
//  Created by Marc Verges on 21/9/23.
//

#include "Estudiant.h"

ostream& operator<< (ostream& out, const Estudiant& e)
{
    out << "Dades de l'estudiant" << endl;
    out << "NIU: " << e.m_niu << endl;
    out << "Nom: " << e.m_nom << endl;
    return out;
}

