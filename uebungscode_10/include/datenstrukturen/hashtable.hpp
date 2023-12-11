#pragma once

#include <functional>
#include <memory>
#include <cstddef>
#include <string>

// Fügen Sie ggf. die Includes zu Ihrer Listenimplementierung hinzu
// #include <datenstrukturen/list.hpp>

namespace Datenstrukturen {

// In dieser Woche beginnen Sie mit der Implementierung einer Hashtable.
// Diese Woche wird die Hashtable eine feste Anzahl von Buckets,
// eine feste Hashfunktion und noch keine Iteratoren enthalten.
class Hashtable{
public:
  // Konstruktor
  Hashtable();
  
  // Element einfügen
  void insert(const std::string x);
  
  // Gibt genau dann true zurück,
  // wenn das Element in der Hashtable enthalten ist
  bool find(const std::string& x) const;
  
  // Element entfernen
  void remove(const std::string& x);
  
  // Druckt alle Elemente der Hashtable
  void print() const;

  // Gibt Anzahl der Elemente zurück
  size_t size() const;
  
private:
  // Die verwendete Hashfunktion.
  // Um den Bucket eines Elements x zu finden,
  // kann die Hashfkt wie folgt verwendet werden
  //   hashfkt(x) % num_buckets;
  const std::function<size_t(const std::string&)> hashfkt;
  
  // Die aktuelle Anzahl der Buckets
  size_t num_buckets;
  
  // Verwenden Sie ihre Listenimplementierung oder
  // std::vector<List> buckets;
};

}
