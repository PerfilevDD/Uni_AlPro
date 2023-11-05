#include <meine_funktionen.hpp>
#include <iostream>

using namespace std;

int main() {

    // TODO 
    int grad;
    double zahl;
    double genauigkeit;
    double pi = 3.141592653589793238462643383279502884197169399375105820974944;

    cout << "Grad ";
    cin >> grad; // Bekommen Grad, der berechnet wird
    zahl = grad * pi / 180; // Grad wird in rad konventiert

    cout << "Genauigkeit: ";
    cin >> genauigkeit;

    cout << "Sinus von Grad " << grad << " ist gleich " << sinus(zahl, genauigkeit) << endl;
    cout << "Cosinus von Grad " << grad << " ist gleich " << kosinus(zahl, genauigkeit) << endl;

    // Pruefen ob kosinus nicht null ist, falls Kosinus null ist,\
    // Dann exestiert kein Tangens
    cout << "Tangens von Grad " << grad << " ist gleich " << tangens(zahl, genauigkeit) << endl;


    // Pruefen ob sinus nicht null ist, falls sinus null ist,\
    // Dann exestiert kein Kotangens
    cout << "Kotangens von Grad " << grad << " ist gleich " << kotangens(zahl, genauigkeit) << endl;

    return 0;
}
