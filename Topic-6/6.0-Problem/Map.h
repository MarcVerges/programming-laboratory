//
// Created by Marc Verges on 10/12/23.
//
#pragma once
#include <stdlib.h>
#include <iostream>
#include <utility>
#include "TreeRB.hpp"
using namespace std;



template<class TClau, class TValor>
class PairMap
{
public:
    TClau first;
    TValor second;
    PairMap() { first = TClau(); second = TValor(); }
    PairMap(TClau primer, TValor segon) { first = primer; second = segon; }
    bool operator<(PairMap<TClau, TValor> valor) const { return (first < valor.first); }
    bool operator==(PairMap<TClau, TValor> valor) const {	return (first == valor.first); }
    friend ostream& operator<<(ostream& out, PairMap<TClau, TValor> valor)
    {
        out << "<" << valor.first << ", " << valor.second << ">";
        return out;
    }
};


template<class TClau, class TValor>
class Map
{
public:
    Map();
    Map(const Map<TClau, TValor>& m);
    ~Map();
    bool esBuit() const;
    TValor& operator[](const TClau& clau);
    void afegeix(const TClau& clau, const TValor& valor);
    friend std::ostream& operator<<(std::ostream& out, const Map<TClau,TValor> & m)
    {
        if (!m.esBuit())
        {
            out << m.m_tree;
        }
        else
        {
            out << "";
        }
        return out;
    }

private:
    TreeRB<PairMap<TClau, TValor>> m_tree;
};


template<class TClau, class TValor>
Map<TClau, TValor>::Map()
{

}

template<class TClau, class TValor>
Map<TClau,TValor>::Map(const Map<TClau, TValor>& m)
{
    TreeRB<PairMap<TClau, TValor>>* m_arbreNou = new TreeRB<PairMap<TClau,TValor>>(m.m_tree);
    m_tree = *m_arbreNou;
}

template<class TClau, class TValor>
Map<TClau, TValor>::~Map()
{

}

template<class TClau, class TValor>
bool Map<TClau, TValor>::esBuit() const
{
    return (m_tree.isEmpty());
}

template<class TClau, class TValor>
TValor& Map<TClau, TValor>::operator[](const TClau& clau)
{
    if (!esBuit())
    {
        TreeRB<PairMap<TClau, TValor>>* trob;
        if (m_tree.cerca(PairMap<TClau, TValor>(clau, TValor()), trob))
        {
            return trob->getData().second;
        }
    }
    return *(new TValor);
}

template<class TClau, class TValor>
inline void Map<TClau, TValor>::afegeix(const TClau& clau, const TValor& valor)
{
    PairMap<TClau, TValor> parella(clau, valor);
    TreeRB<PairMap<TClau, TValor>>* afegir;

    if (m_tree.cerca(parella, afegir))
    {
        afegir->getData().second = valor;
    }
    else
    {
        m_tree.insert(parella);
    }


}
