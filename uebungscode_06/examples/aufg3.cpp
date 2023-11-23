#include <simpler_graph/simpler_graph.hpp>

#include <iostream>


int main() {

 SimplerGraph::SimplerGraph sg(3); // Anzahl der Knoten
 sg.erstelleKnoten(0,1); // Erstellen einer Verbindung zwischen den Knoten
 sg.erstelleKnoten(1,2); 
 sg.loescheKnoten(0,1); // Die Verbindung wird gelöscht
 sg.drucke();  // Die verbindenden Knoten werden gedruckt

}
