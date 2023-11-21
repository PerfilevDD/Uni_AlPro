#include <mergesort.hpp>
#include <misc/hilfsfunktionen.hpp>
#include <vector>
#include <iostream>

int main() {
  // Erstellen ein Array und fuegen ran. Zahlen hin
  std::vector<int> bsp_zahlen(10);
  misc::fuelle_zufaellig(bsp_zahlen);
  misc::drucke_array(bsp_zahlen);
  
  // Erstellen ein sortiertes Array
  std::vector<int> merg_sorted = mergesort(bsp_zahlen);
  misc::drucke_array(merg_sorted);
}
