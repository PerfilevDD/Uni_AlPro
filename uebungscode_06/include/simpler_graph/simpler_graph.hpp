#pragma once

#include <vector>
#include <cstddef>

namespace SimplerGraph{

  class SimplerGraph{
  public:
    // Konstruktor, der einen Graphen mit einer festen Anzahl von Knoten erstellt
    SimplerGraph(size_t knoten_anzahl);
    std::vector<std::vector<bool>> matrix;
    // Methode zum Erstellen einer gerichteten Kante zwischen zwei Knoten
      void erstelleKnoten(const size_t &num1, const size_t &num2);
      // Methode zum Löschen einer gerichteten Kante zwischen zwei Knoten
       void loescheKnoten(const size_t &num1, const size_t &num2);
       // Drucken
      void drucke();



  private:
    const size_t knoten_anz;
  };
}
