//
//  Publicacio.h
//  Tema 2 - Exercici Avaluable 4.2
//
//  Created by Marc Verges on 2/10/23.
//


#include "Biblioteca.h"

class Publicacio
{
private:
    string m_codi;
    string m_titol;
    string m_tipus;

public:
    Publicacio() : m_codi(""), m_titol(""), m_tipus ("") {}
    Publicacio(const string codi, const string& titol, const string& tipus) : m_codi(codi), m_titol(titol), m_tipus(tipus) {}


    string getCodi() const {return m_codi;}
    string getTitol() const {return m_titol;}
    string getTipus () const {return m_tipus;}

    void setTitol(const string& titol) {m_titol = titol;}
    void setCodi (const string& codi) {m_codi = codi;}
    void setTipus (const string& tipus) {m_tipus = tipus;}
    
    
};
