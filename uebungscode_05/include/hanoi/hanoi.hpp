#pragma once

#include <vector>
#include <cstddef>

namespace hanoi{
  
  class Hanoi{
  public:
    // Erstellt eine Startkonfiguration mit anz vielen Scheiben
    Hanoi(size_t anz);
    
    // Verschiebt die oberste Scheibe (falls erlaubt) und gibt true zurück
    // genau dann wenn die Bewegung erlaubt war
    bool bewege(size_t von, size_t nach);
    
    // Druckt die aktuelle Konfiguration auf der Konsole aus
    void drucke() const;

  private:
    // Wir haben drei Stapel. Also bietet sich ein Array von Zahlenarrays an.
    std::vector<std::vector<size_t>> stapel;
  };
}
