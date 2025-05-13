//
//  main.cpp
//  Tema 2 - Exercici Herencia - S6 EXERCICI VOLUNTARI PUJAR NOTA EXERCICI CLASSE
//
//  Created by Marc Verges on 27/9/23.
//

#include <iostream>
#include "Llibre.h"
#include "Electrodomestic.h"
#include "LlistaProductes.h"
#include <list>
#include <cmath>
using namespace std;

int main()
{
    bool valid = true;
    float grade = 0.0;

    cout << endl << endl;
    cout << "Comment :=>> Iniciant test de les classes Productes, Llibres i Electrodomestics VIRTUALS" << endl;
    cout << "Comment :=>> ===========================================================================" << endl;
    cout << "Comment :=>>  " << endl << endl;

        
    cout << "Comment :=>> CREANT LLISTAPRODUCTES: " << endl;
    LlistaProductes llista;
    

    cout << "Comment :=>> CREANT LLIBRE1 I AFEGINT A LA LLISTA: " << endl;
    Llibre l1("CODI_1", 10, "TITOL_1", "AUTOR_1", 100);
    llista.afegeixLlibre(l1);
    cout << "Comment :=>> CREANT LLIBRE2 I AFEGINT A LA LLISTA: " << endl;
    Llibre l2("CODI_2", 20, "TITOL_2", "AUTOR_2", 200);
    llista.afegeixLlibre(l2);
    cout << "Comment :=>> CREANT LLIBRE3 I AFEGINT A LA LLISTA: " << endl;
    Llibre l3("CODI_3", 30, "TITOL_3", "AUTOR_3", 300);
    llista.afegeixLlibre(l3);
    grade += 1;

    cout << "Comment :=>> CREANT ELECTRODOMESTIC1 I AFEGINT A LA LLISTA: " << endl;
    Electrodomestic e1("CODI_4", 400, "MARCA_1", "MODEL_1", 50);
    llista.afegeixElectrodomestic(e1);
    cout << "Comment :=>> CREANT ELECTRODOMESTIC2 I AFEGINT A LA LLISTA: " << endl;
    Electrodomestic e2("CODI_5", 400, "MARCA_1", "MODEL_1", 50);
    llista.afegeixElectrodomestic(e2);
    cout << "Comment :=>> CREANT ELECTRODOMESTIC3 I AFEGINT A LA LLISTA: " << endl;
    Electrodomestic e3("CODI_6", 400, "MARCA_1", "MODEL_1", 50);
    llista.afegeixElectrodomestic(e3);
    grade += 1;

    cout << "Comment :=>> MOSTRANT LLISTA: " << endl;
    llista.mostra();
    grade += 1;

    cout << "Comment :=>> MOSTRANT PREU PRODUCTE AMB CODI: " << l1.getCodi() <<endl;
    float preuProd = llista.getPreuProducte(l1.getCodi(), 20);
    cout << preuProd << endl;
    float epsilon = 0.0001;
    if (fabs(preuProd-190.95)<=epsilon)
    {
        cout << "Comment :=>> PREU CORRECTE: "<< endl;
        grade += 2;
    }
    else
    {
        valid = false;
        cout << "Comment :=>> PREU ERRONI HAURIA DE SER: 190.95" << endl;
    }


    cout << "Comment :=>> MOSTRANT PREU PRODUCTE AMB CODI: " << e1.getCodi() << endl;
    preuProd = llista.getPreuProducte(e1.getCodi(), 2);
    cout << preuProd << endl;
    if (fabs(preuProd - 726.3) <= epsilon)
    {
        cout << "Comment :=>> PREU CORRECTE: " << endl;
        grade += 2;
    }
    else
    {
        valid = false;
        cout << "Comment :=>> PREU ERRONI HAURIA DE SER: 726.3" << endl;
    }
    



    cout << "Comment :=>> Eliminant Llibre" << endl;
    llista.eliminaProducte(l1.getCodi());
    grade += 1;
    cout << "Comment :=>> Eliminant Electrodomestic" << endl;
    llista.eliminaProducte(e1.getCodi());
    grade += 1;

    cout << "Comment :=>> MOSTRANT LLISTA: " << endl;
    llista.mostra();
    grade += 1;

    if (valid)
        cout << "Comment :=>> Final del test sense errors" << endl;
    if (grade < 0)
        grade = 0;
    cout << endl << "Grade :=>> " << grade << endl;

    return 0;
}
