//
// Created by Marc Verges on 5/10/23.
//
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include "Figura.h"
using namespace std;

class Rectangle : public Figura
{
public:
    Rectangle() {}
    ~Rectangle() {}
    Rectangle(int xtl, int ytl, int xbr, int ybr);

    Rectangle* clone() {return new Rectangle(*this);}

    float getPerimetre() override;
    float getArea() override;
    void mostra() override;
private:
    Punt m_topLeft, m_bottomRight;
    float m_base, m_alcada;
};

#endif   //RECTANGLE_H

