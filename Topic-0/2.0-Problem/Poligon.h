//
//  Poligon.h
//  Tema 0 - Exercici 0.9
//
//  Created by Marc Verges on 15/9/23.
//

#ifndef POLIGON_H
#define POLIGON_H

#include "Punt.h"
#include <forward_list>

class Poligon
{
    public:
        Poligon();
        ~Poligon();
        Poligon(int nCostats);

        int getNCostats() const { return m_nCostats; };
        bool afegeixVertex(const Punt &v);
        bool getVertex(int nVertex, Punt &v) const;
        float calculaPerimetre() const;
    private:
        static const int MAX_COSTATS = 30;
        static const int MIN_COSTATS = 3;
        std :: forward_list <Punt> m_vertexs;
        std :: forward_list <Punt> :: iterator m_iter;
        int m_nCostats;
        int m_nVertexs;
    
    
};

#endif // POLIGON_H
