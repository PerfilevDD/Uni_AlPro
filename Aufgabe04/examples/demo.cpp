#include <meine_funktionen.hpp>
#include <iostream>

using namespace std;

int main() {

    int grad;
    double zahl;
    double genauigkeit;
    double pi = 3.141592653589793238462643383279502884197169399375105820974944;

    cout << "Grad ";
    cin >> grad; // Bekommen Grad, der berechnet wird
    zahl = grad * pi / 180; // Grad wird in rad konventiert

    cout << "Genauigkeit: ";
    cin >> genauigkeit;

    double sin_zahl = sinus(zahl, genauigkeit);
    double cos_zahl = kosinus(zahl, genauigkeit);

    cout << "Sinus von Grad " << grad << " ist gleich " << sin_zahl << endl;
    cout << "Cosinus von Grad " << grad << " ist gleich " << cos_zahl << endl;

    // Pruefen ob kosinus nicht null ist, falls Kosinus null ist,\
    // Dann exestiert kein Tangens
    if (cos_zahl != 0){
        cout << "Tangens von Grad " << grad << " ist gleich " << sin_zahl/cos_zahl << endl;
    }

    // Pruefen ob sinus nicht null ist, falls sinus null ist,\
    // Dann exestiert kein Kotangens
    if (sin_zahl != 0){
        cout << "Kotangens von Grad " << grad << " ist gleich " << cos_zahl/sin_zahl << endl;
    }

    return 0;
}
