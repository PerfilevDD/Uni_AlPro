#pragma once

#include <vector>
#include <cstddef>
#include <queue>
#include <stack>

namespace SimplerGraph
{

    class SimplerGraph
    {
    public:
        // Erstellt einen Graph mit einer festen Knotenanzahl
        SimplerGraph(size_t knoten_anzahl);
        void erstelleKanten(const size_t &num1, const size_t &num2);
        void loescheKanten(const size_t &num1, const size_t &num2);


        void drucke();
        std::vector<size_t> breitensuche(size_t s);
        std::vector<size_t> tiefensuche(size_t s);

    private:
      size_t knoten_anz;
      std::vector<std::vector<bool>> matrix;
    };
  } // namespace SimplerGraph

