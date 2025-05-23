//
//  Tramesa.h
//  Tema 0 - Exercici Avaluable 4
//
//  Created by Marc Verges on 19/9/23.
//
#pragma once
#include <string>
using namespace std;

class Tramesa
{
public:
    Tramesa() : m_fitxer(""), m_data("") {};
    Tramesa(const string& fitxer, const string& data) : m_fitxer(fitxer), m_data(data) {}
    void setFitxer(const string& fitxer) { m_fitxer = fitxer; }
    void setData(const string& data) { m_data = data; }
    string getFitxer() const { return m_fitxer; }
    string getData() const { return m_data; }
private:
    string m_fitxer;
    string m_data;
};

