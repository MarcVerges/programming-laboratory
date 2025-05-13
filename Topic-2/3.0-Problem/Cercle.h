//
// Created by Marc Verges on 5/10/23.
//
#ifndef CERCLE_H
#define CERCLE_H

#include <iostream>
#include "Figura.h"
using namespace std;

const float PI = 3.141592;

class Cercle : public Figura
{
public:
    Cercle() {}
    ~Cercle() {}
    Cercle(int r, int x, int y);
    float getPerimetre() override;
    float getArea() override;
    void mostra() override;
    Cercle* clone() {return new Cercle (*this);}
private:
    float m_radi;
    Punt m_centre;
};

#endif  //CERCLE_H

