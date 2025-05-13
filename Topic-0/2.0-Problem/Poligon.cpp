//
//  Poligon.cpp
//  Tema 0 - Exercici 0.9
//
//  Created by Marc Verges on 15/9/23.
//

#include "Poligon.h"
#include <math.h>

Poligon::Poligon()
{
    m_nCostats = MIN_COSTATS;
    m_nVertexs = 0;
    m_iter = m_vertexs.before_begin();
}

Poligon::~Poligon()
{

}

Poligon::Poligon(int nCostats)
{
    if (nCostats >= MIN_COSTATS)
    {
        m_nCostats = nCostats;
    }
    else
    {
        m_nCostats = MIN_COSTATS;
    }
    m_nVertexs = 0;
    m_iter = m_vertexs.before_begin();
}

bool Poligon::afegeixVertex(const Punt &v)
{
    bool correcte = false;
    if (m_nVertexs < m_nCostats)
    {
        m_vertexs.insert_after(m_iter,v);
        m_iter++;
        correcte = true;
    }
    return correcte;
}

bool Poligon::getVertex(int nVertex, Punt &v) const
{
    bool correcte = false;
    if ((nVertex > 0) && (nVertex <= m_nCostats))
    {
        std :: forward_list <Punt> :: const_iterator res = m_vertexs.begin();
        
        for (int i = 1 ; i < nVertex; i ++)
        {
            res ++;
        }
        v = *res;
    }
    return correcte;
}

float Poligon::calculaPerimetre() const
{
    float perimetre = 0;
    float dx, dy;
    std::forward_list<Punt>::const_iterator aux = m_vertexs.begin();
    std::forward_list<Punt>::const_iterator ant;
    
    for (int i = 0; i < m_nCostats - 1; i++)
    {
        ant = aux;
        aux ++;
        dx = ant -> getX() - aux -> getX();
        dy = ant -> getY() - aux -> getY();
        perimetre += sqrt(dx*dx + dy*dy);
    }
    
    dx = aux -> getX() - m_vertexs.begin()->getX();
    dy = aux -> getY() - m_vertexs.begin()->getY();
    perimetre += sqrt(dx*dx + dy*dy);
    
    return perimetre;
}


