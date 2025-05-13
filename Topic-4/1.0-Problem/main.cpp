#include <iostream>
using namespace std;

int factorial(int n);


int main()
{
    float grade = 0.0;

    cout << "Comment :=>> =======================================================================================" << endl;
    int fact0 = factorial(0);
    cout << "Comment :=>> RESULTAT factorial 0: " << fact0 << endl;;
    if (fact0 == 1) {
        grade += 2;
    }

    int fact1 = factorial(1);
    cout << "Comment :=>> RESULTAT factorial 1: " << fact1 << endl;;
    if (fact1 == 1) {
        grade += 2;
    }

    int fact2 = factorial(2);
    cout << "Comment :=>> RESULTAT factorial 2: " << fact2 << endl;;
    if (fact2 == 2) {
        grade += 2;
    }

    int fact3 = factorial(3);
    cout << "Comment :=>> RESULTAT factorial 3: " << fact3 << endl;;
    if (fact3 == 6) {
        grade += 2;
    }

    int fact4 = factorial(4);
    cout << "Comment :=>> RESULTAT factorial 4: " << fact4 << endl;;
    if (fact4 == 24) {
        grade += 2;
    }

    if (grade == 10)
        cout << "Comment :=>> Final del test sense errors" << endl;

    cout << endl << "Grade :=>> " << grade << endl;

    return 0;
}
