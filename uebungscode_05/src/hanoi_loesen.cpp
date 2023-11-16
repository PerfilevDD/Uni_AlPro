#include <hanoi/hanoi.hpp>
#include <hanoi/hanoi_loesen.hpp>

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

  bool Hanoi_loesen::bewege_rekursiv(size_t anz, size_t von, size_t nach, size_t buf){
    if (anz == 0){
      return true;
    }
    bewege_rekursiv(anz - 1, von, buf, nach);
    bewege_rekursiv(anz - 1, buf, nach, von);
  }

}
