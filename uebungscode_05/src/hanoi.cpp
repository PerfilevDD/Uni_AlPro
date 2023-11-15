#include <hanoi/hanoi.hpp>

#include <iostream>
#include <vector>

#include <algorithm>

namespace hanoi
{
    Hanoi::Hanoi(size_t anz)
    {
        // Die Variable stapel ist ein Array von drei Stapeln (welche wiederum Zahlenarrays sind)
        stapel = std::vector<std::vector<size_t>>(3);
        // Der erste Stapel soll den vollen Turm enthalten
        stapel[0] = std::vector<size_t>(anz);
        stapel[2] = std::vector<size_t>(anz);
        anz_scheiben = anz;
        size_t i = anz;
        for (auto &x : stapel[0])
        {
            x = i;
            i--;
        }

        // DELETE
        stapel[1] = std::vector<size_t>(anz);
        i = 3;
        for (auto &x : stapel[1])
        {
            x = i;
            i--;
        }

        // Reverse an Array
        std::reverse(stapel[0].begin(), stapel[0].end());
        std::reverse(stapel[1].begin(), stapel[1].end());
    }

    void Hanoi::drucke() const
    {
        for (int i = 0; i < anz_scheiben; i++)
        {
            //std::cout << stapel[0][i] << stapel[1][i] << stapel[2][i] << std::endl;
            for (int pr0 = 0; pr0 < stapel[0][i]; pr0++){
                std::cout << "s";
            }
            for (int pr1 = 0; pr1 < stapel[1][i]; pr1++){
                std::cout << "h";
            }
            for (int pr2 = 0; pr2 < stapel[2][i]; pr2++){
                std::cout << "f";
            }
            std::cout << std::endl;
        }
        /* for (auto &ein_stapel : Hanoi::stapel)
         {
             for (auto &element : ein_stapel)
             {
                 std::cout << element;
             }
         }
         std::cout << std::endl;*/
    }
}