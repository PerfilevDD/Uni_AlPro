#include <misc/zeitmesser.hpp>
#include <misc/schnellsort.hpp>
#include <misc/hilfsfunktionen.hpp>
#include <mergesort.hpp>
#include <minsort_in_place.hpp>
#include <iostream>
#include <algorithm>
<<<<<<< HEAD

int messen_schnell(const int &zahlen)
{
  // Funktion um Zeit des Algorithmus zu messen
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
  // Funktion um Zeit des Algorithmus zu messen
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
  // Funktion um Zeit des Algorithmus zu messen
  misc::Zeitmesser zm;

  std::vector<int> bsp_zahlen(zahlen);
  misc::fuelle_zufaellig(bsp_zahlen);

  zm.start();
  minsort(bsp_zahlen);
  zm.stop();
  return zm.get_microseconds();
}

void druecken(std::vector<int>& arr){
  // Drucken das Array
  for (const int zahl : arr){
    std::cout << zahl << " " << std::endl;
  }
}

int main()
{
  int zahlen = 1000000;
  int schritt = 5;

  // Vektoren um die Zeit eines Algorithmus zu speichern
  std::vector<int> schnell_zeiten, merge_zeiten, minsort_zeiten, alle_zahlen;

  for (int i = 10; i <= zahlen; i = i * schritt)
  {
    // Untersuchen die Zeit eines Algotirhmus und speichern sie in Array
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
=======
#include <mergesort.hpp>
#include <minsort.hpp>

int main() {
    const int start = 10; // Startwert
    const int max = 30010; // Maximale Größe
    const int schritt = 10000; // Schrittgröße für Schleife

    misc::Zeitmesser zeit;

          /* For Schleife die zuerst bei 10 Elementen in einem Array startet und dann die Anzahl der
          Elemente um 10000 pro Schritt erhöht bis es die Maximale Größe von 30010 Elementen erreicht */
    for (int i = start; i <= max; i = i + schritt) { 
        std::vector<int> bsp_zahlen1(i);
        std::vector<int> bsp_zahlen2(i);
        std::vector<int> bsp_zahlen3(i);

        misc::fuelle_zufaellig(bsp_zahlen1); // Arrays werden mit zufällig generierten Zahlen gefüllt
        misc::fuelle_zufaellig(bsp_zahlen2);
        misc::fuelle_zufaellig(bsp_zahlen3);

        // Schnellsort
        zeit.start();
        misc::schnellsort(bsp_zahlen1);
        zeit.stop();
        std::cout << "Schnellsort mit " << i << " Zahlen: " << zeit.get_microseconds() << std::endl;

        // Mergesort
        zeit.start();
        mergesort(bsp_zahlen2);
        zeit.stop();
        std::cout << "Mergesort mit " << i << " Zahlen: " << zeit.get_microseconds() << std::endl;

        // Minsort
        zeit.start();
        bsp_zahlen3 = minsort_in_place(bsp_zahlen3);
        zeit.stop();
        std::cout << "Minsort mit " << i << " Zahlen: " << zeit.get_microseconds() << std::endl;
        std::cout << std::endl;
    }

    return 0;
>>>>>>> sgitlab/AlPro_06_Kohn
}

















// clang++ -std=c++17 -I./include src/hilfsfunktionen.cpp src/schnellsort.cpp src/zeitmesser.cpp src/mergesort.cpp src/minsort.cpp examples/aufg2.cpp -o build/aufg2