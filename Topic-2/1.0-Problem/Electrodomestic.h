//
//  Electrodomestic.h
//  Tema2 - Exercici Herencia - S5 EXERCICI VOLUNTARI PUJAR NOTA EXERCICI CLASSE
//
//  Created by Marc Verges on 26/9/23.
//


#include "Producte.h"
#include <string>

class Electrodomestic : public Producte
{
private:
    string m_marca;
    string m_model;
    float m_volum;
    
public:
    Electrodomestic() {}
    Electrodomestic(const string& codi, float preu,const string& marca, const string& model, int volum) : Producte(codi,preu),m_marca(marca),m_model(model),m_volum(volum) {}
    Electrodomestic(const Electrodomestic& p) : Producte(p) {m_model = p.m_model; m_marca = p.m_marca; m_volum = p.m_volum;}
    ~Electrodomestic() {}
    
    void setMarca (const string& marca) {m_marca = marca;}
    void setModel (const string& model) {m_model = model;}
    void setVolum (float volum) {m_volum = volum;}
    string getMarca () const {return m_marca;}
    string getModel () const {return m_model;}
    float getVolum () const {return m_volum;}
    
    void mostrarElectrodomestic () const;
    float calculEnviamentElectrodomestic () const;
    float calculaPreu (int nUnitats) const;
  
};
