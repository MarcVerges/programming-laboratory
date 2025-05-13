//
//  LliuramentsEstudiant.cpp
//  Tema 0 - Exercici Avaluable 4
//
//  Created by Marc Verges on 19/9/23.
//

#include "LliuramentsEstudiant.h"

void LliuramentsEstudiant::afegeixTramesa(const string& fitxer, const string& data)
{
    Tramesa res (fitxer,data);
    m_trameses.push_front(res);
}

bool LliuramentsEstudiant::eliminaTramesa(const string& data)
{
    bool ret = false;
    std :: forward_list<Tramesa> :: iterator iter = m_trameses.begin();
    std :: forward_list<Tramesa> :: iterator previ = m_trameses.before_begin();
 
    while ((!ret) && iter != m_trameses.end())
    {
        if (iter ->getData() == data)
        {
            ret = true;
            m_trameses.erase_after(previ);
        }
        else
        {
            iter ++;
            previ ++;
        }
    }
    return ret;
}


bool LliuramentsEstudiant::consultaTramesa(const string& data, string& fitxer)
{
    bool ret = false;
    std :: forward_list<Tramesa> :: iterator iter = m_trameses.begin();
    
    while ((!ret) && iter != m_trameses.end())
    {
        if (iter -> getData() == data)
        {
            ret = true;
            fitxer = iter -> getFitxer();
        }
        else
        {
            iter ++;
        }
    }
    return ret;
}
