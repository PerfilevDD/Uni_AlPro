#include <simpler_graph/simpler_graph.hpp>

#define FMT_HEADER_ONLY  // Dieses Makro ist nötig, um die Bibliothek simpel einzubinden
#include <fmt/core.h>    // Muss eingebunden werden um {fmt} zu verwenden
#include <fmt/ranges.h>  // Muss zur Ausgabe von Arrays eingebunden werden

#include <vector>  // Stellt dynamische Arrays zur Verfügung

int main() {
    // ...

    SimplerGraph::SimplerGraph sg(4);  // Inizialisieren Graphen und geben die Anzahl der Knoten

    bool is_gerichtet = true;

    sg.neue_kante(0, 1, is_gerichtet);  // Erstellen eine Verbindung zwischen den Knoten
    sg.neue_kante(1, 2, is_gerichtet);  // Erstellen eine Verbindung zwischen den Knoten
    sg.neue_kante(1, 3, is_gerichtet);                // Erstellen eine Verbindung zwischen den Knoten

    /*sg.new_knoten(1, 0); // Erstellen eine Verbindung zwischen den Knoten
    sg.new_knoten(2, 1); // Erstellen eine Verbindung zwischen den Knoten
    sg.new_knoten(3, 1); // Erstellen eine Verbindung zwischen den Knoten*/

    sg.BreitenSuche(0);

    sg.drucken();  // Drucken die Knoten mit der Verbindung

    // Nutzen Sie die {fmt}-Library um das Array auszugeben
    fmt::print("HIER DAS ARRAY WIE AUSGEBEN\n");
}
