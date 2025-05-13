//
//  Poligon.h
//  Tema 0 - Exercici 0.7
//
//  Created by Marc Verges on 14/9/23.
//

#ifndef POLIGON_H
#define POLIGON_H

#include "Punt.h"
#include "Node.h"


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
        Node* m_primer;
        Node* m_ultim;
        int m_nCostats;
        int m_nVertexs;
};




#endif // POLIGON_H
