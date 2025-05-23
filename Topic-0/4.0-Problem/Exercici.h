//
//  Exercici.h
//  Tema 0 - Exercici Avaluable 4
//
//  Created by Marc Verges on 19/9/23.
//

#pragma once
#include <string>
#include "LliuramentsEstudiant.h"
using namespace std;

class Exercici
{
public:
    Exercici() : m_descripcio(""), m_dataLimit(""), m_lliuraments(nullptr), m_nEstudiants(0) {}
    Exercici(const string& descripcio, const string& dataLimit) : m_descripcio(descripcio), m_dataLimit(dataLimit), m_lliuraments(nullptr), m_nEstudiants(0) {}
    Exercici(const Exercici& e);
    ~Exercici();
    Exercici& operator=(const Exercici& e);
    
    // per omplir
    
    void inicialitzaEstudiants(const string& fitxerEstudiants);
    bool afegeixTramesa(const string& niu, const string& fitxer, const string& data);
    bool consultaTramesa(const string& niu, const string& data, string& fitxer);
    bool eliminaTramesa(const string& niu, const string& data);
private:
    string m_descripcio;
    string m_dataLimit;
    LliuramentsEstudiant* m_lliuraments;
    int m_nEstudiants;
};

