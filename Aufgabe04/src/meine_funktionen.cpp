#include <meine_funktionen.hpp>

#include <iostream>

using namespace std;


// Die Funktionen ohne von Nutzer angegebene toleranzwert
double sinus(double& x){
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
double sinus(double& x, double& toleranzwert){
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


// Cosinus


// Die Funktionen ohne von Nutzer angegebene toleranzwert
double cosinus(double& x){
    /*Berechnung von Kosinus*/
    double cosinus = 0;
    double summand = 1;
    double zaehler_helfer = 1;
    double klein = 1e-30;

    while (summand > klein || -summand > klein){
        cosinus += summand;
        summand = -(x * x * summand) / ((zaehler_helfer+1)*(zaehler_helfer));
        zaehler_helfer +=2;
    }
    return cosinus;
}



// Die Funktionen mit von Nutzer angegebener toleranzwert
double cosinus(double& x, double& toleranzwert){
    /*Berechnung von Kosinus*/
    double cosinus = 0;
    double summand = 1;
    double zaehler_helfer = 1;

    while (summand > toleranzwert || -summand > toleranzwert){
        cosinus += summand;
        summand = -(x * x * summand) / ((zaehler_helfer+1)*(zaehler_helfer));
        zaehler_helfer +=2;
    }
    return cosinus;
}