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
    void setVal(const T& val) {m_data = val; };
    ~TreeRB();
    bool isLeave() const { return ((m_left == NULL) && (m_right == NULL)); }
    bool isEmpty() const { return (m_data == NULL);}
    TreeRB<T>* getRight(){return m_right;}
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

    void rotaEsq(TreeRB<T>*& pNodAct);
    void swapRootContents( TreeRB<T>* &pOldRoot, TreeRB<T>* &pNewRoot);
    void rotaDreta(TreeRB<T>* &pNodAct);
    void rota(TreeRB<T>* nouNode, TreeRB<T>* pPare,TreeRB<T>* pAvi);
    void swapColor(TreeRB<T>* pNod1, TreeRB<T>* pNod2);
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
        return this == m_father->m_right;
    else return false;

}

template<typename T>
bool TreeRB<T>::esFillEsq()
{
    if (m_father != nullptr)
        return this == m_father->m_left;
    else return false;

}

template<typename T>
TreeRB<T>* TreeRB<T>::oncle()
{
    if (m_father == nullptr) {return nullptr;}
    else
    {   if (m_father->m_father == nullptr)
            return nullptr;
        else
        {   if (m_father->esFillEsq()){ return m_father->m_father->m_right; }
            else { return m_father->m_father->m_left; }
        }
    }
    //FER CODI
}


template<typename T>
void TreeRB<T>::arreglaREDRED(TreeRB<T>* nouNode)
{
    if (nouNode->m_father == nullptr) //Es arrel
    { nouNode->m_color = BLACK; }
    else //Mirem pare, avi i oncle
    {   TreeRB<T>* pPare = nouNode->m_father;
        TreeRB<T>* pAvi = nouNode->m_father->m_father;
        TreeRB<T>* pOncle = nouNode->oncle();
        if (pPare->m_color != BLACK)
        {//Si el pare es BLACK ja hem acabat
            if (pOncle!= nullptr) //Oncle nullptr com NEGRE
                if (pOncle->m_color == RED)
                {//Recoloregem
                    pPare->m_color = BLACK;
                    pOncle->m_color = BLACK;
                    pAvi->m_color = RED;
                    arreglaREDRED(pAvi);
                }
                else{ rota(nouNode,pPare,pAvi);}
            else{ rota(nouNode, pPare, pAvi);}

        }
    }
    //FER CODI
}
template<class T>
void TreeRB<T>::swapColor(TreeRB<T>* pNod1, TreeRB<T>* pNod2)
{
    COLOR aux = pNod1->m_color;
    pNod1->m_color = pNod2->m_color;
    pNod2->m_color = aux;
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
        TreeRB<T>* ptAux=nullptr;
        bool trobat = cerca(val, ptAux);
        if (!trobat)
        {//Si trobem el valor no fem res, si no creem node RED amb val fill de ptAux
            TreeRB<T>* nouNode = new TreeRB<T>;
            nouNode->m_data = new T;
            (*nouNode->m_data) = val;
            nouNode->m_father = ptAux;
            if (val < (*ptAux->m_data)) {ptAux->m_left= nouNode; }
            else {ptAux->m_right= nouNode;}
            arreglaREDRED(nouNode);
        }
    }
    // FER CODI
}

template<class T> void TreeRB<T>::rota(TreeRB<T>* nouNode, TreeRB<T>* pPare,TreeRB<T>* pAvi)
{
    if (pPare->esFillEsq())
    {
        if (nouNode->esFillDret())
        {
            rotaEsq(pPare);
            pPare=pPare->m_father;
        }

        swapColor(pPare,pAvi);
        rotaDreta(pAvi);
    }
    else
    {
        if (nouNode->esFillEsq())
        {
            rotaDreta(pPare);
            pPare=pPare->m_father;
        }
        swapColor(pPare, pAvi);
        rotaEsq(pAvi);
    }
}



template<class T> void TreeRB<T>::rotaDreta(TreeRB<T>* &pNodAct)
{
    TreeRB<T>* fe = pNodAct->m_left;
    TreeRB<T>* besavi = pNodAct->m_father;

    if( besavi )
    {
        if( pNodAct->esFillDret())
        {
            besavi->m_right = fe;
        }else
        {
            besavi->m_left = fe;
        }
        fe->m_father = besavi;
    }
    else
    {
        this->swapRootContents( pNodAct, fe );
        fe->m_father = nullptr;
    }
    pNodAct->m_left = fe->m_right;
    if( fe->m_right)
    {
        fe->m_right->m_father = pNodAct;
    }

    pNodAct->m_father = fe;
    fe->m_right = pNodAct;
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
                if (fitxerNodes.is_open())	TreeRBRec(fitxerNodes, h, NULL);
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


template<class T>
void TreeRB<T>::swapRootContents( TreeRB<T>* &pOldRoot, TreeRB<T>* &pNewRoot)
{
    TreeRB<T> aux1;
    TreeRB<T> *aux2;
    aux2 = pOldRoot;
    pOldRoot = pNewRoot;
    pNewRoot = aux2;
    aux1 = *pOldRoot;
    *pOldRoot = *pNewRoot;
    *pNewRoot = aux1;

    if(pNewRoot->m_left)
        pNewRoot->m_left->m_father = pNewRoot;
    if(pNewRoot->m_right)
        pNewRoot->m_right->m_father = pNewRoot;
    if(pOldRoot->m_left)
        pOldRoot->m_left->m_father = pOldRoot;
    if(pOldRoot->m_right)
        pOldRoot->m_right->m_father = pOldRoot;
}
template<class T>
void TreeRB<T>::rotaEsq(TreeRB<T>*& pNodAct)
{
    TreeRB<T>* besavi = pNodAct->m_father;
    TreeRB<T>* fd = pNodAct->m_right;
    if( besavi )
    {
        if( pNodAct->esFillDret())
        {
            besavi->m_right = fd;
        }else
        {
            besavi->m_left = fd;
        }
        fd->m_father = besavi;
    }else
    {
        this->swapRootContents( pNodAct, fd );
        fd->m_father = nullptr;
    }
    pNodAct->m_right = fd->m_left;
    if( fd->m_left)
    {
        fd->m_left->m_father = pNodAct;
    }
    pNodAct->m_father = fd;
    fd->m_left = pNodAct;
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
                m_left->coutArbreRec(n + 1,out);
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
                m_right->coutArbreRec(n + 1,out);
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