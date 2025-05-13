//
//  Hora.h
//  Tema 0 - Exercici - Avaluable 2
//
//  Created by Marc Verges on 18/9/23.
//

#pragma once

class Hora
{
private:
    int m_hora,m_min,m_sec;
public:
    Hora ();
    Hora (int hora, int min, int sec);
    Hora ( const Hora& e);
    void setHora (int hora)   { m_hora = hora;}
    void setMinuts (int minuts) {m_min = minuts;}
    void setSegons (int sec) {m_sec = sec;}
    int getHora () const {return m_hora;}
    int getMinuts () const {return m_min;}
    int getSegons () const {return m_sec;}
    bool horaValida () const;
    Hora operator+ (int n_sec);
    Hora operator+ (const Hora& e);
    bool operator== (const Hora& e);
    bool operator< (const Hora&e);
    Hora operator= (const Hora& e);
};

