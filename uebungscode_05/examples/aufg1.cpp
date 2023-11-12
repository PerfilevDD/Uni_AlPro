#include <minsort_in_place.hpp>
#include <vector>
#include <algorithm>
#include <functional>
#include <ctime>
#include <iostream>
#include <iomanip>

//
// Hilfsfunktionen die wir nur für diese Demo benutzen
//

// Die Funktion befüllt ein Array mit zufälligen Zahlen
void fuelle_zufaellig(std::vector<int>& in) {
  // Konfiguriere den Zufallszahlengenerator
  std::srand(unsigned(std::time(nullptr)));
  // Erstelle ein Funktionsobjekt welches Zufallszahlen zwischen 0 und 10000 generiert
  std::function<size_t(void)> zufallsgenerator = [] (void) -> size_t { return std::rand() % 10000; };
  // Befülle das Array mithilfe des Funktionsobjekts
  std::generate(in.begin(), in.end(), zufallsgenerator);
}

// Die Funktion druckt ein Array aus
void drucke_array(const std::vector<int>& in) {
  for(const int& zahl: in) {
    std::cout << std::setw(5) << zahl;
  }
  std::cout << std::endl;
}

int main() {
  std::vector<int> bsp_zahlen(4000);
  fuelle_zufaellig(bsp_zahlen);
  drucke_array(bsp_zahlen);
  
}
