//
//  Exercici.cpp
//  Tema 0 - Exercici Avaluable 4
//
//  Created by Marc Verges on 19/9/23.
//

#include "Exercici.h"
#include <fstream>
using namespace std;

Exercici :: Exercici(const Exercici& e)
{
    m_descripcio = e.m_descripcio;
    m_dataLimit = e.m_dataLimit;
    m_nEstudiants = e.m_nEstudiants;
    
    if (e.m_lliuraments != nullptr)
    {
        m_lliuraments = new LliuramentsEstudiant [m_nEstudiants];
        
        for (int i = 0; i < m_nEstudiants; i++)
        {
            m_lliuraments[i] = e.m_lliuraments[i];
        }
    }
    else
    {
        m_lliuraments = nullptr;
    }
}

Exercici :: ~Exercici()
{
    delete [] m_lliuraments;
}


void Exercici :: inicialitzaEstudiants(const string& fitxerEstudiants)
{
  ifstream arxiu;
  arxiu.open(fitxerEstudiants);
  
  if (arxiu.is_open())
  {
      int num;
      arxiu >> num;
      m_nEstudiants = num;
      m_lliuraments = new LliuramentsEstudiant [m_nEstudiants];
      int i = 0;
      
      while ((!arxiu.eof()) && (i < m_nEstudiants))
      {
          string niu;
          
          arxiu >> niu;
          m_lliuraments[i].setNiu(niu);
          i++;
         
      }
  }
    arxiu.close();
}

bool Exercici :: afegeixTramesa(const string& niu, const string& fitxer, const string& data)
{
    bool estudiantesta = false;
    int i = 0;
    
    while ((i < m_nEstudiants) && !estudiantesta)
    {
        if (m_lliuraments[i].getNiu() == niu)
        {
            estudiantesta = true;
        }
        else
        {
            i++;
        }
    }
    if (estudiantesta)
    {
        m_lliuraments[i].afegeixTramesa(fitxer,data);
        return true;
    }
    else
    {
        return false;
    }
}

bool Exercici :: consultaTramesa(const string& niu, const string& data, string& fitxer)
{
    bool estudiantesta = false;
    int i = 0;
    
    while ((i < m_nEstudiants) && !estudiantesta)
    {
        if (m_lliuraments[i].getNiu() == niu)
        {
            estudiantesta = true;
        }
        else
        {
            i++;
        }
    }
    if (estudiantesta)
    {
       return  m_lliuraments[i].consultaTramesa(data, fitxer);
        
    }
    else
    {
        return false;
    }
}

bool Exercici :: eliminaTramesa(const string& niu, const string& data)
{
    bool estudiantesta = false;
    int i = 0;
    
    while ((i < m_nEstudiants) && !estudiantesta)
    {
        if (m_lliuraments[i].getNiu() == niu)
        {
            estudiantesta = true;
        }
        else
        {
            i++;
        }
    }
    if (estudiantesta)
    {
        return  m_lliuraments[i].eliminaTramesa(data);
        
    }
    else
    {
        return false;
    }
}


Exercici& Exercici :: operator=(const Exercici& e)
{
    if (this != &e)
    {
        m_descripcio = e.m_descripcio;
        m_dataLimit = e.m_dataLimit;
        m_nEstudiants = e.m_nEstudiants;
        
        if (m_lliuraments != nullptr)
        {
            delete [] m_lliuraments;
        }
        
        if (e.m_lliuraments != nullptr)
        {
            m_lliuraments = new LliuramentsEstudiant [m_nEstudiants];
            
            for (int i = 0; i < m_nEstudiants; i++)
            {
                m_lliuraments[i] = e.m_lliuraments[i];
            }
        }
        else
        {
            m_lliuraments = nullptr;
        }
    }
    return *this;
}
