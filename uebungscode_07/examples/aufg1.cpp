#include <simpler_graph/simpler_graph.hpp>

#define FMT_HEADER_ONLY  // Dieses Makro ist nötig, um die Bibliothek simpel einzubinden
#include <fmt/core.h>    // Muss eingebunden werden um {fmt} zu verwenden
#include <fmt/ranges.h>  // Muss zur Ausgabe von Arrays eingebunden werden

#include <vector>  // Stellt dynamische Arrays zur Verfügung

int main() {
    SimplerGraph::SimplerGraph sg(6);  // Inizialisieren Graphen und geben die Anzahl der Knoten

    bool is_gerichtet = true;

    // Initialisieren Kanten
    sg.neue_kante(0, 1, is_gerichtet);
    sg.neue_kante(0, 4, is_gerichtet);
    sg.neue_kante(1, 2, is_gerichtet);
    sg.neue_kante(1, 3, is_gerichtet);
    sg.neue_kante(4, 5, is_gerichtet);

    // Rufen BreitenScuhe-Funktin aus
    sg.BreitenSuche(0);

    fmt::print("Alle Kanten, die exestieren\n");
    sg.drucken();  // Drucken die Knoten mit der Verbindung

    // Nutzen Sie die {fmt}-Library um das Array auszugeben
    fmt::print("Resultät von Breitensuche von {0}\n", 0);
    fmt::print("{}\n", fmt::join(sg.folge, " -> "));
}
