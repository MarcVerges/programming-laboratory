//
//  Racional.cpp
//  Tema 1 - Exercici 1.4
//
//  Created by Marc Verges on 19/9/23.
//

#include "Racional.h"

bool Racional:: operator == (const Racional& ret)
{
    if ((m_numerador == ret.m_numerador) && (m_denominador == ret.m_denominador))
        return true;
    else
        return false;
}

ostream& operator << (ostream& output, const Racional& e)
{
    output << e.m_numerador << e.m_denominador;
    
    return output;
}
