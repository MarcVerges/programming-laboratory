//
//  Poligon.h
//  Tema 0 - Exercici 0.4
//
//  Created by Marc Verges on 14/9/23.
//

#ifndef POLIGON_H
#define POLIGON_H

#include "Punt.h"

class Poligon
{
    public:
        Poligon();
        ~Poligon();
        Poligon(int nCostats);
        Poligon(const Poligon& r);
        Poligon & operator= (const Poligon& e);
        
    

        int getNCostats() const { return m_nCostats; };
        bool afegeixVertex(const Punt &v);
        bool getVertex(int nVertex, Punt &v) const;
        float calculaPerimetre() const;
    private:
        
        static const int MIN_COSTATS = 3;
        Punt *m_vertexs;
        int m_nCostats;
        int m_nVertexs;
};

#endif // POLIGON_H

