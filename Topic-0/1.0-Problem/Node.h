//
//  Node.h
//  Tema 0 - Exercici 0.7
//
//  Created by Marc Verges on 14/9/23.
//

#ifndef Node_h
#define Node_h

#include "Poligon.h"
#include "Punt.h"

class Node
{
public:
    Node (const Punt& pt) {m_valor = pt ; m_next = nullptr;}
    Punt getValor() {return m_valor;}
    Node* getNext() {return m_next;}
    void setNext(Node* next) {m_next = next;}
    void setValor (const Punt & e) {m_valor = e;}
    
private:
    Node* m_next;
    Punt m_valor;
    
};

#endif 
