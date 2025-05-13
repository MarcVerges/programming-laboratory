//
//  Prestec.h
//  Tema 2 - Exercici Avaluable 4.2
//
//  Created by Marc Verges on 3/10/23.
//


#include "Biblioteca.h"


class Prestec
{
private:
string m_codeUser;
string m_codePubli;
Data m_dataReturn;
Data m_dataPresetc;

public:
Prestec(): m_codeUser(""), m_codePubli(""), m_dataReturn(-1,-1,-1), m_dataPresetc(-1,-1,-1) {}

string getUserCode () const {return m_codeUser;}
string getCodePubli () const {return m_codePubli;}
Data getDataReturn () const {return m_dataReturn;}
Data getDataPresctec() const {return m_dataPresetc;}

void setUserCode (const string& codi) {m_codeUser = codi;}
void setPubliCode (const string& codi) {m_codePubli = codi;}
void setDataReturn (const Data& data) {m_dataReturn = data;}
void setDataPrestec (const Data& data) {m_dataPresetc = data;}

};


