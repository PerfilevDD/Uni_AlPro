#include <hanoi/hanoi.hpp>
#include <hanoi/hanoi_loesen.hpp>

#include <iostream>
#include <vector>
#include <string>

#include <algorithm>

namespace hanoi_loesen
{
  Hanoi_loesen::Hanoi_loesen(size_t anz)
  {
    // Die Variable stapel ist ein Array von drei Stapeln (welche wiederum Zahlenarrays sind)
    stapel = std::vector<std::vector<size_t>>(3);
    // Der erste Stapel soll den vollen Turm enthalten
    stapel[0] = std::vector<size_t>(anz);
    zaehler = 0;
    anz_scheiben = anz;
    size_t i = anz;
    // Addiert die Scheibe in Stapel 0
    for (auto &x : stapel[0])
    {
      x = i;
      i--;
    }
  }

  void Hanoi_loesen::scheibe_in_stapel(std::vector<size_t> &stapel_von, std::vector<size_t> &stapel_nach)
  {
    int scheibe = stapel_von.back();
    stapel_von.pop_back();
    stapel_nach.push_back(scheibe);
  }

  bool Hanoi_loesen::bewege_rekursiv(size_t anz, size_t von, size_t nach, size_t buf)
  {
    if (anz == 0)
    {
      drucke();
      return true;
    }
    bewege_rekursiv(anz - 1, von, buf, nach);
    scheibe_in_stapel(stapel[von], stapel[nach]);
    zaehler++;
    bewege_rekursiv(anz - 1, buf, nach, von);
    return true;
  }
  void Hanoi_loesen::drucke() const
  {
    std::cout << "Bewegung " << zaehler << std::endl; // Anzahl der Bewegungen
    std::cout << std::endl;
    // Print aktuelle Stapeln
    for (auto &ein_stapel : stapel)
    {
      std::cout << "Stapel ";
      for (auto &element : ein_stapel)
      {
        std::cout << element << " ";
      }
      std::cout << std::endl;
    }
    std::cout << std::endl;

    for (size_t ebene = anz_scheiben; ebene > 0; --ebene) // Von oben nach unten jede Ebene durchgehen
    {
      for (size_t stapel_index = 0; stapel_index < 3; ++stapel_index) // Jeden Stapel durchgehen
      {
        if (ebene <= stapel[stapel_index].size()) // Wenn der Stapel auf dieser Ebene ein Element hat
        {
          size_t scheibe = stapel[stapel_index][ebene - 1];
          std::cout << std::string(anz_scheiben - scheibe, ' '); // Leerzeichen vor der Scheibe
          std::cout << std::string(2 * scheibe, '-');            // Die Scheibe selbst
          std::cout << std::string(anz_scheiben - scheibe, ' '); // Leerzeichen nach der Scheibe
        }
        else
        {
          // Drucke Leerzeichen, wenn kein Element vorhanden ist
          std::cout << std::string(2 * anz_scheiben, ' ');
        }
        std::cout << "   "; // Abstand zwischen den Stapeln
      }
      std::cout << std::endl;
    }

    // Abschließende Zeile für Stapel-Basis
    std::cout << std::string(anz_scheiben * 6 + 10, '=') << std::endl;
  }
}