//
// Created by Marc Verges on 17/10/23.
//
#include <iostream>
#include <vector>
#include <utility>
#include <string>
using namespace std;

//Amb col�lisions sondeig quadratic:

class Hash
{
public:
    Hash(int sizeIni=15);
    ~Hash();
    string& operator[](const string& clau);
    int insert(const string& clau, const string& desc);
    bool find(const string&clau);
    void mostra();

private:
    int codi(string s) const;
    std::vector<std::pair<string, string> > m_diccionari;
    int m_numElements;
};
