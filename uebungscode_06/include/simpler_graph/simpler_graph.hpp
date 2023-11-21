#pragma once

#include <vector>
#include <cstddef>

namespace SimplerGraph
{

  class SimplerGraph
  {
  public:
    // Erstellt einen Graph mit einer festen Knotenanzahl
    SimplerGraph(size_t knoten_anzahl);

    void drucken(); // Druck funktion

    // Funktionen um die Knoten zu erstellen bzw. zu loeschen
    void new_knoten(const size_t &num1, const size_t &num2);
    void enf_knoten(const size_t &num1, const size_t &num2);

  private:
    std::vector<std::vector<bool>> matrix;
    const size_t knoten_anz;
  };
}
