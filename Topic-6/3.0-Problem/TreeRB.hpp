//
// Created by Marc Verges on 21/11/23.
//
#pragma once
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

template <typename T>
class TreeRB {
public:

    TreeRB() { m_left = NULL; m_right = NULL; m_father = NULL; m_data = NULL;  m_color = RED; };
    TreeRB(string nomFitxer);
    TreeRB(const TreeRB<T>& t);
    void setVal(const T& val) { m_data = val; };
    ~TreeRB();
    bool isLeave() const { return ((m_left == NULL) && (m_right == NULL)); }
    bool isEmpty() const { return (m_data == NULL); }
    TreeRB<T>* getRight() { return m_right; }
    TreeRB<T>* getLeft() { return m_left; }
    T& getData() { return (*m_data); }
    bool cerca(const T& val, TreeRB<T>*& valTrobat);
    TreeRB<T>* oncle();
    bool esFillDret();
    bool esFillEsq();
    friend std::ostream& operator<<(std::ostream& out, const TreeRB<T>& t)
    {
        t.coutArbreRec(0, out);
        return out;
    };

    void insert(T& val);

private:
    enum COLOR { RED, BLACK };
    TreeRB<T>* m_left;
    TreeRB<T>* m_right;
    TreeRB<T>* m_father;
    T* m_data;
    COLOR m_color;

    void arreglaREDRED(TreeRB<T>* nouNode);
    void TreeRBRec(ifstream& fitxerNodes, int h, TreeRB<T>* father);
    std::ostream& coutArbreRec(int n, std::ostream& out) const;
};


template<typename T>
TreeRB<T>::TreeRB(const TreeRB<T>& t)
{
    m_color = t.m_color;

    if (t.m_left != NULL)
    {
        m_left = new(TreeRB<T>);
        m_left = t.m_left;
    }
    else
    {
        m_left = NULL;
    }

    if (t.m_right != NULL)
    {
        m_right = new(TreeRB<T>);
        m_right = t.m_right;
    }
    else
    {
        m_right = NULL;
    }
//m_father: here m_father must be NULL
//we are creating a TreeRB, if it has to be connected with another one you will use setRight o r left.
    m_father = NULL;

    if (t.m_data != NULL)
    {
        m_data = new(T);
        m_data = t.m_data;
    }
    else
    {
        m_data = NULL;
    }
}

template<typename T>
bool TreeRB<T>::esFillDret()
{
    if (m_father != nullptr)
    {
        return this == m_father->m_right;
    }
    else
    {
        return false;
    }
}

template<typename T>
bool TreeRB<T>::esFillEsq()
{
    if (m_father != nullptr)
    {
        return this == m_father->m_left;
    }
    else
    {
        return false;
    }
}

template<typename T>
TreeRB<T>* TreeRB<T>::oncle()
{
    if (m_father == nullptr)
    {
        return nullptr;
    }
    else
    {
        if (m_father->m_father == nullptr)
        {
            return nullptr;
        }
        else
        {
            if (m_father->esFillEsq())
            {
                return m_father->m_father->m_right;
            }
            else
            {
                return m_father->m_father->m_left;
            }
        }
    }
}


template<typename T>
void TreeRB<T>::arreglaREDRED(TreeRB<T>* nouNode)
{
    if (nouNode->m_father == nullptr)
    {
        nouNode->m_color = BLACK;
    }
    else
    {
        TreeRB<T>* Pare = nouNode->m_father;
        TreeRB<T>* Avi = Pare->m_father;
        TreeRB<T>* Oncle = nouNode->oncle();

        if (Pare->m_color != BLACK)
        {
            if (Oncle != nullptr)
            {
                if (Oncle->m_color == RED)
                {
                    Pare->m_color = BLACK;
                    Avi->m_color = RED;
                    Oncle->m_color = BLACK;
                    arreglaREDRED(Avi);
                }
            }
        }
    }

}

template<typename T>
void TreeRB<T>::insert(T& val)
{
    if (m_data == nullptr)
    {//Arbre buit
        m_data = new T;
        (*m_data) = val;
        m_color = BLACK;
    }
    else
    {
        TreeRB<T>* ptAux = nullptr;
        bool trobat = cerca(val, ptAux);
        if (!trobat)
        {//Si trobem el valor no fem res, si no creem node RED amb val fill de ptAux
            TreeRB<T>* nouNode = new TreeRB<T>;
            nouNode->m_data = new T;
            (*nouNode->m_data) = val;
            nouNode->m_father = ptAux;
            if (val < (*ptAux->m_data))
            {
                ptAux->m_left = nouNode;
            }
            else
            {
                ptAux->m_right = nouNode;
            }
            arreglaREDRED(nouNode);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
// TreeRB(nomFitxer):                                                        //
//                 constructor que obre fitxer i crida a metode privat     //
// TreeRBRec(ifstream& fitxerNodes, int h, TreeRB<T>* father)              //
//            metode privat que llegeix arbre de forma recursiva           //
//Lectura d'un fitxer a on tindrem                                         //
//alcada                                                                   //
//estat: 0 o 1 segons sigui buit o amb informacio al costat dada           //
//Esta en preordre Preordre(FillEsq) Arrel Preordre(FillDret)                //
/////////////////////////////////////////////////////////////////////////////
template<typename T>
TreeRB<T>::TreeRB(string nomFitxer)
{
    ifstream fitxerNodes;

    fitxerNodes.open(nomFitxer.c_str());
    if (fitxerNodes.is_open())
    {
//Llegim al�ada arbre binari
        int h;
        fitxerNodes >> h;
        if (!fitxerNodes.eof())
        {
            int estat;
            fitxerNodes >> estat;
            if (estat == 1)
            {
                if (fitxerNodes.is_open()) TreeRBRec(fitxerNodes, h, NULL);
            }
        }
        fitxerNodes.close();
    }
}

template<typename T>
void TreeRB<T>::TreeRBRec(ifstream& fitxerNodes, int h, TreeRB<T>* father)
{
    m_father = father;
    m_data = new(T);
    fitxerNodes >> (*m_data);
    if (h > 0)
    {
        int estat;
        if (!fitxerNodes.eof())
        {
            fitxerNodes >> estat;
            if (!fitxerNodes.eof())
            {
                if (estat == 1)
                {
                    m_left = new(TreeRB<T>);
                    m_left->TreeRBRec(fitxerNodes, h - 1, this);
                }
            }
        }
        if (!fitxerNodes.eof())
        {
            fitxerNodes >> estat;
            if (!fitxerNodes.eof())
            {
                if (estat == 1)
                {
                    m_right = new(TreeRB<T>);
                    m_right->TreeRBRec(fitxerNodes, h - 1, this);
                }
            }
        }
    }
}


template<typename T>
TreeRB<T>::~TreeRB()
{
    if (m_right != NULL)
    {
        delete m_right;
    }

    if (m_left != NULL)
    {
        delete m_left;
    }

    if (m_data != NULL)
    {
        delete m_data;
    }

    m_father = NULL;
}

//Suposem l'arbre ordenat amb valors menors a arrel a esquerra i valors majors a dreta
template<typename T>
bool TreeRB<T>::cerca(const T& val, TreeRB<T>*& valTrobat)
{
    if (m_data != NULL)
    {
        if (val == (*m_data))
        {
            valTrobat = this;
            return true;
        }
        else
        if (val < (*m_data))
        {
            if (m_left != NULL)
            {
                return m_left->cerca(val, valTrobat);
            }
            else
                valTrobat = this;
        }
        else
        {
            if (m_right != NULL)
            {
                return (m_right->cerca(val, valTrobat));
            }
            else
                valTrobat = this;
        }
    }
    return false;
}

/////////////////////////////////////////////////////////////////////////////
// coutArbreRec():                                                         //
//         Metode privat cridat per operator<<                             //
//                       que escriu arbre per pantalla de forma recursiva  //
// |--arrel                                                                //
// |---->FillDret1                                                         //
// |------>FillDret2                                                       //
// |------>FillEsquerre2                                                   //
// |---->FillEsquerre1                                                     //
//alcada                                                                   //
//estat: 0 o 1 segons sigui buit o amb informacio al costat dada           //
//Esta en inordre Inordre(FillEsq) Arrel Inordre(FillDret)                 //
/////////////////////////////////////////////////////////////////////////////
template<typename T>
std::ostream& TreeRB<T>::coutArbreRec(int n, std::ostream& out) const
{
    if (isEmpty())
    {//Pintem arbre buit
        out << "Comment :=>> ";
        for (int i = 0; i < n; i++)
        {
            out << "|--";
        }
        out << "-->BUIT" << endl;
    }
    else
    {
        out << "Comment :=>> ";
        for (int i = 0; i < n; i++)
        {
            out << "|--";
        }
        out << "|-->";
        if (m_color == RED)
            out << "RED,";
        else
            out << "BLACK,";
        out << (*m_data) << endl;
        if (!isLeave())
        {
            if (m_left != NULL)
            {
                m_left->coutArbreRec(n + 1, out);
            }
            else
            {
                out << "Comment :=>> ";
                for (int i = 0; i < n + 1; i++)
                {
                    out << "|--";
                }
                out << "|-->BUIT" << endl;
            }
            if (m_right != NULL)
            {
                m_right->coutArbreRec(n + 1, out);
            }
            else
            {
                out << "Comment :=>> ";
                for (int i = 0; i < n + 1; i++)
                {
                    out << "|--";
                }
                out << "|-->BUIT" << endl;
            }
        }
    }
    return out;
}
