//
//  Punt.h
//  Tema 0 - Exercici 0.9
//
//  Created by Marc Verges on 15/9/23.
//

#ifndef PUNT_H
#define PUNT_H

#include <iostream>
using namespace std;

class Punt
{
    public:
        Punt();
        ~Punt();
        Punt(float x, float y): m_x(x), m_y(y) {};
        Punt(const Punt& pt);
        float getX() const { return m_x; }
        void setX(const float x) { m_x = x; }
        float getY() const { return m_y; }
        void setY(const float y) { m_y = y; }
    private:
        float m_x;
        float m_y;
};

#endif // PUNT_H

