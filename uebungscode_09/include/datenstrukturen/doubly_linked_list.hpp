#pragma once

#include <memory>

#include <datenstrukturen/doubly_linked_listnode.hpp>

namespace Datenstrukturen {

class DoublyLinkedList{
public:
  DoublyLinkedList();
  
  // Get the first Node of the current List
  DListNodeptr get_first() const;
  
  // Get the last Node of the current List
  DListNodeptr get_last() const;
  
  // Insert and delete Nodes
  DListNodeptr insert_front(int x);
  DListNodeptr insert_after(const DListNodeptr& pred, int x);
  DListNodeptr remove(const DListNodeptr& n);

  // Get the next Node of the current List
  DListNodeptr next(const DListNodeptr& n) const;
  
  // Get the previous Node of the current List
  DListNodeptr prev(const DListNodeptr& n) const;

  // Print the current List
  void print() const;

private:
  DListNodeptr head;
  DListNodeptr tail;
};

}
