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

        /*// DELETE
        stapel[1] = std::vector<size_t>(anz);
        i = anz;
        for (auto &x : stapel[1])
        {
            x = i;
            i--;
        }
        stapel[2] = std::vector<size_t>(anz);
        i = anz;
        for (auto &x : stapel[2])
        {
            x = i;
            i--;
        }*/

        // Reverse an Array
        std::reverse(stapel[0].begin(), stapel[0].end());
        std::reverse(stapel[1].begin(), stapel[1].end());
        std::reverse(stapel[2].begin(), stapel[2].end());
    }

    bool Hanoi::bewege(size_t von, size_t nach){
        //if(stapel[von].)
    }

    void Hanoi::drucke() const
    {
        int temp = 1;
        for (int i = 1; i <= anz_scheiben; i++)
        {
            // Stapel 1
            if (i != stapel[0].size())
            {
                std::cout << std::string(stapel[0][stapel[0].size() - 1 - i], ' ');
            }

            std::cout << std::string(stapel[0][i - 1], '-') << std::string(stapel[0][i - 1], '-');

            if (i != stapel[0].size())
            {
                std::cout << std::string(stapel[0][stapel[0].size() - 1 - i], ' ')
                          << std::string(1, ' ');
            } else {
                std::cout << std::string(1, ' ');
            }
            // Stapel 2
            if (i != stapel[1].size() & stapel[1].size() == *std::max_element(stapel[1].begin(), stapel[1].end()))
            {
                std::cout << std::string(stapel[1][stapel[1].size() - 1 - i], ' ');
            }
            else if (i != stapel[1].size() & stapel[1].size() != *std::max_element(stapel[1].begin(), stapel[1].end()))
            {
                std::cout << std::string(stapel[1][stapel[1].size() - 1 - i], ' ')
                          << std::string(1, ' ');
            }

            std::cout << std::string(stapel[1][i - 1], '-') << std::string(stapel[1][i - 1], '-');

            if (i != stapel[1].size())
            {
                std::cout << std::string(stapel[1][stapel[1].size() - 1 - i], ' ')
                          << std::string(1, ' ');
            } else {
                std::cout << std::string(1, ' ');
            }

            // Stael 3
            if (i != stapel[2].size() & stapel[2].size() == *std::max_element(stapel[2].begin(), stapel[2].end()))
            {
                std::cout << std::string(stapel[2][stapel[1].size() - 1 - i], ' ');
            }
            else if (i != stapel[2].size() & stapel[2].size() != *std::max_element(stapel[2].begin(), stapel[2].end()))
            {
                std::cout << std::string(stapel[2][stapel[2].size() - 1 - i], ' ')
                          << std::string(1, ' ');
            }

            std::cout << std::string(stapel[2][i - 1], '-') << std::string(stapel[2][i - 1], '-');

            if (i != stapel[2].size())
            {
                std::cout << std::string(stapel[2][stapel[1].size() - 1 - i], ' ')
                          << std::string(1, ' ');
            } else {
                std::cout << std::string(1, ' ');
            }
            std::cout << std::endl;
        }
    }
}