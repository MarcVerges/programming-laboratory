//
// Created by Marc Verges on 16/11/23.
//
#pragma once
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Heap {
public:
    Heap() { m_numNodes = 0; m_max = 0; };
    Heap(Heap<T>& h);
    ~Heap() {};
    Heap<T>& operator=(const Heap<T>& h);

    T& min() { return &(m_data[0]); }
    size_t mida() { return m_numNodes; }
    void read(string nomFitxer);
    friend std::ostream& operator<<(std::ostream& out, const Heap<T>& h)
    {if (h.m_numNodes == 0){out << "|---->BUIT" << endl;}
        else	h.printRec(out,0, 0);
        return out;
    }
    void insert(T el);
    void delMin();
    void ordenar(vector<T>& v);
    void descendirRec(size_t posAct);
    void descendirVector(int posAct, vector<T>& v, int midaAct);

private:
    vector<T> m_data;
    size_t m_max; //indica nombre total de nodes: array va de 0 a m_max-1
    size_t m_numNodes; //indica nombre Elements actual: inicialment 0

    size_t pare(size_t pos) const { return ((pos - 1) / 2); }
    size_t fillEsq(size_t pos) const  { return ((2 * pos) + 1); }
    size_t fillDret(size_t pos) const { return ((2 * pos) + 2); }
    void intercanvia(size_t pos1, size_t pos2) { T aux = m_data[pos1]; m_data[pos1] = m_data[pos2]; m_data[pos2] = aux;}
    void intercanviaValors(T& v1, T& v2);

    std::ostream& printRec(std::ostream& out,size_t pos,size_t n) const;
};

template<typename T>
Heap<T>::Heap(Heap<T>& h)
{//constructor de copia
    m_data = h.m_data;
    m_max=h.m_max;
    m_numNodes=h.m_numNodes;
}
template<typename T>
Heap<T>& Heap<T>::operator=(const Heap<T>& h)
{
    if (this != &h)
    {
        m_data = h.m_data;
        m_max = h.m_max;
        m_numNodes = h.m_numNodes;
    }
    return *this;
}

template<typename T>
void Heap<T>::insert(T el)
{
    if ((m_numNodes + 1) < m_max)
    {
        m_data[m_numNodes++] = el;
        size_t pos = m_numNodes -1 ;
        while (pos != 0 && m_data[pos] < m_data[pare(pos)])
        {
            intercanvia(pos,pare(pos));
            pos = pare (pos);
        }
    }
}

template<class T>
void Heap<T>::descendirRec(size_t posAct)
{
    size_t fEsq = fillEsq(posAct);
    size_t fDret = fillDret(posAct);
    size_t mesPetit = posAct;

    if (fEsq < m_numNodes)
        if (m_data[fEsq] < m_data[mesPetit])
            mesPetit = fEsq;
    if (fDret < m_numNodes)
        if (m_data[fDret] < m_data[mesPetit])
            mesPetit = fDret;
    if (mesPetit != posAct)
    {
        intercanvia(posAct, mesPetit);
        descendirRec(mesPetit);
    }
}


template<typename T>
void Heap<T>::delMin()
{
    if (m_numNodes > 0)
    {
        intercanvia(0, --m_numNodes);
        descendirRec(0);
    }

    //FER CODI
}

template<class T>
void Heap<T>::descendirVector(int posAct, vector<T>& v, int midaAct)
{
    int fEsq = fillEsq(posAct);
    int fDret = fillDret(posAct);
    int mesPetit = posAct;
    if (fEsq <= midaAct)
        if (v[fEsq] < v[posAct])
            mesPetit = fEsq;
    if (fDret <= midaAct)
        if (v[fDret] < v[mesPetit])
            mesPetit = fDret;
    if (mesPetit != posAct)
    {
        intercanviaValors(v[posAct], v[mesPetit]);
        descendirVector(mesPetit,v, midaAct);
    }
}

template <typename T>
void Heap <T> :: intercanviaValors(T& v1, T& v2)
{
    T aux = v1;
    v1 = v2;
    v2 = aux;
}

template<typename T>
void Heap<T>::ordenar(vector<T>& v)
{
    int midaAct = v.size()-1;
    while (midaAct >= 0)
    {
        //Posar element ultim a l'arrel i decrementar nombre elements
        intercanviaValors(v[0], v[midaAct]);
        midaAct--;
        descendirVector(0,v, midaAct);
    }
}

/////////////////////////////////////////////////////////////////////////////
// read(nomFitxer):                                                        //
//                 Metode public que obre fitxer i llegeix Heap            //
//Lectura d'un fitxer a on tindrem                                         //
//nombre elements maxim admet Heap                                         //
//nombre elements que cont? el Heap                                        //
//Valors elements                                                          //
/////////////////////////////////////////////////////////////////////////////
template<typename T>
void Heap<T>::read(string nomFitxer)
{
    ifstream fitxerNodes;

    fitxerNodes.open(nomFitxer.c_str());
    if (fitxerNodes.is_open())
    {
        //Llegim maxim nombre de nodes i nombre nodes actual
        fitxerNodes >> m_max;
        fitxerNodes >> m_numNodes;
        m_data.resize(m_max, T());

        size_t i=0;
        while ((!fitxerNodes.eof()) && (i < m_numNodes))
        {
            fitxerNodes >> m_data[i];
            i++;
        }
        fitxerNodes.close();
    }
}

/////////////////////////////////////////////////////////////////////////////
// printRec(size_t pos, size_t n)                                                 //
//         Metode privat que escriu HEap per pantalla de forma recursiva   //
// |--arrel                                                                //
// |---->FillDret1                                                         //
// |------>FillDret2                                                       //
// |------>FillEsquerre2                                                   //
// |---->FillEsquerre1                                                     //
/////////////////////////////////////////////////////////////////////////////
template<typename T>
std::ostream& Heap<T>::printRec(std::ostream& out,size_t pos, size_t n) const
{
    if (pos<m_numNodes)
    {//Pintem arbre
        for (size_t i = 0; i < n; i++)
        {
            out << "|--";
        }
        out << "|-->" <<m_data[pos] << endl;
        if (((2*pos)+1)<=m_max)
        {//printem subarbre esquerre
            printRec(out, fillEsq(pos), n + 1);
        }
        if ((2 * pos) < m_max)
        {//printem subarbre dret
            printRec(out,fillDret(pos), n + 1);
        }
    }
    return out;
}