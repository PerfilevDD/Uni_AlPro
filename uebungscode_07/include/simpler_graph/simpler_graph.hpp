#pragma once

#include <vector>
#include <cstddef>

namespace SimplerGraph
{

    class SimplerGraph
    {
    public:
        // Erstellt einen Graph mit einer festen Knotenanzahl
        SimplerGraph(size_t knoten_anzahl);

        void drucken(); // Druck funktion

        void BreitenSuche(const size_t &s);

        // Funktionen um die Knoten zu erstellen bzw. zu loeschen
        void new_knoten(const size_t &num1, const size_t &num2);
        void enf_knoten(const size_t &num1, const size_t &num2);
        std::vector<size_t> folge;

    private:
        bool check_knoten(std::vector<size_t> &arr, const size_t &j);
        std::vector<std::vector<bool>> matrix;
        const size_t knoten_anz;
    };
}
