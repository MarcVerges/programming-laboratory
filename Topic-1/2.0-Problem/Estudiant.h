#pragma once
#include <string>
#include <iostream>
using namespace std;

class Estudiant
{
public:
	Estudiant() {}
	Estudiant(const string& niu, const string& nom) : m_niu(niu), m_nom(nom) {}
	string getNIU() const { return m_niu; }
	string getNom() const { return m_nom; }
	bool operator==(const Estudiant& e) const { return m_niu == e.m_niu; }
	friend ostream& operator<< (ostream& out, const Estudiant& e);
private:
	string m_niu;
	string m_nom;
};