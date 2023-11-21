#include <simpler_graph/simpler_graph.hpp>

#include <iostream>

int main()
{
  SimplerGraph::SimplerGraph sg(3); // Inizialisieren Graphen und geben die Anzahl der Knoten

  sg.new_knoten(0,1); // Erstellen eine Verbindung zwischen den Knoten
  sg.drucken(); // Drucken die Knoten mit der Verbindung

  sg.enf_knoten(0,1); // Entfernen die Verbindung zwischen den Knoten

  // Illegal
  sg.new_knoten(2,3); // Erstellen eine Verbindung zwischen den Knoten

  sg.new_knoten(1,1); // Erstellen eine Verbindung zwischen den Knoten
  sg.new_knoten(2,1); // Erstellen eine Verbindung zwischen den Knoten
  sg.new_knoten(1,0); // Erstellen eine Verbindung zwischen den Knoten

  sg.drucken(); // Drucken die Knoten mit der Verbindung

}
