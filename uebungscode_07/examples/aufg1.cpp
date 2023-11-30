#include <simpler_graph/simpler_graph.hpp>

#define FMT_HEADER_ONLY  // Dieses Makro ist nötig, um die Bibliothek simpel einzubinden
#include <fmt/core.h>    // Muss eingebunden werden um {fmt} zu verwenden
#include <fmt/ranges.h>  // Muss zur Ausgabe von Arrays eingebunden werden

#include <vector>  // Stellt dynamische Arrays zur Verfügung

int main() {
    SimplerGraph::SimplerGraph sg(6);  // Inizialisieren Graphen und geben die Anzahl der Knoten


    // Initialisieren Kanten
    sg.erstelleKanten(0, 1);
    sg.erstelleKanten(0, 4);
    sg.erstelleKanten(1, 2);
    sg.erstelleKanten(1, 3);
    sg.erstelleKanten(4, 5);
    
    fmt::print("Alle Kanten, die exestieren\n");
    sg.drucke();  // Drucken die Knoten mit der Verbindung
    
  // Breitensuche starten, z.B. vom Knoten 0
  std::vector<size_t> breitensuche_resultat = sg.breitensuche(0);

  // Das Ergebnis der Breitensuche ausgeben
  fmt::print("Ergebnis von Breitensuche von {0}\n", 0);
  fmt::print("{}\n", fmt::join(breitensuche_resultat, " -> "));

  return 0;
}