//
// Created by Marc Verges on 5/10/23.
//
#include "Cercle.h"

Cercle :: Cercle (int r, int x, int y)
{
    m_radi = r;
    m_centre.x = x;
    m_centre.y = y;
}

float Cercle::getPerimetre()
{
    return (2 * PI * m_radi);
}

float Cercle::getArea()
{
    return (PI * m_radi * m_radi);
}

void Cercle::mostra()
{
    cout << "Dades del Cercle" << endl;
    cout << "Centre del cercle: ";
    cout << "(" << m_centre.x << ", " << m_centre.y << ")" << endl;
    cout << "Longitud del radi: ";
    cout << m_radi << endl;
}