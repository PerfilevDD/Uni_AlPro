#include <simpler_graph/simpler_graph.hpp>
#include <vector>
#include <iostream>

namespace SimplerGraph {
  // Konstruktor
  SimplerGraph::SimplerGraph(size_t knoten_anzahl) : 
  // zunächst gibt es keine Kanten zwischen den Knoten, deswegen false
    knoten_anz(knoten_anzahl), matrix(knoten_anzahl, std::vector<bool>(knoten_anzahl, false)) {
  }

   // Knoten werden erstellt
  void SimplerGraph::erstelleKnoten(const size_t &num1, const size_t &num2) {
    matrix[num1][num2] = true;
  }
   // Knoten werden gelöscht
   void SimplerGraph::loescheKnoten(const size_t &num1, const size_t &num2) {
    matrix[num1][num2] = false;
  }

  void SimplerGraph::drucke() {
     // Schleife über alle Zeilen 
    for (size_t i = 0; i < knoten_anz; i++) {
      // Schleife über alle Spalten
      for (size_t j = 0; j < knoten_anz; j++) {
        // Überprüfen, ob es eine Kante von Knoten i nach Knoten j gibt
        if (matrix[i][j]) {
          std::cout << i << " -> " << j << std::endl;
          // Wenn true, wird gedruckt 
        }
      }
    }
  }

}

