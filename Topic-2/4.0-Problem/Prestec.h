//
// Created by Marc Verges on 3/10/23.
//
#include "Biblioteca.h"

class Prestec
{
private:
    string m_codeUser;
    string m_codePubli;
    Data m_dataReturn;
    Data m_dataPresetc;
    int m_exemplar; // nomes amb revista

public:
    Prestec(): m_codeUser(""), m_codePubli(""), m_dataReturn(-1,-1,-1), m_dataPresetc(-1,-1,-1) {}
    Prestec(const string& codiUser, const string& codiPubli, const Data& dataret, const Data& dataPrestac, int exemplar) : m_codeUser(codiUser), m_codePubli(codiPubli),
    m_dataReturn(dataret), m_dataPresetc(dataPrestac), m_exemplar(exemplar) {}
    string getUserCode () const {return m_codeUser;}
    string getCodePubli () const {return m_codePubli;}
    const Data getDataReturn () const {return m_dataReturn;}
    Data getDataPresctec() const {return m_dataPresetc;}
    void setUserCode (const string& codi) {m_codeUser = codi;}
    void setPubliCode (const string& codi) {m_codePubli = codi;}
    void setDataReturn (const Data& data) {m_dataReturn = data;}
    void setDataPrestec (const Data& data) {m_dataPresetc = data;}
};



