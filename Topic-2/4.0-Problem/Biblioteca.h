//
// Created by Marc Verges on 3/10/23.
//
#pragma once
#include "Data.h"
#include "Publicacio.h"
#include "Revista.h"
#include "Llibre.h"
#include "Prestec.h"
#include <string>
#include <list>
#include <fstream>

using namespace std;

class Biblioteca
{
public:
    Biblioteca() {}
    ~Biblioteca() {}
    void llegirPublicacions(const string& nomFitxer);
    bool prestar(const string& idUsuari, const string& codi, const Data& dataPrestec, Data& dataRetorn, int nExemplar = 0);
    bool retornar(const string& idUsuari, const string& codi, const Data& data, bool &dataCorrecta, int nExmplar = 0);

private:
    list <Publicacio*> m_llista;
    list <Prestec> m_prestecs;
};


void Biblioteca:: llegirPublicacions(const string& nomFitxer)
{
    ifstream fitxer;
    fitxer.open(nomFitxer);
    if (fitxer.is_open())
    {
        while (!fitxer.eof())
        {
            char tipus;
            string codi;
            string titol;

            fitxer >> tipus;
            fitxer >> codi;
            fitxer >> titol;

            if (tipus == 'L')
            {
                string autor;
                int nCopies;
                int nDies;

                fitxer >> autor;
                fitxer >> nCopies;
                fitxer >> nDies;
                Llibre *a = new Llibre (titol,codi,tipus,autor,nCopies,nDies);
                m_llista.push_front(a);
            }
            else
            {
                string periodicitat;
                int exemplars;
                vector <pair<int,bool>> presencia;

                fitxer >> periodicitat;
                fitxer >> exemplars;
                presencia.resize(exemplars);

                for (int i = 0; i < exemplars; i ++)
                {
                    int num;
                    fitxer >> presencia[i].first;
                    presencia [i].second = false;
                }

                Revista *a = new Revista(tipus,codi,titol,periodicitat,exemplars,presencia);
                m_llista.push_front(a);

            }
        }
    }
    fitxer.close();
}


bool Biblioteca :: prestar(const string& idUsuari, const string& codi, const Data& dataPrestec, Data& dataRetorn, int nExemplar)
{
    list <Publicacio*>  :: iterator  iter = m_llista.begin();
    bool esta = false;

    while (iter != m_llista.end() && !esta)
    {
        if ((*iter)->getCodi() == codi)
        {
            esta = true;

            if ((*iter)->getTipus() == 'L')
            {
                //cas on esta demanant el llibre
                if ((*iter)->esPotPrestar())
                {
                     Data r = dataPrestec;
                     r = r + (*iter)->dataRetorn();
                     dataRetorn = r;
                     Prestec a (idUsuari,codi,dataRetorn,dataPrestec,nExemplar);
                     m_prestecs.push_front(a);
                     return true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                //cas on es demana la revista
                if ((*iter)->esPotPrestar(nExemplar))
                {
                    Data r = dataPrestec;
                    r = r + (*iter)->dataRetorn();
                    dataRetorn = r;
                    Prestec a (idUsuari,codi,dataRetorn,dataPrestec,nExemplar);
                    m_prestecs.push_front(a);
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
        else
        {
            iter ++;
        }
    }
    return false;
}


bool Biblioteca :: retornar(const string& idUsuari, const string& codi, const Data& data, bool &dataCorrecta, int nExmplar)
{
    list <Prestec>  :: iterator  iter = m_prestecs.begin();
    bool esta = false;
    bool ret = false;

    while (iter != m_prestecs.end() && !esta)
    {
        //comprovem  si el llibre o revista estaba prestat i pertany al usari que el torna

        if (iter -> getCodePubli() == codi && iter ->getUserCode() == idUsuari)
        {
            esta = true;

            //comporvem data de entrega

            if((iter ->getDataReturn().getDia() >= data.getDia()) && (iter ->getDataReturn().getMes() >= data.getMes()) && (iter ->getDataReturn().getAny()
                >= data.getAny()))
            {
                dataCorrecta = true;
            }
            else
            {
                dataCorrecta = false;
            }

            //tornem el llibre / revist al sistema

            list <Publicacio*> :: iterator  forniter = m_llista.begin();
            bool esta = false;
            while (forniter != m_llista.end() && !esta)
            {
                if ((*forniter) -> getCodi() == codi)
                {
                    esta = true;
                    ret = (*forniter)->tornaPubli(nExmplar);
                }
                else
                {
                    forniter++;
                }
            }

            //eliminem el element de la llista de prestecs

            m_prestecs.erase(iter);
            return ret;
        }
        else
        {
            iter ++;
        }
    }

    //descarta llibres i revistes que no estan prestades o que no estan prestades per el id passat
    return false;
}



