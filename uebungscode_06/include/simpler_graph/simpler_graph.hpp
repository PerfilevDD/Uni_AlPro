#pragma once

#include <vector>
#include <cstddef>

<<<<<<< HEAD
namespace SimplerGraph
{

  class SimplerGraph
  {
=======
namespace SimplerGraph{

  class SimplerGraph{
>>>>>>> sgitlab/AlPro_06_Kohn
  public:
    // Konstruktor, der einen Graphen mit einer festen Anzahl von Knoten erstellt
    SimplerGraph(size_t knoten_anzahl);
<<<<<<< HEAD

    void drucken(); // Druck funktion

    // Funktionen um die Knoten zu erstellen bzw. zu loeschen
    void new_knoten(const size_t &num1, const size_t &num2);
    void enf_knoten(const size_t &num1, const size_t &num2);
=======
    std::vector<std::vector<bool>> matrix;
    // Methode zum Erstellen einer gerichteten Kante zwischen zwei Knoten
      void erstelleKnoten(const size_t &num1, const size_t &num2);
      // Methode zum Löschen einer gerichteten Kante zwischen zwei Knoten
       void loescheKnoten(const size_t &num1, const size_t &num2);
       // Drucken
      void drucke();


>>>>>>> sgitlab/AlPro_06_Kohn

  private:
    std::vector<std::vector<bool>> matrix;
    const size_t knoten_anz;
  };
}
