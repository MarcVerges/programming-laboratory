//
//  Poligon.cpp
//  Tema 0 - Exercici 0.4
//
//  Created by Marc Verges on 14/9/23.
//

#include "Poligon.h"
#include <math.h>

Poligon::Poligon()
{
    m_nCostats = MIN_COSTATS;
    m_nVertexs = 0;
    m_vertexs = new Punt [m_nCostats];

}

Poligon::~Poligon()
{
    delete [] m_vertexs;
}

Poligon::Poligon(int nCostats)
{
    if ((nCostats >= MIN_COSTATS) )
        m_nCostats = nCostats;
    else
    {
        m_nCostats = MIN_COSTATS;
    }
    m_vertexs = new Punt [m_nCostats];
    m_nVertexs = 0;
       
}

Poligon :: Poligon(const Poligon& r)
{
    m_nCostats = r.m_nCostats;
    m_nVertexs = r.m_nVertexs;
    
    if (r.m_vertexs != nullptr)
    {
        m_vertexs = new Punt [m_nCostats];
        for (int i = 0; i < m_nCostats; i++)
        {
            m_vertexs[i] = r.m_vertexs[i];
        }
    }
    else
    {
        m_vertexs = nullptr;
    }
}

Poligon& Poligon :: operator= (const Poligon& e)
{
    if (this != &e)
    {
        m_nVertexs = e.m_nVertexs;
        m_nCostats = e.m_nCostats;
        
        if (m_vertexs != nullptr)
        {
            delete [] m_vertexs;
        }
        
        if (e.m_vertexs != nullptr)
        {
            m_vertexs = new Punt [m_nCostats];
            
            for (int i = 0; i < m_nCostats; i++)
            {
                m_vertexs[i] = e.m_vertexs[i];
            }
        }
    }
    else
    {
        m_vertexs = nullptr;
    }
    
    return *this;
}

bool Poligon::afegeixVertex(const Punt &v)
{
    bool correcte = false;
    if (m_nVertexs < m_nCostats)
    {
        m_vertexs[m_nVertexs] = v;
        m_nVertexs++;
        correcte = true;
    }
    return correcte;
}

bool Poligon::getVertex(int nVertex, Punt &v) const
{
    bool correcte = false;
    if ((nVertex > 0) && (nVertex <= m_nCostats))
    {
        v = m_vertexs[nVertex - 1];
        correcte = true;
    }
    return correcte;
}

float Poligon::calculaPerimetre() const
{
    float perimetre = 0;
    float dx, dy;
    for (int i = 0; i < m_nCostats - 1; i++)
    {
        dx = m_vertexs[i].getX() - m_vertexs[i+1].getX();
        dy = m_vertexs[i].getY() - m_vertexs[i+1].getY();
        perimetre += sqrt(dx*dx + dy*dy);
    }
    dx = m_vertexs[m_nCostats - 1].getX() - m_vertexs[0].getX();
    dy = m_vertexs[m_nCostats - 1].getY() - m_vertexs[0].getY();
    perimetre += sqrt(dx*dx + dy*dy);
    
    return perimetre;
}


