//
//  LliuramentsEstudiant.h
//  Tema 0 - Exercici Avaluable 4
//
//  Created by Marc Verges on 19/9/23.
//

#pragma once
#include <string>
#include <forward_list>
#include "Tramesa.h"
using namespace std;

class LliuramentsEstudiant
{
public:
    LliuramentsEstudiant() : m_niu(""), m_nota(0.0) {};
    void setNiu(const string& niu) { m_niu = niu; }
    string getNiu() const { return m_niu; }
    float getNota() const { return m_nota; }
    
    // per omplir
    void afegeixTramesa(const string& fitxer, const string& data);
    bool consultaTramesa(const string& data, string& fitxer);
    bool eliminaTramesa(const string& data);
    
  
private:
    string m_niu;
    float m_nota;
    forward_list<Tramesa> m_trameses;
};


