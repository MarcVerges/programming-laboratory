#include "TreeRB.hpp"
#include <vector>

bool IgualFitxers(string nomF1, string nomF2, string nomFRes)
{
    ifstream f1, f2;
    f1.open(nomF1);
    f2.open(nomF2);
    bool iguals = true;

    if (f1.is_open() && f2.is_open())
    {
        ofstream fitxCompara(nomFRes, ios::out);
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
                fitxCompara << flush << "Error num " << cont << " a linia " << linia << endl << flush;
                iguals = false;
            }
        }
        if (!f1.eof() && f2.eof())
        {
            fitxCompara << "Fitxer " << nomF2 << " es mes curt que " << nomF1 << endl;
        }
        if (!f2.eof() && f1.eof())
        {
            fitxCompara << "Fitxer " << nomF1 << " es mes curt que " << nomF2 << endl;
        }
        fitxCompara.close();
        f1.close();
        f2.close();
    }
    else
    {
        throw "Error al fitxer de sortida al comparar.";
    }
    return iguals;
}


int main()
{
    try
    {
        float grade = 0;
        bool valid = true;

        cout << "Comment :=>> ==============================" << endl;
        cout << "Comment :=>> === CREANT ARBRE RED BLACK ===" << endl;
        cout << "Comment :=>> ==============================" << endl;
        TreeRB<int> tRB;
        cout << tRB;
        int MAXVALS = 3;
        vector<int> valors = { 35,15,80 };

        for (int i = 0; i < MAXVALS; i++)
        {
            tRB.insert(valors[i]);
        }

        cout << "Comment :=>> ==============================" << endl;
        cout << "Comment :=>> === ESCRIU ARBRE RED BLACK ===" << endl;
        cout << "Comment :=>> ==============================" << endl;
        cout << tRB;

        MAXVALS = 4;
        valors = { 92, 10, 45, 105 };
        for (int i = 0; i < MAXVALS; i++)
        {
            tRB.insert(valors[i]);
        }

        cout << "Comment :=>> ==============================" << endl;
        cout << "Comment :=>> === ESCRIU ARBRE RED BLACK ===" << endl;
        cout << "Comment :=>> ==============================" << endl;
        cout << tRB;

        ofstream fTreeColor;
        fTreeColor.open("ResTreeColor.txt");
        if (fTreeColor.is_open())
        {
            fTreeColor << tRB;
            fTreeColor.close();
        }
        ofstream fTreeColorComp;
        if (IgualFitxers("ResTreeColor.txt", "ResTreeColorEsp.txt", "ResTreeColorComp.txt"))
        {
            cout << "Comment :=>> RB Tree amb cas Recolorejar BEN CONSTRUIT OK ....................... " << endl;
            grade=grade+2;
        }
        else
        {
            cout << "Comment :=>> ERROR CONSTRUCCIO RB Tree amb cas Recolorejar ....................... " << endl;
            valid = false;
        }

        cout << "Comment :=>> =================================" << endl;
        cout << "Comment :=>> === Insert 9 esquerre-esquerre===" << endl;
        cout << "Comment :=>> =================================" << endl;

        MAXVALS = 1;
        valors = { 9 };
        for (int i = 0; i < MAXVALS; i++)
        {
            tRB.insert(valors[i]);
        }

        cout << "Comment :=>> ==============================" << endl;
        cout << "Comment :=>> === ESCRIU ARBRE RED BLACK ===" << endl;
        cout << "Comment :=>> ==============================" << endl;
        cout << tRB;

        ofstream fTreeEsqEsq;
        fTreeEsqEsq.open("ResTreeEsqEsq.txt");
        if (fTreeEsqEsq.is_open())
        {
            fTreeEsqEsq << tRB;
            fTreeEsqEsq.close();
        }
        ofstream fTreeEsqEsqComp;
        if (IgualFitxers("ResTreeEsqEsq.txt", "ResTreeEsqEsqEsp.txt", "ResTreeEsqEsqComp.txt"))
        {
            cout << "Comment :=>> RB Tree amb cas esquerre-esquerre BEN CONSTRUIT OK ....................... " << endl;
            grade=grade+2;
        }
        else
        {
            cout << "Comment :=>> ERROR CONSTRUCCIO RB Tree amb cas esquerre-esquerre ....................... " << endl;
            valid = false;
        }

        cout << "Comment :=>> ===============================" << endl;
        cout << "Comment :=>> === Insert 100 dret-esquerre==" << endl;
        cout << "Comment :=>> ===============================" << endl;

        MAXVALS = 1;
        valors = { 100 };
        for (int i = 0; i < MAXVALS; i++)
        {
            tRB.insert(valors[i]);
        }

        cout << "Comment :=>> ==============================" << endl;
        cout << "Comment :=>> === ESCRIU ARBRE RED BLACK ===" << endl;
        cout << "Comment :=>> ==============================" << endl;

        cout << tRB;

        ofstream fTreeDretEsq;
        fTreeDretEsq.open("ResTreeDretEsq.txt");
        if (fTreeDretEsq.is_open())
        {
            fTreeDretEsq << tRB;
            fTreeDretEsq.close();
        }
        ofstream fTreeDretEsqComp;
        if (IgualFitxers("ResTreeDretEsq.txt", "ResTreeDretEsqEsp.txt", "ResTreeDretEsqComp.txt"))
        {
            cout << "Comment :=>> RB Tree amb cas dret-esquerre BEN CONSTRUIT OK ....................... " << endl;
            grade=grade+2;
        }
        else
        {
            cout << "Comment :=>> ERROR CONSTRUCCIO RB Tree amb cas dret-esquerre ....................... " << endl;
            valid = false;
        }


        MAXVALS = 2;
        valors = { 20,27 };
        for (int i = 0; i < MAXVALS; i++)
        {
            tRB.insert(valors[i]);
        }

        cout << "Comment :=>> ==============================" << endl;
        cout << "Comment :=>> === ESCRIU ARBRE RED BLACK ===" << endl;
        cout << "Comment :=>> ==============================" << endl;

        cout << tRB;

        ofstream fTreeDretDret;
        fTreeDretDret.open("ResTreeDretDret.txt");
        if (fTreeDretDret.is_open())
        {
            fTreeDretDret << tRB;
            fTreeDretDret.close();
        }
        ofstream fTreeDretDretComp;
        if (IgualFitxers("ResTreeDretDret.txt", "ResTreeDretDretEsp.txt", "ResTreeDretDretComp.txt"))
        {
            cout << "Comment :=>> RB Tree amb cas dret-dret BEN CONSTRUIT OK ....................... " << endl;
            grade = grade + 2;
        }
        else
        {
            cout << "Comment :=>> ERROR CONSTRUCCIO RB Tree amb cas dret-dret ....................... " << endl;
            valid = false;
        }

        MAXVALS = 2;
        valors = { 40,43 };
        for (int i = 0; i < MAXVALS; i++)
        {
            tRB.insert(valors[i]);
        }

        cout << "Comment :=>> ==============================" << endl;
        cout << "Comment :=>> === ESCRIU ARBRE RED BLACK ===" << endl;
        cout << "Comment :=>> ==============================" << endl;

        cout << tRB;

        ofstream fTreeEsqDret;
        fTreeEsqDret.open("ResTreeEsqDret.txt");
        if (fTreeEsqDret.is_open())
        {
            fTreeEsqDret << tRB;
            fTreeEsqDret.close();
        }
        ofstream fTreeEsqDretComp;
        if (IgualFitxers("ResTreeEsqDret.txt", "ResTreeEsqDretEsp.txt", "ResTreeEsqDretComp.txt"))
        {
            cout << "Comment :=>> RB Tree amb cas esquerre-dret BEN CONSTRUIT OK ....................... " << endl;
            grade = grade + 2;
        }
        else
        {
            cout << "Comment :=>> ERROR CONSTRUCCIO RB Tree amb cas esquerre-dret ....................... " << endl;
            valid = false;
        }
        cout << endl;

        if (valid)
            cout << "Comment :=>> Final del test sense errors" << endl;
        if (grade < 0)
            grade = 0;
        cout << endl << "Grade :=>> " << grade << endl;

        return 0;
    }
    catch (std::bad_alloc)
    {
        cout << "Comment :=>> error allocatant memoria:" << endl;
    }
    catch (const std::out_of_range& oor) {
        std::cerr << "Comment :=>> Out of Range error: " << oor.what() << '\n';
    }
    catch (const char* msg)
    {
        cout << msg << endl;
    }
}
