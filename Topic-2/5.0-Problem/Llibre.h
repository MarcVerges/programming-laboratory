//
//  Llibre.h
//  Tema 2 - Exercici Avaluable 4.2
//
//  Created by Marc Verges on 3/10/23.
//


#include "Publicacio.h"
#include "Biblioteca.h"


class Llibre : public Publicacio
{
private:
    string m_autor;
    int m_nCopies;
    int m_nDies;
    bool m_enPrestec;

public:
    Llibre(): m_autor(""),m_enPrestec(false),m_nCopies(0), m_nDies(0) {}
    Llibre(const string& titol,const string& codi, const string& tipus, const string& autor, int copies, int dies, bool prestec) :

    void setAutor (const string& autor) {m_autor = autor;}
    void setnCopies (int copies)  {m_nCopies = copies;}
    void setDies (int dies)  {m_nDies = dies;}
    void setenPrestec (bool prestec)  {m_enPrestec = prestec;}
    string getAutor () const {return m_autor;}
    int getCopies() const {return m_nCopies;}
    int getnDies() const {return m_nDies;}
    bool getPrestec() const {return m_enPrestec;}


};
