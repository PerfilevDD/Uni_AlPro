#include <iostream>
#include <queue>
#include <simpler_graph/simpler_graph.hpp>
#include <vector>

namespace SimplerGraph {
    SimplerGraph::SimplerGraph(size_t knoten_anzahl) : knoten_anz(knoten_anzahl),
                                                       matrix(knoten_anzahl, std::vector<bool>(knoten_anzahl, false)) {
        // Erstellen eine Klasse mit gegebener Zahl der Anzahl der Knoten
    }

    void SimplerGraph::neue_kante(const size_t &num1, const size_t &num2, const bool &is_gerichtet) {
        // Erstellen neue Knoten
        if (num1 < knoten_anz && num2 < knoten_anz) {
            matrix[num1][num2] = true;
            if (!is_gerichtet) {
                matrix[num2][num1] = true;
            }
        }
    }
    void SimplerGraph::enf_kante(const size_t &num1, const size_t &num2, const bool &is_gerichtet) {
        // Entwernen die Knote
        if (num1 < knoten_anz && num2 < knoten_anz) {
            matrix[num1][num2] = false;
            if (!is_gerichtet) {
                matrix[num2][num1] = false;
            }
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

    // Breitensuche
    void SimplerGraph::BreitenSuche(const size_t &s) {
        std::queue<size_t> q;  // Warteschlange, die die zu erkundenden Knoten enthält

        // Markiere den Startknoten als erkundet und füge ihn in die Warteschlange und Rückgabearray ein
        std::vector<bool> erkundet(knoten_anz, false);  // Vektor, der markiert, welche Knoten bereits erkundet wurden
        erkundet[s] = true;
        q.push(s);
        folge.push_back(s);

        while (!q.empty()) {                      // Schleife geht solange die Warteschlange q nicht leer ist
            size_t aktueller_knoten = q.front();  // der Wert des vordersten Elements in der Warteschlange q ist aktueller knoten
            q.pop();                              // das vorderste Element aus der Warteschlange wird entfernt, da es erkundet wurde

            // Durchlaufe alle Nachbarn des aktuellen Knotens
            for (size_t nachbar = 0; nachbar < knoten_anz; ++nachbar) {
                // für jeden unerkundeten Nachbarn des aktuellen Knotens wird überprüft, ob es eine Kante gibt
                if (matrix[aktueller_knoten][nachbar] && !erkundet[nachbar]) {
                    /* Wenn eine Kante vorhanden ist und der Nachbarknoten noch nicht erkundet wurde,
                     wird er als erkundet markiert, zur Warteschlange hinzugefügt und
                     in Rückgabearray hinzugefügt */
                    erkundet[nachbar] = true;
                    q.push(nachbar);
                    folge.push_back(nachbar);
                }
            }
        }
    }

    void SimplerGraph::TiefenSuche(const size_t &s) {
        // TiefenSuche-Funktion
        folge.push_back(s);  // Hier etwas mit Suchelement machen
        // Gehen die Knoten durch
        for (int i = 0; i < knoten_anz; i++) {
            // Pruefen, falls eine Kante exestiert
            if (matrix[s][i]) {
                // Pruefen falls der Knoten bereits besucht war
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
                if (matrix[i][j]) {
                    // Falls eine Verbindung zwischen den Knoten exestiert, druecken sie aus
                    std::cout << "(" << i << " -> " << j << ")" << std::endl;
                }
            }
        }
        std::cout << std::endl;
    }
}  // namespace SimplerGraph
