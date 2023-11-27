#pragma once

#include <memory>

#include <datenstrukturen/treenode.hpp>

namespace Datenstrukturen {

class BinaryTree {
public:
  // Constructs a Binary Tree with a root that stores the given data
  BinaryTree(int root_data);
  
  // Returns a Shares Pointer to the current root
  TreeNodeptr get_root() const;
  
  // Print the current Binary Tree (somehow)
  // Eine Möglichkeit ist das Durchlaufen der Knoten mit Breitensuche
  // Dabei soll dann jeder Knoten und dessen Kinder gedruckt werden.
  void print() const;
  
private:
  TreeNodeptr root; // Wurzelknoten
};


}
