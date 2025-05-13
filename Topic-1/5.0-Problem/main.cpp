//
//  main.cpp
//  Tema 1 - Exercici Voluntari
//
//  Created by Marc Verges on 18/9/23.
//

//MAIN TEST
#include "Pila.hpp"
#include "Racional.h"
#include <iostream>

using namespace std;

int main()
{
    bool valid = true;
    float grade = 0.0;
    
    cout << endl << endl;
    cout << "Comment :=>> Iniciant test del template PILA per elements de tipus INT" << endl;
    cout << "Comment :=>> ===========================================================" << endl;
    cout << "Comment :=>>  " << endl << endl;

    Pila <int> p;
    for (int i = 0; i < 10; i++)
        p.push(i);
    p.pop();
    int primer = p.top();
    cout << "El primer element de la pila es: " << primer << endl;
    
    if (primer == 8) grade += 5;
    else valid = false;

    Pila<Racional> pRacional;
    for (int i = 0; i < 10; i++)
    {
        Racional r(1, i);
        pRacional.push(r);
    }
    pRacional.pop();
    Racional primerR = pRacional.top();
    cout << "El primer element de la pila es: (" << primerR.getNumerador() <<" , " << primerR.getDenominador() <<" )" <<endl;

    if ((primerR.getNumerador() == 1) and (primerR.getDenominador() == 8)) grade += 5;
    else valid = false;

    if (valid)
        cout << "Comment :=>> Final del test sense errors" << endl;
    if (grade < 0)
        grade = 0;
    cout << endl << "Grade :=>> " << grade << endl;

    return 0;
}
//FINAL DEL MAIN PEL TEST
