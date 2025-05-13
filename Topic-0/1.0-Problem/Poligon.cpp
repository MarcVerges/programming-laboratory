//
//  Poligon.cpp
//  Tema 0 - Exercici 0.7
//
//  Created by Marc Verges on 14/9/23.
//

#include "Poligon.h"
#include <math.h>

Poligon::Poligon()
{
    m_nCostats = MIN_COSTATS;
    m_nVertexs = 0;
    m_primer = nullptr;
    m_ultim = nullptr;

}

Poligon::~Poligon()
{
    while (m_primer != nullptr)
    {
        Node *aux = m_primer;
        m_primer = m_primer -> getNext();
        delete aux;
    }

}

Poligon::Poligon(int nCostats)
{
    if ((nCostats >= MIN_COSTATS) && (nCostats <= MAX_COSTATS))
        m_nCostats = nCostats;
    else
        m_nCostats = MIN_COSTATS;
    m_nVertexs = 0;
    m_primer = nullptr;
    m_ultim = nullptr;
}

bool Poligon::afegeixVertex(const Punt &v)
{
    bool final = false;
   
    
    if (m_nVertexs < m_nCostats)
    {
        final = true;
        m_nVertexs++;
        Node * aux = new Node (v);
        
        if (m_primer == nullptr)
        {
            m_primer = aux;
        }
        else
        {
            m_ultim ->setNext(aux);
        }
        m_ultim = aux;

    }
    return final;
}

bool Poligon::getVertex(int nVertex, Punt &v) const
{
    bool correcte = false;
    if ((nVertex > 0) && (nVertex <= m_nCostats))
    {
        Node* aux = m_primer;
        v = aux-> getValor();
        
        for (int i = 1; i < nVertex; i++)
        {
            aux = aux -> getNext();
            v = aux -> getValor();
        }
       
    }
    return correcte;
}

float Poligon::calculaPerimetre() const
{
    float perimetre = 0;
    float dx, dy;
    Node* aux = m_primer;
    
    for (int i = 0; i < (m_nCostats - 1); i++)
    {
        Node* seguent = aux -> getNext();
        
        dx = aux -> getValor().getX() - seguent -> getValor().getX();
        dy = aux -> getValor().getY() - seguent -> getValor().getY();
        perimetre += sqrt(dx*dx + dy*dy);
        aux = seguent;
    }
    dx = aux -> getValor().getX() - m_primer -> getValor().getX();
    dy = aux -> getValor().getY() - m_primer -> getValor().getY();
    perimetre += sqrt(dx*dx + dy*dy);
    
    return perimetre;
}



