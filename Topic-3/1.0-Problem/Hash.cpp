//
// Created by Marc Verges on 17/10/23.
//
#include "Hash.h"
#include <math.h>

Hash::Hash(int sizeIni)
{
    m_numElements = sizeIni;
    m_diccionari.resize(m_numElements,pair<string,string>("",""));
}

Hash::~Hash()
{
}

int Hash::codi(string s) const
{
    unsigned long valor = 0;
    for (int i = 0; i < s.size(); i++)
    {
        valor+= (s[i]*pow(2,i));
        valor = valor%m_numElements;
    }
    return valor;
}


int Hash::insert(const string& clau, const string& desc)
{
    int index=codi(clau);

    if ((m_diccionari[index].first != "") && (m_diccionari[index].first != clau))
        throw "COLISIO";
    m_diccionari[index].first = clau;
    m_diccionari[index].second = desc;
    return index;
}

string& Hash::operator[](const string& clau)
{
    int index = codi(clau);

    if (m_diccionari[index].first == clau)
    {
        //Element trobat
        return m_diccionari[index].second;
    }
    else
    {//Element no trobat, l'inserim
        string desc = "";
        m_diccionari[index].first = clau;
        m_diccionari[index].second = desc;
        return m_diccionari[index].second;
    }
}

bool Hash::find(const string& clau)
{
    int index = codi(clau);

    if (m_diccionari[index].first == clau)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Hash::mostra()
{
    for (int i = 0; i < m_diccionari.size(); i++)
    {
        if (m_diccionari[i].first!="")
        {
            cout << "POS: " <<i <<"  CLAU: " << m_diccionari[i].first <<"  VALOR: " << m_diccionari[i].second <<endl;
        }
    }
}