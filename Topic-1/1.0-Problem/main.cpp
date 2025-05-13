//
//  main.cpp
//  Tema 1 - Exercici 4.2
//
//  Created by Marc Verges on 21/9/23.
//

#include "Relacio.hpp"
#include "ArrayRelacions.hpp"
#include "Estudiant.h"
#include "Assignatura.h"
#include "Professor.h"
#include <iostream>
using namespace std;

int main()
{
    bool valid = true;
    float grade = 0.0;

    cout << endl << endl;
    cout << "Comment :=>> Iniciant test de la classe ARRAY RELACIONS" << endl;
    cout << "Comment :=>> ==========================================" << endl;
    cout << "Comment :=>>  " << endl << endl;

    cout << "Comment :=>> CREANT ARRAY RELACIONS ESTUDIANT ASSIG DE 10" << endl;
    cout << "Comment :=>> ============================================" << endl;
    ArrayRelacions<Estudiant> estudiantsAssignatura;
    grade += 1;

    cout << "Comment :=>> CREANT ARRAY RELACIONS PROFESSOR ASSIG DE  5" << endl;
    cout << "Comment :=>> ============================================" << endl;
    const int MAX_EST_PROF = 5;
    ArrayRelacions<Professor, Assignatura, MAX_EST_PROF> professorsAssignatura;
    grade += 1;

    cout << "Comment :=>> CREANT ESTUDIANT ASSIGNATURA I PROFESSOR" << endl;
    cout << "Comment :=>> ========================================" << endl;
    string niuEst[3] = { "NIU_E1" ,"NIU_E2" ,"NIU_E3" };
    string niuProf[3] = { "NIU_P1" ,"NIU_P2" ,"NIU_P3" };
    string nomEst[3] = { "NOM_EST_1" ,"NOM_EST_2" ,"NOM_EST_3" };
    string nomProf[3] = { "NOM_PROF_1" ,"NOM_PROF_2" ,"NOM_PROF_3" };
    string nomAssig[3] = { "NOM_ASSIG_1","NOM_ASSIG_2", "NOM_ASSIG_3" };
    string deptProf[3] = { "DEPT_1","DEPT_2", "DEPT_3" };

    Estudiant* est[3];
    Assignatura* assig[3];
    Professor* prof[3];

    
    for (int i = 0; i < 3; i++)
    {
        est[i]= new Estudiant(niuEst[i], nomEst[i]);
        assig[i]= new Assignatura(i+1, nomAssig[i]);
        prof[i] = new Professor(niuProf[i], nomProf[i], deptProf[i]);
    }
    grade += 1;

    cout << "Comment :=>> AFEGINT RELACIONS A ESTUDIANT ASSIGNATURA" << endl;
    cout << "Comment :=>> AFEGINT RELACIONS A PROFESSOR ASSIGNATURA" << endl;
    cout << "Comment :=>> =========================================" << endl;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            bool afegit;
            afegit = estudiantsAssignatura.afegeixRelacio(est[i], assig[j]);
            if (afegit)
            {
                cout << "Comment :=>> CORRECTE: HEU AFEGIT RELACIO: ASSIGNATURA " << j << " a ESTUDIANT: " << i << endl;
                grade += 0.2;
            }
            afegit = professorsAssignatura.afegeixRelacio(prof[i], assig[j]);
            if (afegit && (((i + 1) * (j + 1)) >= 10))
                cout << "Comment :=>> ERROR: HEU AFEGIT MASSES RELACIONS, ASSIGNATURA: " << j << " a PROFESSOR: " << i << " No s'ha d'afegir, excedeix el nombre de relacions maxim" << endl;
            else
            {
                if (afegit)    cout << "Comment :=>> CORRECTE: HEU AFEGIT RELACIO ASSIGNATURA: " << j << " a PROFESSOR: " << i << endl;
                else cout << "Comment :=>> ERROR: NO HEU AFEGIT RELACIO ASSIGNATURA: " << j << " a PROFESSOR: " << i << endl;
                grade += 0.2;
            }
        }
    }
    
    cout << "Comment :=>> MOSTRANT ASSIGNATURES D'ESTUDIANTS" << endl;
    cout << "Comment :=>> ================================" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "Comment :=>> Assignatures de l'estudiant: " << est[i]->getNIU() << endl;
        estudiantsAssignatura.mostraRelacions(est[i]);
        grade += 0.2;
    }

    cout << "Comment :=>> MOSTRANT ESTUDIANTS D'ASSIGNATURES" << endl;
    cout << "Comment :=>> ==================================" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "Comment :=>> Estudiants de l'assignatura: " << assig[i]->getCodi() << endl;
        estudiantsAssignatura.mostraRelacions(assig[i]);
        grade += 0.2;
    }

    cout << "Comment :=>> MOSTRANT PROFESSORS D'ASSIGNATURES" << endl;
    cout << "Comment :=>> ==================================" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "Comment :=>> Professors de l'assignatura: " << assig[i]->getCodi() << endl;
        professorsAssignatura.mostraRelacions(assig[i]);
        grade += 0.2;
    }

    cout << "Comment :=>> MOSTRANT ASSIGNATURES DE PROFESSORS" << endl;
    cout << "Comment :=>> ===================================" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "Comment :=>> Assignatures del professor: " << prof[i]->getNIU() << endl;
        professorsAssignatura.mostraRelacions(prof[i]);
        grade += 0.2;
    }

    for (int i = 0; i < 3; i++)
    {
        delete est[i];
        delete assig[i];
        delete prof[i];
    }
    
    grade += 1;

    if (valid)
        cout << "Comment :=>> Final del test sense errors" << endl;
    if (grade < 0)
        grade = 0;
    cout << endl << "Grade :=>> " << grade << endl;

    return 0;

}
