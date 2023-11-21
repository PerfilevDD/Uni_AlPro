#include <misc/zeitmesser.hpp>
#include <misc/schnellsort.hpp>
#include <misc/hilfsfunktionen.hpp>
#include <mergesort.hpp>
#include <minsort_in_place.hpp>
#include <iostream>
#include <algorithm>

int messen_schnell(const int &zahlen)
{
  misc::Zeitmesser zm;

  std::vector<int> bsp_zahlen(zahlen);
  misc::fuelle_zufaellig(bsp_zahlen);

  zm.start();
  misc::schnellsort(bsp_zahlen);
  zm.stop();
  return zm.get_microseconds();
}

int messen_merge(const int &zahlen)
{

  misc::Zeitmesser zm;

  std::vector<int> bsp_zahlen(zahlen);
  misc::fuelle_zufaellig(bsp_zahlen);

  zm.start();
  mergesort(bsp_zahlen);
  zm.stop();
  return zm.get_microseconds();
}

int messen_minsort(const int &zahlen)
{

  misc::Zeitmesser zm;

  std::vector<int> bsp_zahlen(zahlen);
  misc::fuelle_zufaellig(bsp_zahlen);

  zm.start();
  minsort(bsp_zahlen);
  zm.stop();
  return zm.get_microseconds();
}

void druecken(std::vector<int>& arr){
  for (const int zahl : arr){
    std::cout << zahl << " " << std::endl;
  }
}

int main()
{
  int zahlen = 100000;
  int schritt = 10;
  std::vector<int> schnell_zeiten, merge_zeiten, minsort_zeiten, alle_zahlen;

  for (int i = 10; i <= zahlen; i = i * schritt)
  {
    schnell_zeiten.push_back(messen_schnell(i));
    merge_zeiten.push_back(messen_merge(i));
    minsort_zeiten.push_back(messen_minsort(i));
    alle_zahlen.push_back(i);
  }

  std::cout << "Schnellsort: " << std::endl;
  druecken(schnell_zeiten);

  std::cout << "Mergesort: " << std::endl;
  druecken(merge_zeiten);

  std::cout << "Minsort: " << std::endl;
  druecken(minsort_zeiten);

  std::cout << "Alle Zahlen: " << std::endl;
  druecken(alle_zahlen);
}
