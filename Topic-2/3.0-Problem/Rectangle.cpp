//
// Created by Marc Verges on 5/10/23.
//
#include "Rectangle.h"
Rectangle::Rectangle (int xtl, int ytl, int xbr, int ybr)
{

    m_topLeft.x = xtl;
    m_topLeft.y = ytl;
    m_bottomRight.x = xbr;
    m_bottomRight.y = ybr;

    m_base = m_bottomRight.x - m_topLeft.x;
    m_alcada = m_topLeft.y - m_bottomRight.y;
}

float Rectangle::getPerimetre()
{
    return (2 * m_base + 2 * m_alcada);
}

float Rectangle::getArea()
{
    return m_base * m_alcada;
}

void Rectangle::mostra()
{
    cout << "Dades del Rectangle" << endl;
    cout << "Cantonada superior esquerra: ";
    cout << "(" << m_topLeft.x << ", " << m_topLeft.y << ")" << endl;
    cout << "Cantonada inferior dreta: ";
    cout << "(" << m_bottomRight.x << ", " << m_bottomRight.y << ")" << endl;
}