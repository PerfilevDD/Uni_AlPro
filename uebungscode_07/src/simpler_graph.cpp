#include <simpler_graph/simpler_graph.hpp>
#include <iostream>
#include <vector>
#include <queue>

namespace SimplerGraph
{
    SimplerGraph::SimplerGraph(size_t knoten_anzahl) : knoten_anz(knoten_anzahl),
                                                       matrix(knoten_anzahl, std::vector<bool>(knoten_anzahl, false))
    {
        // Erstellen eine Klasse mit gegebener Zahl der Anzahl der Knoten
    }

    void SimplerGraph::new_knoten(const size_t &num1, const size_t &num2)
    {
        // Erstellen neue Knoten
        if (num1 >= 0 && num1 < knoten_anz && num2 >= 0 && num2 < knoten_anz)
        {
            matrix[num1][num2] = true;
        }
    }
    void SimplerGraph::enf_knoten(const size_t &num1, const size_t &num2)
    {
        // Entwernen die Knote
        if (num1 >= 0 && num1 < knoten_anz && num2 >= 0 && num2 < knoten_anz)
        {
            matrix[num1][num2] = false;
        }
    }

    bool check_knoten(std::vector<size_t> &arr, const size_t &j)
    {
        for (const auto &unerk_knoten : arr)
        {
            if (unerk_knoten == j)
            {
                return true;
            }
        }
        return false;
    }

    void SimplerGraph::BreitenSuche(const size_t &s)
    {
        std::queue<size_t> queue;
        std::vector<size_t> folge;
        queue.push(s);
        while (!queue.empty())
        {
            int v = queue.front();
            queue.pop();
            for (size_t j = 0; j < knoten_anz; j++)
            {
                if (matrix[v][j])
                {
                    if (!check_knoten(folge, j))
                    {
                        std::cout << j << std::endl;
                        folge.push_back(j);
                        queue.push(j);
                    }
                }
            }
        }
        for (const auto &knoten : folge)
        {
            std::cout << knoten << " ";
        }
        std::cout << std::endl;
    }

    /*void SimplerGraph::BreitenSuche(const size_t &s)
        {
            std::queue<size_t> queue;
            std::vector<size_t> folge;
            queue.push(s);
            folge.push_back(s);
            while (!queue.empty())
            {
                int v = queue.front();
                queue.pop();
                for (size_t i = v; i < knoten_anz; i++)
                {
                    for (size_t j = 0; j < knoten_anz; j++)
                    {
                        if (matrix[i][j])
                        {
                            if (!check_knoten(folge, j))
                            {
                                std::cout << j << std::endl;
                                folge.push_back(j);
                                queue.push(j);
                            }
                        }
                    }
                }
            }
            for (const auto &knoten : folge){
                std::cout << knoten << " ";
            }
            std::cout << std::endl;
        }*/

    void SimplerGraph::drucken()
    {
        // Drucken alle exestierende Knoten mit ensprechender Verbindung

        // Gehen Array durch
        for (int i = 0; i < knoten_anz; i++)
        {
            for (int j = 0; j < knoten_anz; j++)
            {
                if (matrix[i][j] == true)
                {
                    // Falls eine Verbindung zwischen den Knoten exestiert, druecken sie aus
                    std::cout << "(" << i << " -> " << j << ")" << std::endl;
                }
            }
        }
    }
}
