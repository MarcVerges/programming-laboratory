//
//  main.cpp
//  Tema 2 - Exercici Herencia - EXERCICI VOLUNTARI PUJAR NOTA VIDEO PREVI CLASSE
//
//  Created by Marc Verges on 25/9/23.
//

#include "Persona.h"
#include "Estudiant.h"
#include "Professor.h"
#include <iostream>

using namespace std;


int main()
{
    
    bool valid = true;
    float grade = 0.0;
    
    Persona *per1;
    Professor *pp1;
    
    pp1 = new Professor;
    per1 = pp1;
    
    
    cout << "Inicialitzacio constructor per defecte" << endl;
    cout << "======================================" << endl;
    Estudiant e1;
    e1.setNiu("NIU_1");
    e1.setNom("NOM_1");
    e1.setTitulacio("TITULACIO_1");
    cout << "Estudiant 1: " << e1.getNiu() << ", " << e1.getNom() << ", " << e1.getTitulacio() << endl;
    

    Professor p1;
    p1.setNiu("NIU_1");
    p1.setNom("NOM_1");
    p1.setDepartament("DEPARTAMENT_1");
    cout << "Professor 1: " << p1.getNiu() << ", " << p1.getNom() << ", " << p1.getDepartament() << endl;

    cout << endl << "Inicialitzacio constructor copia" << endl;
    cout << "===================================" << endl;
    Estudiant e2(e1);
    cout << "Estudiant 2: " << e2.getNiu() << ", " << e2.getNom() << ", " << e2.getTitulacio()<< endl;
    
    Professor p2(p1);
    cout << "Professor 2: " << p2.getNiu() << ", " << p2.getNom() << ", " << p2.getDepartament()<< endl;
    

    cout << endl << "Inicialitzacio constructor parametres" << endl;
    cout << "=======================================" << endl;
    Estudiant e3("NIu_2", "NOM_2", "TITULACIO_2");
    cout << "Estudiant 2: " << e3.getNiu() << ", " << e3.getNom() << ", " << e3.getTitulacio() << endl;
    Professor p3("NIu_3", "NOM_3", "DEPARTAMENT_2");
    cout << "Estudiant 2: " << p3.getNiu() << ", " << p3.getNom() << ", " << p3.getDepartament() << endl;

    cout << endl << "Destruccio objectes" << endl;
    cout << "======================" << endl;
    
    if (valid)
    {
        grade = 10;
        cout << "Comment :=>> Final del test sense errors" << endl;
    }
    if (grade < 0)
        grade = 0;
    cout << endl << "Grade :=>> " << grade << endl;


}
