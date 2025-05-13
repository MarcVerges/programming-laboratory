#include "Assignatura.h"

ostream& operator<< (ostream& out, const Assignatura& a)
{
	out << "Dades de l'assignatura" << endl;
	out << "Codi: " << a.m_codi << endl;
	out << "Nom: " << a.m_nom << endl;
	return out;
}
