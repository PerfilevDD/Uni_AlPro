#include <hanoi/hanoi.hpp>

#include <iostream>
#include <vector>
#include <string>

#include <algorithm>

namespace hanoi
{
    Hanoi::Hanoi(size_t anz)
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

    bool Hanoi::bewege(size_t von, size_t nach)
    {
        if (von >= 0 && von <= 2 && nach >= 0 && nach <= 2)
        {
            if (!stapel[von].empty())
            {
                if (stapel[nach].empty() || stapel[von].back() < stapel[nach].back())
                {
                    stapel[nach].push_back(stapel[von].back());
                    stapel[von].pop_back();
                    return true;
                }
            }
        }
        return false;
    }

    void Hanoi::drucke() const
    {
        // std::cout << anz_scheiben << std::endl;
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