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
    anz_scheiben = anz;
    size_t i = anz;
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
    bewege_rekursiv(anz - 1, buf, nach, von);
    return true;
  }
  void Hanoi_loesen::drucke() const
  {
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
  }
}
