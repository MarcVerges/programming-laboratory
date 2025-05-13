//
//  Biblioteca.h
//  Tema 2 - Exercici Avaluable 4.2
//
//  Created by Marc Verges on 2/10/23.
//

#pragma once
#include "Data.h"
#include "Publicacio.h"
#include "Prestec.h"
#include <string>
#include <list>
#include <fstream>

using namespace std;

class Biblioteca
{
public:
    Biblioteca() {}
    ~Biblioteca() {}

    void llegirPublicacions(const string& nomFitxer);
    bool prestar(const string& idUsuari, const string& codi, const Data& dataPrestec, Data& dataRetorn, int nExemplar = 0);
    bool retornar(const string& idUsuari, const string& codi, const Data& data, bool &dataCorrecta, int nExmplar = 0);
private:

list <Publicacio*> m_llista;
list <Prestec> m_prestecs;

};


void Biblioteca:: llegirPublicacions(const string& nomFitxer)
{
    ifstream fitxer;
    fitxer.open(nomFitxer);
    if (fitxer.is_open())
    {
        
    }
}




