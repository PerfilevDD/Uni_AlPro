#pragma once

#include <memory>

#include <datenstrukturen/listnode.hpp>

namespace Datenstrukturen {

class List{
public:
  List();

  // Insert and delete Nodes
  ListNodeptr insert_front(const int x);
  ListNodeptr insert_after(const ListNodeptr& pred, const int x);
  ListNodeptr remove_front();
  ListNodeptr remove_after(const ListNodeptr& pred);

  // Get the next Node of the current List
  ListNodeptr next(const ListNodeptr& n) const;

  // Print the current List
  void print() const;

private:
  ListNodeptr head;
};

}
