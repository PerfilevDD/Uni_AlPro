#include <hanoi/hanoi.hpp>

#include <iostream>

namespace hanoi
{
    Hanoi::Hanoi(size_t anz)
    {
        // Die Variable stapel ist ein Array von drei Stapeln (welche wiederum Zahlenarrays sind)
        stapel = std::vector<std::vector<size_t>>(3);
        // Der erste Stapel soll den vollen Turm enthalten
        stapel[0] = std::vector<size_t>(anz);
        size_t i = anz;
        for (auto &x : stapel[0])
        {
            x = i;
            i--;
        }
    }
}