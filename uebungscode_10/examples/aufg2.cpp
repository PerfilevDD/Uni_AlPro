
#include <random>
#include <vector>
#include <iostream>

// Dies ist ein naiver Test (der nicht vollständig prüft ob ihre Implementierung korrekt ist).
void naiver_test() {
  // Hier erstellen wir eine zufällige Folge von Zahlen
  std::random_device rand_device;
  std::mt19937 rand_engine(rand_device());
  std::uniform_int_distribution<int> dist(100, 999);
  std::vector<int> zahlenfolge(20);
  for (int& x : zahlenfolge) {
    x = dist(rand_engine);
  }
  
  // Nutzen Sie diese Folge um ihren binären Suchbaum aufzubauen
  // ...
  
  
  // Prüfen Sie, ob ihr binärer Suchbaum die Elemente im Inorderdurchlauf aufsteigend ausgeben.
  // ...
  
  
}


int main() {
  // ...
  
  naiver_test();
  
  // ...
}
