//
// Created by Marc Verges on 3/10/23.
//
#include "Biblioteca.h"

class Llibre : public Publicacio
{
private:
    string m_autor;
    int m_nCopies;
    int m_nDies;
    bool m_enPrestec;

public:
    Llibre(): m_autor(" "),m_nCopies(0), m_nDies(0) {}
    Llibre(const string& titol,const string& codi, char tipus, const string& autor, int copies, int dies): Publicacio(codi,titol,tipus), m_autor(autor),m_nCopies(copies),m_nDies(dies) {}
    void setAutor (const string& autor) {m_autor = autor;}
    void setnCopies (int copies)  {m_nCopies = copies;}
    void setDies (int dies)  {m_nDies = dies;}
    void setenPrestec (bool prestec)  {m_enPrestec = prestec;}
    string getAutor () const {return m_autor;}
    int getCopies() const {return m_nCopies;}
    int getnDies() const {return m_nDies;}
    bool getPrestec() const {return m_enPrestec;}
    bool esPotPrestar(int nExemplar = 0) override;
    int dataRetorn () const override ;
    bool tornaPubli (int nExemplar = 0) override;

};

bool Llibre :: esPotPrestar(int nExemplar)
{
    if (m_nCopies > 0)
    {
        m_nCopies --;
        return true;

    }
    else
    {
        return false;
    }
}

int Llibre :: dataRetorn () const
{
    return m_nDies;
}

bool Llibre :: tornaPubli (int nExemplar)
{
    m_nCopies ++;
    return true;
}





