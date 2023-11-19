#include <mergesort.hpp>
#include <misc/hilfsfunktionen.hpp>
#include <vector>
#include <iostream>

int main() {
  std::vector<int> bsp_zahlen(10);
  misc::fuelle_zufaellig(bsp_zahlen);
  misc::drucke_array(bsp_zahlen);
  
  std::vector<int> merg_sorted = mergesort(bsp_zahlen);
  misc::drucke_array(merg_sorted);
}
