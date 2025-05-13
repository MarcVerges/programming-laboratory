//
//  Llibre.h
//  Tema2 - Exercici Herencia - S5 EXERCICI VOLUNTARI PUJAR NOTA EXERCICI CLASSE
//
//  Created by Marc Verges on 26/9/23.
//

#include <string>
#include "Producte.h"

class Llibre : public Producte
{
private:
    string m_titol;
    string m_autor;
    int m_nPag;
    
public:
    Llibre() {}
    Llibre(const string& codi, float preu,const string& titol, const string& autor, int pag) : Producte(codi,preu),m_titol(titol),m_autor(autor),m_nPag(pag) {}
    Llibre (const Llibre& p) : Producte(p) {m_autor = p.m_autor; m_titol = p.m_titol; m_nPag = p.m_nPag;}
    ~Llibre() {}
    
    void setTitol (const string& titol) {m_titol = titol;}
    void setAutor (const string& autor) {m_autor = autor;}
    void setnPagines (int pag) {m_nPag= pag;}
    string getTitol () const {return m_titol;}
    string getAutor () const {return m_autor;}
    int getPag () const {return m_nPag;}
    
    void mostra () const;
    float calculEnviamentLlibre() const;
    float calculaPreu (int nUnitats) const;
    
};
