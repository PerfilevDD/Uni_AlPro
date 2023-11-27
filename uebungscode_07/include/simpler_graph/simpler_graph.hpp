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

        void BreitenSuche(const size_t &s); // Breitensuche
        void TiefenSuche(const size_t &s); // Tiefensuche

        // Funktionen um die Knoten zu erstellen bzw. zu loeschen
        void neue_kante(const size_t &num1, const size_t &num2, const bool &is_gerichtet);
        void enf_kante(const size_t &num1, const size_t &num2, const bool &is_gerichtet);
        std::vector<size_t> folge;

    private:
        bool check_knoten(std::vector<size_t> &arr, const size_t &j); // Funktion prueft falls der Knoten schon besucht war
        std::vector<std::vector<bool>> matrix;
        const size_t knoten_anz;
    };
}
