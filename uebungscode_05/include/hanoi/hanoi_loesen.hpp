#pragma once

#include <vector>
#include <cstddef>

namespace hanoi_loesen
{

  class Hanoi_loesen
  {
  public:
    // Erstellt eine Startkonfiguration mit anz vielen Scheiben
    Hanoi_loesen(size_t anz);

    // Verschiebt die oberste Scheibe (falls erlaubt) und gibt true zurück
    // genau dann wenn die Bewegung erlaubt war
    bool bewege(size_t von, size_t nach);
    void scheibe_in_stapel(std::vector<size_t>& stapel_von, std::vector<size_t>& stapel_nach);
    bool bewege_rekursiv(size_t anz, size_t von, size_t nach, size_t buf);

    // Druckt die aktuelle Konfiguration auf der Konsole aus
    void drucke() const;

  private:
    // Wir haben drei Stapel. Also bietet sich ein Array von Zahlenarrays an.
    std::vector<std::vector<size_t>> stapel;
    int anz_scheiben;
  };
}
