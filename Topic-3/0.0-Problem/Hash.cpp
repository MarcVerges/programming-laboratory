//
// Created by Marc Verges on 17/10/23.
//
#include "Hash.h"
#include <math.h>
using namespace std;

Hash::Hash(int sizeIni, const string& descripcioDefecte)
{
    m_maxElements = sizeIni;
    m_descripcioDefecte=descripcioDefecte;

    m_diccionari.resize(m_maxElements,pair<string,string>("",""));
    m_estat.resize(m_maxElements, 0);

    m_numOcupats = 0;
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
        valor = valor%m_maxElements;
    }
    return valor;
}

int Hash::codi2(int index, int vegades) const
{
    return (int)(index + pow(vegades,2)) % m_maxElements;
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

void Hash::insertIntern(const string& clau, const string& descripcio)
{
    int index2 = codi(clau);
    int index = index2;
    int rep = 1;

    while ((m_estat[index] == OCUPAT) && (rep < m_maxElements))
    {
        index = codi2(index2, rep);
        rep++;
    }

    if (rep >= m_maxElements) throw "ERROR AL TROBAR POSICIO INSERCIO A HASH";


    m_diccionari[index].first = clau;
    m_diccionari[index].second = descripcio;
    m_estat[index] = OCUPAT;
    m_numOcupats++;
}


int Hash::cerca(const string& clau) const
{
    int index2 = codi(clau);
    int index = index2;
    int rep = 1;
    while (m_estat[index] != LLIURE)
    {
        if ((m_estat[index] == OCUPAT) && (m_diccionari[index].first == clau))
            return index;
        index = codi2(index2, rep);
        rep++;
    }
    return index;
}

void Hash::insert(const string& clau, const string& descripcio)
{
    int index = cerca(clau);
    if ((m_estat[index] == OCUPAT) && (m_diccionari[index].first == clau))
    {
        m_diccionari[index].second = descripcio;
    }
    else
    {
        insertIntern(clau, descripcio);
    }
}

bool Hash::find(const string& clau, string& definicio) const
{
    int index = cerca(clau);
    if ((m_estat[index] == OCUPAT) && (m_diccionari[index].first == clau))
    {
        definicio = m_diccionari[index].second;
        return true;
    }
    definicio = "";
    return false;
}

string& Hash::operator[](const string& clau)
{
    int index = cerca(clau);
    if ((m_estat[index] == OCUPAT) && (m_diccionari[index].first == clau))
    {
        return m_diccionari[index].second;
    }

    insertIntern(clau, m_descripcioDefecte);
    return m_descripcioDefecte;
}

bool Hash::esborra(const string& clau)
{
    int index = cerca(clau);
    if ((m_estat[index] == OCUPAT) && (m_diccionari[index].first == clau))
    {
        m_estat[index] = ESBORRAT;
        m_numOcupats--;
        return true;
    }
    return false;
}