//
//  Revista.h
//  Tema 2 - Exercici Avaluable 4.2
//
//  Created by Marc Verges on 3/10/23.
//

#include "Publicacio.h"
#include "Biblioteca.h"
#include <vector>

class Revista : public Publicacio
{
private:

string m_periodicitat;
int m_nExemplars;
vector <pair <int,bool>> m_exemplars;


public:
Revista() : m_exemplars(0),m_enPrestec(false),m_periodicitat("") {}

string getPeriodicitat () const {return m_periodicitat;}
int getnExemplars () const {return m_nExemplars;}
bool exemplarEstaInoPrestat (int exemplar) const;


};

bool Revista :: exemplarEstaInoPrestat (int exemplar) const
{
    
}



