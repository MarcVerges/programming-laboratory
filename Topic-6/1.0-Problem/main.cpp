#include "Tree.h"
#include <string>


bool IgualFitxers(const string& nomF1, const string& nomF2)
{
    ifstream f1,f2;
    f1.open(nomF1);
    f2.open(nomF2);
    bool iguals = true;

    if (f1.is_open() && f2.is_open())
    {
        int cont = 0, linia = 0;
        while (!f1.eof() && !f2.eof())
        {
            ++linia;
            string a, b;
            getline(f1, a);
            size_t pos;
            if ((pos = a.find_first_of(char(13))) < string::npos)
                a = a.substr(0, pos);
            getline(f2, b);
            if ((pos = b.find_first_of(char(13))) < string::npos)
                b = b.substr(0, pos);
            if (a != b)
            {
                ++cont;
                iguals = false;
            }
        }
        if (!f1.eof() && f2.eof())
        {
            cout << "Comment :=>> ==== Fitxer : " << nomF2 << " es mes curt que " << nomF1 << endl;
        }
        if (!f2.eof() && f1.eof())
        {
            cout << "Comment :=>> ==== Fitxer : " << nomF1 << " es mes curt que " << nomF2 << endl;
        }
    }
    else
    {
        throw "Error al fitxer de sortida al comparar.";
    }
    return iguals;
}

int main()
{

    float grade = 0.0;
    bool valid = true;

    cout << endl << endl;
    cout << "Comment :=>>            Iniciant test inicial arbres              " << endl;
    cout << "Comment :=>> ==================================================================" << endl;
    cout << "Comment :=>> ==================================================================" << endl;

    cout << "=======================" << endl;
    cout << "IMPRIMINT ARBRE ORDENAT" << endl;
    cout << "=======================" << endl;
    Tree<int> tOrd("arbreOrdenat.txt");

    ofstream student_file;
    student_file.open("salida_dada.txt");
    student_file << tOrd;
    student_file.close();


    if (IgualFitxers("salida_esperada.txt", "salida_dada.txt"))
    {
        cout << "Comment :=>> CORRECTE" << endl;
        grade = 10.0;
    }
    else
    {
        cout << "Comment :=>> NO ES CORRECTE" << endl;
        valid = false;
    }


    cout << "Comment :=>> =====================================================================" << endl;
    if (valid)
        cout << "Comment :=>> Final del test sense errors" << endl;

    cout << "Comment :=>> " << endl << "Grade :=>> " << grade << endl;

    return 0;
}


