
#pragma once
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

template<class TClau, class TValor>
class Map
{
private:
    std::vector<pair<TClau, TValor>> m_relacio;
    TClau m_clau;
    TValor m_valor;
    
public:
    Map() {}
    Map(const Map& m);
    ~Map() {}

    int longitud() const {return m_relacio.size();};
    bool esBuit() const{return m_relacio.empty();}
    TValor& operator[](const TClau& clau);
    const TValor& operator[](const TClau& clau) const;
    TClau& operator[](const int& posicio);
    const TClau& operator[](const int& posicio) const;
    void afegeix(const TClau& clau, const TValor& valor);
    Map<TClau, TValor>& operator= (const Map<TClau, TValor>& m);

};

template<class TClau, class TValor>
Map<TClau, TValor>::Map(const Map& m)
{
    m_relacio = m.m_relacio;
}



template<class TClau, class TValor>
TValor& Map<TClau, TValor>::operator[](const TClau& clau)
{
    typename vector<pair<TClau,TValor>> :: iterator m_iter = m_relacio.begin();
    
    while (m_iter != m_relacio.end())
    {
        if (m_iter->first == clau)
        {
            return m_iter->second;
        }
        else
        {
            m_iter ++;
        }
    }
    return m_valor;
}


template<class TClau, class TValor>
const TValor& Map<TClau, TValor>::operator[](const TClau& clau) const
{
    
    typename vector<pair<TClau,TValor>> :: const_iterator m_iter = m_relacio.begin();
    
    while (m_iter != m_relacio.end())
    {
        if (m_iter->first == clau)
        {
            return m_iter->second;
        }
        else
        {
            m_iter ++;
        }
    }
    return m_valor;
}


template<class TClau, class TValor>
TClau& Map<TClau, TValor>::operator[](const int& posicio)
{
    if (posicio >= 0 && posicio < longitud())
    {
        return m_relacio[posicio].first;
    }
    else
    {
        return m_clau;
    }
}


template<class TClau, class TValor>
const TClau& Map<TClau, TValor>::operator[](const int& posicio) const
{
    if (posicio >= 0 && posicio < longitud())
    {
        return m_relacio[posicio].first;
    }
    else
    {
        return m_clau;
    }
}


template<class TClau, class TValor>
void Map<TClau, TValor>::afegeix(const TClau& clau, const TValor& valor)
{
    bool existeix = false;
    int i = 0;

    while (i < longitud() && !existeix)
    {
        if (m_relacio[i].first == clau)
        {
            m_relacio[i].second = valor;
            existeix = true;
        }
        else
        {
            i++;
        }
    }
    
    if (!existeix)
    {
        //creem e insrim element
        pair<TClau, TValor> m;
        typename vector<pair<TClau, TValor>>::iterator m_iter = m_relacio.begin();
        m_relacio.insert(m_iter, make_pair(clau, valor));

        // ordenem el vector segons codi
        for (int i = 0; i < longitud(); i++)
        {
            for (int j = i + 1; j < longitud(); j++)
            {
                if (m_relacio[i].first > m_relacio[j].first)
                {
                    m = m_relacio[i];
                    m_relacio[i] = m_relacio[j];
                    m_relacio[j] = m;
                }
            }
        }
    }
}


template<class TClau, class TValor>
Map<TClau, TValor>& Map<TClau, TValor>::operator= (const Map<TClau, TValor>& m)
{
    if (this != &m)
    {
        if (m.m_relacio != nullptr)
        {
            m_relacio = m.m_relacio;
        }
    }

    return *this;
}




