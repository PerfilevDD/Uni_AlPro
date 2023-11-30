#include <simpler_graph/simpler_graph.hpp>
#include <vector>
#include <iostream>
#include <queue>
#include <stack>

// Code von letzer Woche
namespace SimplerGraph {
  // Konstruktor
  SimplerGraph::SimplerGraph(size_t knoten_anzahl) : 
  // zunächst gibt es keine Kanten zwischen den Knoten, deswegen false
    knoten_anz(knoten_anzahl), matrix(knoten_anzahl, std::vector<bool>(knoten_anzahl, false)) {
  }

   // Kanten werden erstellt
  void SimplerGraph::erstelleKanten(const size_t &num1, const size_t &num2) {
    matrix[num1][num2] = true;
  }
   // Kanten werden gelöscht
   void SimplerGraph::loescheKanten(const size_t &num1, const size_t &num2) {
    matrix[num1][num2] = false;
  }

  void SimplerGraph::drucke() {
     // Schleife über alle Zeilen 
    for (size_t i = 0; i < knoten_anz; i++) {
      // Schleife über alle Spalten
      for (size_t j = 0; j < knoten_anz; j++) {
        // Überprüfen, ob es eine Kante von Knoten i nach Knoten j gibt
        if (matrix[i][j]) {
          std::cout << i << " -> " << j << std::endl;
          // Wenn true, wird gedruckt 
        }
      }
    }
  }

  // Breitensuche
    std::vector<size_t> SimplerGraph::breitensuche(size_t s) {
    std::vector<size_t> folge; // Rückgabearray
    std::queue<size_t> q; // Warteschlange, die die zu erkundenden Knoten enthält

    // Markiere den Startknoten als erkundet und füge ihn in die Warteschlange und Rückgabearray ein
    std::vector<bool> erkundet(knoten_anz, false); // Vektor, der markiert, welche Knoten bereits erkundet wurden
    erkundet[s] = true;
    q.push(s);
    folge.push_back(s);

    while (!q.empty()) { // Schleife geht solange die Warteschlange q nicht leer ist
      size_t aktueller_knoten = q.front(); // der Wert des vordersten Elements in der Warteschlange q ist aktueller knoten 
      q.pop(); // das vorderste Element aus der Warteschlange wird entfernt, da es erkundet wurde

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

    return folge;
  }

// Tiefensuche
std::vector<size_t> SimplerGraph::tiefensuche(size_t s) {
       std::cout << "S ist gleich" << s << std::endl;
    std::vector<size_t> folge; // Rückgabearray
    std::stack<size_t> stack; // Stapel für die Tiefensuche
    std::vector<bool> erkundet(knoten_anz, false); // Vektor, der markiert, welche Knoten bereits erkundet wurden

    // Schiebe den Startknoten auf den Stapel und markiere ihn als erkundet
    stack.push(s);
    erkundet[s] = true;
    folge.push_back(s);

    while (!stack.empty()) {
      size_t aktueller_knoten = stack.top(); // der Wert des obersten Elements im Stapel ist der aktuelle Knoten

      // Finde einen unerkundeten Nachbarn des aktuellen Knotens
      size_t nachbar = 0;
      while ((matrix[aktueller_knoten][nachbar] || erkundet[nachbar])) {
        ++nachbar;
      }

      if (nachbar < knoten_anz) 
      {
        // Wenn ein unerkundeter Nachbar gefunden wurde
        erkundet[nachbar] = true;
        stack.push(nachbar);
        folge.push_back(nachbar);
      } else {
        // Wenn es keine unerkundeten Nachbarn gibt, entferne den aktuellen Knoten vom Stapel
        stack.pop();
      }
    }

    return folge;
  }
  
}