#include <misc/zeitmesser.hpp>
#include <misc/schnellsort.hpp>
#include <misc/hilfsfunktionen.hpp>
#include <iostream>
#include <algorithm>
#include <mergesort.hpp>
#include <minsort.hpp>

int main() {
    const int start = 10; // Startwert
    const int max = 30010; // Maximale Größe
    const int schritt = 10000; // Schrittgröße für Schleife

    misc::Zeitmesser zeit;

          /* For Schleife die zuerst bei 10 Elementen in einem Array starten und dann die Anzahl der
             Elemente um 10000 pro Schritt erhöht bis es die Maximale Größe 30010 erreicht */
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
}