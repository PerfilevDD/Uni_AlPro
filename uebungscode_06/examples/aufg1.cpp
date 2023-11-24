#include <mergesort.hpp>
#include <misc/hilfsfunktionen.hpp>
#include <vector>
#include <iostream>

int main() {
  // Erstellen ein Array und fuegen ran. Zahlen hin
  std::vector<int> bsp_zahlen(10);
  misc::fuelle_zufaellig(bsp_zahlen);
  misc::drucke_array(bsp_zahlen);
<<<<<<< HEAD
  
  // Erstellen ein sortiertes Array
  std::vector<int> merg_sorted = mergesort(bsp_zahlen);
  misc::drucke_array(merg_sorted);
=======
  std::cout << std::endl << std::endl << std::endl;
  mergesort(bsp_zahlen);
  misc::drucke_array(bsp_zahlen);
>>>>>>> sgitlab/AlPro_06_Kohn
}
