#include "Professor.h"

ostream& operator<< (ostream& out, const Professor& p)
{
	out << "Dades del professor" << endl;
	out << "NIU: " << p.m_niu << endl;
	out << "Nom: " << p.m_nom << endl;
	out << "Departament: " << p.m_departament << endl;
	return out;
}
