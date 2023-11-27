#include <iostream>
#include <queue>
#include <simpler_graph/simpler_graph.hpp>
#include <vector>

namespace SimplerGraph {
    SimplerGraph::SimplerGraph(size_t knoten_anzahl) : knoten_anz(knoten_anzahl),
                                                       matrix(knoten_anzahl, std::vector<bool>(knoten_anzahl, false)) {
        // Erstellen eine Klasse mit gegebener Zahl der Anzahl der Knoten
    }

    void SimplerGraph::neue_kante(const size_t &num1, const size_t &num2) {
        // Erstellen neue Knoten
        if (num1 >= 0 && num1 < knoten_anz && num2 >= 0 && num2 < knoten_anz)

        {
            matrix[num1][num2] = true;
        }
    }
    void SimplerGraph::enf_kante(const size_t &num1, const size_t &num2) {
        // Entwernen die Knote
        if (num1 >= 0 && num1 < knoten_anz && num2 >= 0 && num2 < knoten_anz) {
            matrix[num1][num2] = false;
        }
    }

    bool SimplerGraph::check_knoten(std::vector<size_t> &arr, const size_t &j) {
        // Funktion prueft ob ein Knoten im Array schon ist
        for (const auto &unerk_knoten : arr) {
            if (unerk_knoten == j) {
                return true;
            }
        }
        return false;
    }

    void SimplerGraph::BreitenSuche(const size_t &s) {
        std::queue<size_t> queue;

        // Pruefen falls der Startknoten exestiert im Array aller Knoten
        if (s < knoten_anz) {
            queue.push(s);
            // Gehen Queue durch
            while (!queue.empty()) {
                int v = queue.front();
                queue.pop();
                for (size_t j = 0; j < knoten_anz; j++) {
                    // Pruefen falls eine Kante exestiert
                    if (matrix[v][j]) {
                        // Prufen, damit nur unterer Teil der Graph ausgedruckt wuerde
                        if (j > s) {
                            // Pruefen falls der Knoten schon besucht war
                            if (!check_knoten(folge, j)) {
                                folge.push_back(j);
                                queue.push(j);
                            }
                        }
                    }
                }
            }
        }
        // DEL
        for (const auto &knoten : folge) {
            std::cout << knoten << " ";
        }
        std::cout << std::endl;
    }

    void SimplerGraph::TiefenSuche(const size_t &s) {
        folge.push_back(s);
        for (int i = 0; i < knoten_anz; i++) {
            if (matrix[s][i]) {
                if (!check_knoten(folge, i)) {
                    TiefenSuche(i);
                }
            }
        }
    }

    void SimplerGraph::drucken() {
        // Drucken alle exestierende Knoten mit ensprechender Verbindung

        // Gehen Array durch
        for (int i = 0; i < knoten_anz; i++) {
            for (int j = 0; j < knoten_anz; j++) {
                if (matrix[i][j] == true) {
                    // Falls eine Verbindung zwischen den Knoten exestiert, druecken sie aus
                    std::cout << "(" << i << " -> " << j << ")" << std::endl;
                }
            }
        }
    }
}  // namespace SimplerGraph
