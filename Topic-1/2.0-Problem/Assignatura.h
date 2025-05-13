#pragma once
#include <string>
#include <iostream>
using namespace std;

class Assignatura 
{
public:
	Assignatura(): m_codi(), m_nom(){}
	Assignatura(int codi, const string& nom) : m_codi(codi), m_nom(nom) {}
	int getCodi() const { return m_codi; }
	string getNom() const { return m_nom; }
	bool operator==(const Assignatura& a) const { return m_codi == a.m_codi; }
	friend ostream& operator<< (ostream& out, const Assignatura& a);
private:
	int m_codi;
	string m_nom;
};