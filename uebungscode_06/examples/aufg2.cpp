#include <misc/zeitmesser.hpp>
#include <misc/schnellsort.hpp>
#include <misc/hilfsfunktionen.hpp>
#include <mergesort.hpp>
#include <iostream>
#include <algorithm>

int messen_schnell(const int& zahlen){
  misc::Zeitmesser zm;

  std::vector<int> bsp_zahlen(zahlen);
  misc::fuelle_zufaellig(bsp_zahlen);

  zm.start();
  misc::schnellsort(bsp_zahlen);
  zm.stop();
  return zm.get_microseconds();
}

int messen_merge(const int& zahlen){

  misc::Zeitmesser zm;

  std::vector<int> bsp_zahlen(zahlen);
  misc::fuelle_zufaellig(bsp_zahlen);


  zm.start();
  mergesort(bsp_zahlen);
  zm.stop();
  return zm.get_microseconds();

}

int main() {
  int zahlen = 100000;

  std::cout << "Schnellsort: " << messen_schnell(zahlen) << std::endl;
  std::cout << "Mergesort: " << messen_merge(zahlen) << std::endl;
}
