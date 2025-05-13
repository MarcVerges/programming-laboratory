#include "Heap.hpp"
#include <string>

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

    //Proves de HEaps
    Heap<int> mont;

    cout << "Comment :=>>==============================" << endl;
    cout << "Comment :=>>=======LLEGINT HEAP===========" << endl;
    cout << "Comment :=>>==============================" << endl;
    mont.read("heap.txt");

    cout << "Comment :=>>==============================" << endl;
    cout << "Comment :=>>=======ESCRIU HEAP============" << endl;
    cout << "Comment :=>>==============================" << endl;

    cout << mont;

    ofstream student_file;
    student_file.open("sortida_escriu_heap.txt");
    student_file << mont;
    student_file << endl;
    student_file.close();


    if (IgualFitxers("sortida_escriu_heap.txt", "sortida_escriu_heap_esperada.txt"))
    {
        cout << "Comment :=>> CORRECTE" << endl;
        grade+= 2.5;
    }
    else
    {
        cout << "Comment :=>> NO ES CORRECTE" << endl;
        valid = false;
    }

    cout << "Comment :=>>==============================" << endl;
    cout << "Comment :=>>=======INSERIM 12       ======" << endl;
    cout << "Comment :=>>==============================" << endl;

    mont.insert(12);
    cout << mont;

    ofstream student_file2;
    student_file2.open("sortida_inserir12.txt");
    student_file2 << mont;
    student_file2 << endl;
    student_file2.close();

    if (IgualFitxers("sortida_inserir12.txt", "sortida_inserir12_esperada.txt"))
    {
        cout << "Comment :=>> CORRECTE" << endl;
        grade += 2.5;
    }
    else
    {
        cout << "Comment :=>> NO ES CORRECTE" << endl;
        valid = false;
    }

    cout << "Comment :=>>==============================" << endl;
    cout << "Comment :=>>=======ESBORREM MIN     ======" << endl;
    cout << "Comment :=>>==============================" << endl;

    mont.delMin();
    cout << mont;

    ofstream student_file3;
    student_file3.open("sortida_esborrarmin.txt");
    student_file3 << mont;
    student_file3 << endl;
    student_file3.close();

    if (IgualFitxers("sortida_esborrarmin.txt", "sortida_esborrarmin_esperada.txt"))
    {
        cout << "Comment :=>> CORRECTE" << endl;
        grade += 2.5;
    }
    else
    {
        cout << "Comment :=>> NO ES CORRECTE" << endl;
        valid = false;
    }


    Heap<int> mont3;
    vector<int> v = { 10,21,15,30,24,25,29,70,48,27,26 };

    cout << "Comment :=>>=======VECTOR ABANS ORDRE=====" << endl;
    for (size_t i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ; ";
    }

    cout << endl;

    mont3.ordenar(v);



    cout << "=======VECTOR DESPRES ORDRE=====" << endl;
    for (size_t i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ; ";
    }
    cout << endl;

    ofstream student_file4;
    student_file4.open("ordenarvector.txt");
    for (size_t i = 0; i < v.size(); i++)
    {
        student_file4 << v[i] << " ; ";
    }
    student_file4 << endl;

    student_file4.close();

    if (IgualFitxers("ordenarvector.txt", "ordenarvector_esperada.txt"))
    {
        cout << "Comment :=>> CORRECTE" << endl;
        grade += 2.5;
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