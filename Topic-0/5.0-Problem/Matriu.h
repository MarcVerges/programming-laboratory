//
//  Matriu.h
//  Tema 0 - Exercici Avalauble 6
//
//  Created by Marc Verges on 19/9/23.
//
#pragma once


class Matriu
{
public:
    Matriu() : m_matriu(nullptr), m_nFiles(0), m_nColumnes(0) {}
    Matriu(int nFiles, int nColumnes) : m_matriu(nullptr), m_nFiles(0), m_nColumnes(0) { resize(nFiles, nColumnes); }
    Matriu(const Matriu& m) : m_matriu(nullptr), m_nFiles(0), m_nColumnes(0) { *this = m; }
    ~Matriu();
    void resize(int nFiles, int nColumnes);
    void transpose();
    void setValor(int fila, int columna, float valor);
    float getValor(int fila, int columna) const;
    bool esBuida() const { return (m_matriu == nullptr); }
    int getNFiles() const { return m_nFiles; }
    int getNColumnes() const { return m_nColumnes; }
    Matriu operator+(const Matriu& m);
    Matriu operator+(float s);
    bool operator==(const Matriu& m);
    
    Matriu& operator=(const Matriu& m);
    void initValor(float valor);
    

private:
    float **m_matriu;
    int m_nFiles;
    int m_nColumnes;

};
