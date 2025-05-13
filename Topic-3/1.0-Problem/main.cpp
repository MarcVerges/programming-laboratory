//
// Created by Marc Verges on 17/10/23.
//
#include <iostream>
#include "Hash.h"
using namespace std;

int main()
{
    try
    {
        float grade = 0.0;
        Hash h(20);
        const int MAXELEMENTS = 6;
        pair<string, string> vEntrada[MAXELEMENTS] = {
                pair<string,string>("Hola", "Es una salutacio."),
                pair<string,string>("Adeu","Es un comiat."),
                pair<string,string>("Dia", "Es un periode de 24 hores."),
                pair<string,string>("Mes", "Es un periode de entre 28 i 31 dies."),
                pair<string,string>("Any", "Es un periode de 12 mesos."),
                pair<string,string>("ornitorinc", "Animal."),
        };

        for (int i = 0; i < MAXELEMENTS; i++)
        {
            h.insert(vEntrada[i].first, vEntrada[i].second);
        }

        cout << "=====DICCIONARI=====" << endl;
        h.mostra();

        cout << "Definicio de caleidoscopi es: " << h["caleidoscopi"] <<endl;
        cout << "Definicio d'eina es: " << h["eina"] <<endl;

        cout << "=====DICCIONARI DESPRES CERCA=====" << endl;
        h.mostra();
        cout << "Definicio de Any es: " << h["Any"] << endl;

        cout << "Trobem Setmana?: " << h.find("Setmana") << endl;

        cout << "=====DICCIONARI DESPRES FIND=====" << endl;
        h.mostra();

        cout << "Definicio de Setmana es: " << h["Setmana"] << endl;
        cout << "=====DICCIONARI DESPRES OPERATOR[]=====" << endl;
        h.mostra();

        if (h.find("Setmana") == 1) grade = 10;

        if (grade == 10)
            cout << "Comment :=>> Final del test sense errors" << endl;
        else
            cout << "Comment :=>> El resultat no es correcte" << endl;


        cout << endl << "Grade :=>> " << grade << endl;
    }
    catch (const char* msg)
    {
        cout << msg;
    }
    catch (std::out_of_range)
    {
        cout << "Intentes accedir a una posicio fora del vector";
    }
    return 0;
}
