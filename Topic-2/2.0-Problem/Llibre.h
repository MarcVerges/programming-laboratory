//
//  Llibre.h
//  Tema 2 - Exercici Herencia - S6 EXERCICI VOLUNTARI PUJAR NOTA EXERCICI CLASSE
//
//  Created by Marc Verges on 27/9/23.
//

#pragma once
#include "Producte.h"
#include <string>
#include <iostream>
using namespace std;

static const float FACTOR_DESPESES_PES = 0.5;

class Llibre: public Producte
{
public:
    Llibre() : m_titol(""), m_autor(""), m_nPagines(0) {}
    Llibre(const string& codi, float preu, const string& titol, const string& autor, int nPagines) : Producte(codi, preu), m_titol(titol), m_autor(autor), m_nPagines(nPagines) {}
    Llibre(const Llibre& l) : Producte(l) { m_titol = l.m_titol; m_autor = l.m_autor; m_nPagines = l.m_nPagines; }
    ~Llibre() {}
    void setTitol(const string& titol) { m_titol = titol; }
    void setAutor(const string& autor) { m_autor = autor; }
    void setnPagines(const int nPagines) { m_nPagines = nPagines; }
    string getTitol() { return m_titol; }
    string getAutor() { return m_autor; }
    int getNPagines() { return m_nPagines; }

    float calculaDespesesEnviament();
    float calculaPreu(int nUnitats) override;
    void mostra()override;
private:
    string m_titol;
    string m_autor;
    int m_nPagines;
};


