//
// Created by Marc Verges on 3/10/23.
//
#include "Biblioteca.h"
#include <vector>

class Revista : public Publicacio
{
private:
    string m_periodicitat;
    int m_nExemplars;
    vector <pair <int,bool>> m_exemplars; // int = num exemplar, bool false = no prestat, true = prestat

public:
    Revista() : m_exemplars(0),m_periodicitat("") {}
    Revista(char tipus,const string& codi, const string& titol, const string& periodicitat, int exemplars, vector<pair<int,bool>> presencia)
    : Publicacio(codi,titol,tipus),m_periodicitat(periodicitat), m_nExemplars(exemplars)  {m_exemplars = presencia;}
    string getPeriodicitat () const {return m_periodicitat;}
    int getnExemplars () const {return m_nExemplars;}
    bool exemplarEstaInoPrestat (int exemplar) const;
    bool esPotPrestar(int nExemplar = 0) override ;
    int dataRetorn () const override ;
    bool tornaPubli (int nExemplar = 0) override;
};

bool Revista :: esPotPrestar(int nExemplar)
{
    int i = 0;
    bool esta = false;

    while(i< m_nExemplars && !esta)
    {
        if (m_exemplars[i].first == nExemplar)
        {
            if (m_exemplars[i].second == false)
            {
                esta = true;
                m_exemplars[i].second = true;
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            i++;
        }
    }
    return false;
}


int Revista :: dataRetorn () const
{
    return 30;
}

bool Revista :: tornaPubli (int nExemplar)
{
    bool esta = false;
    int i = 0;

    while (!esta && i <m_nExemplars )
    {
        if (m_exemplars[i].first == nExemplar)
        {
            if (m_exemplars[i].second == false)
            {
                return false;
            }
            else
            {
                m_exemplars[i].second = false;
                return true;
            }
        }
        else
        {
            i++;
        }
    }
    return false;
}