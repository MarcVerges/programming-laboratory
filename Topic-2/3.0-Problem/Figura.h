//
// Created by Marc Verges on 5/10/23.
//
#ifndef FIGURA_H
#define FIGURA_H

typedef struct
{
    float x, y;
} Punt;


class Figura
{
public:
    Figura() {};
    Figura(const Figura& e) { *this = e;}
    virtual ~Figura() {}
    virtual Figura* clone() = 0;

    virtual float getPerimetre() =0;
    virtual float getArea()= 0;
    virtual void mostra()=0;
};


#endif  //FIGURA_H

