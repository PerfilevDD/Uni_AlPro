#include <simpler_graph/simpler_graph.hpp>

#define FMT_HEADER_ONLY  // Dieses Makro ist nötig, um die Bibliothek simpel einzubinden
#include <fmt/core.h>    // Muss eingebunden werden um {fmt} zu verwenden
#include <fmt/ranges.h>  // Muss zur Ausgabe von Arrays eingebunden werden
#include <vector>        // Stellt dynamische Arrays zur Verfügung

int main() {
  // ...
  
  // Nutzen Sie die {fmt}-Library um das Array auszugeben
  fmt::print("HIER DAS ARRAY WIE AUSGEBEN\n");
}
