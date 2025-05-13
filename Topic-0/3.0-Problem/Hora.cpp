//
//  Hora.cpp
//  Tema 0 - Exercici - Avaluable 2
//
//  Created by Marc Verges on 18/9/23.
//

#include "Hora.h"

Hora :: Hora ()
{
    m_sec = 0;
    m_min = 0;
    m_hora = 0;
}

Hora :: Hora (int hora, int min, int sec)
{
    m_sec = sec;
    m_min = min;
    m_hora = hora;
}

Hora :: Hora ( const Hora& e)
{
    m_min = e.m_min;
    m_sec = e.m_sec;
    m_hora = e.m_hora;
}

bool Hora :: horaValida () const
{
    bool valida = true;
    
    if ((m_hora > 23) || (m_hora < 00) || (m_min < 0) || (m_min > 59) || (m_sec < 0) || (m_sec > 59))
    {
        valida = false;
    }
    return valida;
}

Hora Hora :: operator+ (int n_sec)
{
    Hora res (m_hora,m_min,m_sec);
    
    if ((n_sec + m_sec > 59))
    {
        int ret = (m_sec + n_sec)/60;
        int restantes = (m_sec + n_sec) % 60;
        res.m_sec = restantes;
        
        if ((m_min + ret) > 59)
        {
            int ret2 = (m_min + ret)/60;
            int restantes2 = (m_min + ret) % 60;
            res.m_min = restantes2;
            
            if ((m_hora + ret2) > 23)
            {
                res.m_hora = ((m_hora + ret2) - 24);
                
                while (m_hora > 23)
                {
                    res.m_hora = res.m_hora - 24;
                }
            }
            else
            {
                res.m_hora = m_hora + ret2;
            }
        }
        else
        {
            res.m_min = m_min + ret;
        }
    }
    else
    {
        res.m_sec = m_sec + n_sec;
    }
    return res;
}

Hora Hora :: operator+ (const Hora& e)
{
    int totalsec = ((e.m_hora * 60) * 60 ) + (e.m_min * 60) + e.m_sec;
    Hora res;
    res = *this + totalsec;
    return res;
}

bool Hora :: operator== (const Hora& e)
{
    if (m_hora != e.m_hora)
    {
        return false;
    }
    else
    {
        if (m_min != e.m_min)
        {
            return false;
        }
        else
        {
            if (m_sec != e.m_sec)
            {
                return false;
            }
            else
            {
                return true;
            }
        }
    }
}

bool Hora :: operator< (const Hora&e)
{
    if (m_hora > e.m_hora)
    {
        return false;
    }
    else
    {
        if (m_min > e.m_min)
        {
            return false;
        }
        else
        {
            if (m_sec > e.m_sec)
            {
                return false;
            }
            else
            {
                return true;
            }
        }
    }
}

Hora Hora :: operator= (const Hora& e)
{
    
    m_hora = e.m_hora;
    m_min = e.m_min;
    m_sec = e.m_sec;
    
    return *this;
}


