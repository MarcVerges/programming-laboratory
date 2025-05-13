#include "Estudiant.h"

ostream& operator<< (ostream& out, const Estudiant& e)
{
	out << "Dades de l'estudiant" << endl;
	out << "NIU: " << e.m_niu << endl;
	out << "Nom: " << e.m_nom << endl;
	return out;
}
