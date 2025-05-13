//
// Created by Marc Verges on 3/10/23.
//
#include "Biblioteca.h"

class Publicacio
{
private:
    string m_codi;
    string m_titol;
    char m_tipus;

public:
    Publicacio() : m_codi(""), m_titol(""), m_tipus () {}
    Publicacio(const string codi, const string& titol, const char& tipus) : m_codi(codi), m_titol(titol), m_tipus(tipus) {}
    string getCodi() const {return m_codi;}
    string getTitol() const {return m_titol;}
    char getTipus () const {return m_tipus;}
    void setTitol(const string& titol) {m_titol = titol;}
    void setCodi (const string& codi) {m_codi = codi;}
    void setTipus (char tipus) {m_tipus = tipus;}
    virtual bool esPotPrestar(int nExemplar = 0) = 0;
    virtual int dataRetorn () const = 0;
    virtual bool tornaPubli (int nExemlplar = 0) = 0;
};
