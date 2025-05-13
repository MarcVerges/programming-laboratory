//
// Created by Marc Verges on 5/10/23.
//
#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>
#include "Figura.h"
using namespace std;


class Triangle : public Figura
{
public:
    Triangle() {}
    ~Triangle() {}
    Triangle(const int m[][2]);
    Triangle* clone() {return new Triangle (*this);}

    float getPerimetre() override;
    float getArea() override;
    void mostra() override;
private:
    Punt m_vertexs[3];
    float m_costats[3];
};


#endif  //TRIANGLE_H

