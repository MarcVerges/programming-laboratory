#include <list>
#include <string>

#include <iostream>
using namespace std;

bool cercaRecursiva(list<int>& l, list<int>::iterator& itL, int valor);
bool cerca(list<int>& l, int valor);
void escriuLlistaInversaRec(list<string>& l, list<string>::iterator& itL, list<string>& lRes);
void escriuLlistaInversa(list<string>& l, list<string>& lRes);
void escriuLlistaInversaIt(list<string>& l, list<string>& lRes);

int main()
{

    float grade = 0.0;
    bool valid = true;

    cout << endl << endl;
    cout << "Comment :=>>     Iniciant test dels exercicis de cerca i llista inversa        " << endl;
    cout << "Comment :=>> ==================================================================" << endl;
    cout << "Comment :=>>  " << endl << endl;

    cout << "Comment :=>> ================== EXERCICI CERCA RECURSIVA ======================" << endl;

    list<int> l = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    cout << "Comment :=>> RESULTAT DE CERCA 5 A LA LLISTA { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 } " << endl;;
    if (cerca(l, 5)) {
        cout << "Comment :=>> CORRECTE: Trobat 5 a la llista " << endl;
        grade += 2.5;
    }
    else
    {
        cout << "Comment :=>> ERROR RESULTAT FINAL    ....................... " << endl;
        cout << "Comment :=>> No trobat element 5 a la llista ............... " << endl;
        valid = false;
    }

    cout << "Comment :=>> RESULTAT DE CERCA 12 A LA LLISTA { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }" << endl;;
    if (cerca(l, 12)) {
        cout << "Comment :=>> ERROR RESULTAT FINAL    ....................... " << endl;
        cout << "Comment :=>> Trobat element 12 a la llista ................. " << endl;
        valid = false;
    }
    else {
        cout << "Comment :=>> CORRECTE: No trobat 12 a la llista " << endl;
        grade += 2.5;
    }
    cout << "Comment :=>>  " << endl << endl;

    cout << "Comment :=>> ======== EXERCICI LLISTA INVERSA AMB RECURSIVITAT ================" << endl;
    cout << "Comment :=>> {Anna,Carles,David,Francesc,Joan,Jordi,Marc,Marta,Monica,Silvia} " << endl;
    list<string> lNoms    = { "Anna"    ,"Carles"  ,"David"   ,"Francesc","Joan"    ,"Jordi"   ,"Marc"    ,"Marta"   ,"Monica"  ,"Silvia" };
    list<string> lNomsInv = { "Silvia"  ,"Monica"  ,"Marta"   ,"Marc"    ,"Jordi"   ,"Joan"    ,"Francesc","David"   ,"Carles"  ,"Anna"   };
    list<string> lNomsRes   = {};
    list<string> lNomsResIt = {};
    cout << "Comment :=>> ==================================================================" << endl;
    escriuLlistaInversa(lNoms, lNomsRes);
    if ((lNomsRes != lNomsInv)) {
        cout << "Comment :=>> ERROR RESULTAT FINAL    ....................... " << endl;
        cout << "Comment :=>> Valor esperat:          ....................... " << endl;
        cout << "Comment :=>> {Silvia,Monica,Marta,Marc,Jordi,Joan,Francesc,David,Carles,Anna} " << endl;
        valid = false;
    }
    else {
        cout << "Comment :=>> CORRECTE: Llista resultant invertida " << endl;
        grade += 2.5;
    }
    cout << "Comment :=>>  " << endl << endl;

    cout << "Comment :=>> ======== EXERCICI LLISTA INVERSA ITERATIVA =======================" << endl;
    cout << "Comment :=>> ==================================================================" << endl;
    escriuLlistaInversaIt(lNoms, lNomsResIt);
    if ((lNomsResIt != lNomsInv)) {
        cout << "Comment :=>> ERROR RESULTAT FINAL    ....................... " << endl;
        cout << "Comment :=>> Valor esperat:          ....................... " << endl;
        cout << "Comment :=>> {Silvia,Monica,Marta,Marc,Jordi,Joan,Francesc,David,Carles,Anna} " << endl;
        valid = false;
    }
    else {
        cout << "Comment :=>> CORRECTE: Llista resultant invertida " << endl;
        grade += 2.5;
    }

    cout << "Comment :=>> ==================================================================" << endl;
    if (valid)
        cout << "Comment :=>> Final del test sense errors" << endl;
    if (grade < 3)
        grade = 0;

    cout << "Comment :=>> " << endl << "Grade :=>> " << grade << endl;

    return 0;
}

