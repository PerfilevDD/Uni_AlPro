#include <simpler_graph/simpler_graph.hpp>
<<<<<<< HEAD
#include <iostream>
#include <vector>

namespace SimplerGraph
{
  SimplerGraph::SimplerGraph(size_t knoten_anzahl) : knoten_anz(knoten_anzahl),
                                                     matrix(knoten_anzahl, std::vector<bool>(knoten_anzahl, false))
  {
    // Erstellen eine Klasse mit gegebener Zahl der Anzahl der Knoten
  }

  void SimplerGraph::new_knoten(const size_t &num1, const size_t &num2)
  {
    // Erstellen neue Knoten
    if (num1 >= 0 && num1 < knoten_anz && num2 >= 0 && num2 < knoten_anz)
    {
      matrix[num1][num2] = true;
    }
  }
  void SimplerGraph::enf_knoten(const size_t &num1, const size_t &num2)
  {
    // Entwernen die Knote
    if (num1 >= 0 && num1 < knoten_anz && num2 >= 0 && num2 < knoten_anz)
    {
      matrix[num1][num2] = false;
    }
  }

  void SimplerGraph::drucken()
  {
    // Drucken alle exestierende Knoten mit ensprechender Verbindung

    // Gehen Array durch
    for (int i = 0; i < knoten_anz; i++) {
      for (int j = 0; j < knoten_anz; j++) {
        if (matrix[i][j]==true) {
          // Falls eine Verbindung zwischen den Knoten exestiert, druecken sie aus
          std::cout << "(" << i << " -> " << j << ")" << std::endl;
        }
      }
    }
=======
#include <vector>
#include <iostream>

namespace SimplerGraph {
  // Konstruktor
  SimplerGraph::SimplerGraph(size_t knoten_anzahl) : 
  // zunächst gibt es keine Kanten zwischen den Knoten, deswegen false
    knoten_anz(knoten_anzahl), matrix(knoten_anzahl, std::vector<bool>(knoten_anzahl, false)) {
>>>>>>> sgitlab/AlPro_06_Kohn
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

