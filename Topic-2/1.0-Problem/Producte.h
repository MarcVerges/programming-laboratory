//
//  Producte.h
//  Tema2 - Exercici Herencia - S5 EXERCICI VOLUNTARI PUJAR NOTA EXERCICI CLASSE
//
//  Created by Marc Verges on 26/9/23.
//

#include <string>
#include <iostream>


using namespace std;
class Producte
{
public:
    Producte()  {}
    Producte(const string& codi, float preu): m_codi(codi), m_preu(preu) {}
    Producte (const Producte& e) : m_codi(e.m_codi), m_preu(e.m_preu) {}
    ~Producte() {}
    
    void setCodi(const string& codi) { m_codi = codi; }
    void setPreu(float preu) { m_preu = preu; }
    string getCodi() { return m_codi; }
    float getPreu() { return m_preu; }
    
    void mostra () const;
    float calculEnviament () const;
    float calculPreu ()const;
    
    
private:
    string m_codi;
    
protected:
    float m_preu;
    
};
