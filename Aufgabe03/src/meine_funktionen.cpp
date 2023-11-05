#include <meine_funktionen.hpp>
#include <iostream>


// Die Funktionen ohne von Nutzer angegebene toleranzwert
double sinus(double x){
    /*Berechnung von Sinus*/
    double sinus = 0;
    double summand = x;
    double zaehler_helfer = 1;
    double klein = 1e-10;

    while (summand > klein || -summand > klein){
        sinus += summand;
        summand = -(summand * x * x) / ((zaehler_helfer+1)*(zaehler_helfer+2));
        zaehler_helfer +=2;
    }
    return sinus;
}


// Die Funktionen mit von Nutzer angegebener toleranzwert
double sinus(double x, double toleranzwert){
    /*Berechnung von Sinus*/
    double sinus = 0;
    double summand = x;
    double zaehler_helfer = 1;

    while (summand > toleranzwert || -summand > toleranzwert){
        sinus += summand;
        summand = -(summand * x * x) / ((zaehler_helfer+1)*(zaehler_helfer+2));
        zaehler_helfer +=2;
    }
    return sinus;
}


// kosinus


// Die Funktionen ohne von Nutzer angegebene toleranzwert
double kosinus(double x){
    /*Berechnung von Kosinus*/
    double kosinus = 0;
    double summand = 1;
    double zaehler_helfer = 1;
    double klein = 1e-30;

    while (summand > klein || -summand > klein){
        kosinus += summand;
        summand = -(x * x * summand) / ((zaehler_helfer+1)*(zaehler_helfer));
        zaehler_helfer +=2;
    }
    return kosinus;
}



// Die Funktionen mit von Nutzer angegebener toleranzwert
double kosinus(double x, double toleranzwert){
    /*Berechnung von Kosinus*/
    double kosinus = 0;
    double summand = 1;
    double zaehler_helfer = 1;

    while (summand > toleranzwert || -summand > toleranzwert){
        kosinus += summand;
        summand = -(x * x * summand) / ((zaehler_helfer+1)*(zaehler_helfer));
        zaehler_helfer +=2;
    }
    return kosinus;
}


// Tangens


// Die Funktionen ohne von Nutzer angegebene toleranzwert
double tangens(double x){
    double sinus_wert = sinus(x);
    double kosinus_wert = kosinus(x);

    if (kosinus_wert != 0){
        return sinus_wert/kosinus_wert;
    } else {return -1;}
}

// Die Funktionen mit von Nutzer angegebener toleranzwert
double tangens(double x, double toleranzwert){
    double sinus_wert = sinus(x, toleranzwert);
    double kosinus_wert = kosinus(x, toleranzwert);

    if (kosinus_wert != 0){
        return sinus_wert/kosinus_wert;
    } else {return -1;}
}

// Kotangens


// Die Funktionen ohne von Nutzer angegebene toleranzwert
double kotangens(double x){
    double sinus_wert = sinus(x);
    double kosinus_wert = kosinus(x);

    if (kosinus_wert != 0){
        return sinus_wert/kosinus_wert;
    } else {return -1;}
}

// Die Funktionen mit von Nutzer angegebener toleranzwert
double kotangens(double x, double toleranzwert){
    double sinus_wert = sinus(x, toleranzwert);
    double kosinus_wert = kosinus(x, toleranzwert);

    if (sinus_wert != 0){
        return kosinus_wert/sinus_wert;
    } else {return -1;}
}