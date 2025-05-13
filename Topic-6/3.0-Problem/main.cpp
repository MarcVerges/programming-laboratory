
#include "TreeRB.hpp"
#include <vector>

bool IgualFitxers(string nomF1, string nomF2)
{
    ifstream f1, f2;
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
            int pos;
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

    cout << "Comment :=>>==============================" << endl;
    cout << "Comment :=>>=== CREANT ARBRE RED BLACK ===" << endl;
    cout << "Comment :=>>==============================" << endl;
    TreeRB<int> tRB;
    cout <<tRB;
    int MAXVALS = 3;
    vector<int> valors = { 35,15,80 };

    for (int i = 0; i < MAXVALS; i++)
    {
        tRB.insert(valors[i]);
    }

    cout << "Comment :=>>==============================" << endl;
    cout << "Comment :=>>=== ESCRIU ARBRE RED BLACK ===" << endl;
    cout << "Comment :=>>==============================" << endl;
    cout << tRB;

    ofstream student_file_ej1;
    student_file_ej1.open("redblack_sol1.txt");
    student_file_ej1<< tRB;
    student_file_ej1 << endl;
    student_file_ej1.close();

    if (IgualFitxers("redblack_sol1.txt", "redblack_ej1.txt"))
    {
        cout << "Comment :=>> CORRECTE" << endl;
        grade+= 5.0;
    }
    else
    {
        cout << "Comment :=>> NO ES CORRECTE" << endl;
        valid = false;
    }



    MAXVALS = 4;
    valors = { 92, 10, 45, 105};
    for (int i = 0; i < MAXVALS; i++)
    {
        tRB.insert(valors[i]);
    }

    cout << "Comment :=>>==============================" << endl;
    cout << "Comment :=>>=== ESCRIU ARBRE RED BLACK ===" << endl;
    cout << "Comment :=>>==============================" << endl;
    cout << tRB;

    ofstream student_file_ej2;
    student_file_ej2.open("redblack_sol2.txt");
    student_file_ej2 << tRB;
    student_file_ej2 << endl;
    student_file_ej2.close();

    if (IgualFitxers("redblack_sol2.txt", "redblack_ej2.txt"))
    {
        cout << "Comment :=>> CORRECTE" << endl;
        grade+= 5.0;
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