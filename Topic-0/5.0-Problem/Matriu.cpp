//
//  Matriu.cpp
//  Tema 0 - Exercici Avalauble 6
//
//  Created by Marc Verges on 19/9/23.
//

#include "Matriu.h"
#include <cmath>

Matriu :: ~Matriu()
{
    for (int i = 0; i < m_nFiles; i++)
    {
        delete [] m_matriu[i];
    }
    delete [] m_matriu;
}

void Matriu:: resize(int nFiles, int nColumnes)
{
    float **aux = new float*[nFiles];
    
    for (int i = 0; i < nFiles; i++)
        aux[i] = new float [nColumnes];
    
    for (int i = 0 ; i < nFiles; i++)
    {
        for (int j = 0; j < nColumnes; j++)
        {
            aux[i][j] = 0;
        }
    }
    
    if ((m_nColumnes < nColumnes) || (m_nFiles < nFiles))
    {
        for (int i = 0 ; i < m_nFiles; i++)
        {
            for (int j = 0; j < m_nColumnes; j++)
            {
                aux[i][j] = m_matriu[i][j];
            }
        }
        
    }
    else
    {
        for (int i = 0 ; i < nFiles; i++)
        {
            for (int j = 0; j < nColumnes; j++)
            {
                aux[i][j] = m_matriu[i][j] ;
            }
        }
    }
      
    for (int i = 0; i < m_nFiles; i++)
    {
        delete [] m_matriu[i];
    }
    delete [] m_matriu;
    m_nFiles = nFiles;
    m_nColumnes = nColumnes;
    m_matriu = aux;
}

void Matriu:: transpose()
{
    float **aux = new float*[m_nColumnes];
    for (int i = 0; i < m_nColumnes; i++)
    {
        aux[i] = new float [m_nFiles];
    }
        
    for (int i = 0; i < m_nFiles; i ++)
    {
        for (int j = 0; j < m_nColumnes; j++)
        {
            aux[j][i] = m_matriu[i][j];
        }
    }
   
    
    for (int i = 0; i < m_nFiles; i++)
    {
        delete [] m_matriu[i];
    }
    
    delete [] m_matriu;
    int rest = m_nFiles;
    m_nFiles = m_nColumnes;
    m_nColumnes = rest;
    m_matriu = aux;
}

void Matriu :: setValor(int fila, int columna, float valor)
{
    if ((fila <= m_nFiles) && (columna <= m_nColumnes))
    {
        m_matriu[fila][columna] = valor;
    }
}

float Matriu :: getValor(int fila, int columna) const
{
    if ((fila <= m_nFiles) || (columna <= m_nColumnes))
    {
        return m_matriu[fila][columna];
    }
    else
    {
        return NAN;
    }
}

Matriu Matriu:: operator+(const Matriu& m)
{
    if ((m.m_nFiles == m_nFiles) && (m.m_nColumnes == m_nColumnes))
    {
        Matriu res;
        res.m_nFiles = m_nFiles;
        res.m_nColumnes = m_nColumnes;
        
        res.m_matriu = new float* [res.m_nFiles];
        for (int i = 0; i < res.m_nFiles; i++)
        {
            res.m_matriu[i] = new float [res.m_nColumnes];
        }
        
        for (int i = 0; i < res.m_nFiles; i ++)
        {
            for (int j = 0; j < res.m_nColumnes; j++)
            {
                res.m_matriu[i][j] = m_matriu[i][j] + m.m_matriu[i][j];
            }
        }
        return res;
    }
    else
    {
        Matriu res;
        res.m_nFiles = 0;
        res.m_nColumnes = 0;
        res.m_matriu = nullptr;
        return res;
    }
}



Matriu Matriu :: operator+(float s)
{
    Matriu res;
    res.m_nFiles = m_nFiles;
    res.m_nColumnes = m_nColumnes;
    
    res.m_matriu = new float* [m_nFiles];
    for (int i = 0; i < m_nFiles; i++)
    {
        res.m_matriu[i] = new float [m_nColumnes];
    }
    
    for (int  i = 0; i < m_nFiles; i ++)
    {
        for (int j = 0; j < m_nColumnes; j++)
        {
            res.m_matriu[i][j] = m_matriu[i][j] + s;
        }
    }
    return res;
}

bool Matriu :: operator==(const Matriu& m)
{
    if ((m_nFiles == m.m_nFiles) && (m_nColumnes == m.m_nColumnes))
    {
        int i = 0, j = 0;
        bool iguals = true;
        
        while ((i < m_nFiles) && iguals)
        {
            j= 0;
            
            while ((j < m_nColumnes) && iguals)
            {
                if (m_matriu[i][j] != m.m_matriu[i][j])
                {
                    iguals = false;
                }
                else
                {
                    j++;
                }
            }
            i++;
        }
        return iguals;
    }
    else
    {
        return false;
    }
}

Matriu& Matriu :: operator=(const Matriu& m)
{
    if (this != &m)
    {
        m_nFiles = m.m_nFiles;
        m_nColumnes = m.m_nColumnes;
        
        if (m_matriu != nullptr)
        {
            for (int i = 0; i < m_nFiles; i++)
            {
                delete [] m_matriu[i];
            }
            delete [] m_matriu;
        }
        
        if (m.m_matriu != nullptr)
        {
            m_matriu = new float* [m_nFiles];
            for (int i = 0; i < m_nFiles; i++)
            {
                m_matriu[i] = new float [m_nColumnes];
            }
            
            for (int  i = 0; i < m_nFiles; i ++)
            {
                for (int j = 0; j < m_nColumnes; j++)
                {
                    m_matriu[i][j] = m.m_matriu[i][j];
                }
            }
        }
        else
        {
            m_matriu = nullptr;
        }
    }
    return *this;
}
