#pragma once
#include <iostream>
using namespace std;

template <typename t1, typename t2>
class Relacio
{
public:
	Relacio() : m_valor1(nullptr), m_valor2(nullptr) {}
	Relacio(t1* valor1, t2* valor2) : m_valor1(valor1), m_valor2(valor2) {}

	void setValors(t1* valor1, t2* valor2) { m_valor1 = valor1; m_valor2 = valor2; }
	t1* getValor1 () const { return m_valor1; }
	t2* getValor2() const { return  m_valor2; }
    void mostrarRelacions ( Relacio <t1,t2> m_relacions[], t1* valor1, int nrelacions);
    void mostrarRelacions ( Relacio <t1,t2> m_relacions[], t2* valor2, int nrelacions);

    
private:
    t1* m_valor1;
	t2* m_valor2;
};


template <typename t1, typename t2>
void Relacio <t1,t2> :: mostrarRelacions ( Relacio <t1,t2> m_relacions[], t1* valor1, int nrelacions)
{
    for (int i = 0; i < nrelacions ; i++)
    {
        if (*m_relacions[i].getValor1() == *valor1)
        {
            cout << *m_relacions[i].getValor2();
        }
    }
}

template <typename t1, typename t2>
void Relacio <t1,t2> :: mostrarRelacions ( Relacio <t1,t2> m_relacions[], t2* valor2, int nrelacions)
{
    for (int i = 0; i < nrelacions ; i++)
    {
        if (*m_relacions[i].getValor2() == *valor2)
        {
            cout << *m_relacions[i].getValor1();
        }
    }
}
