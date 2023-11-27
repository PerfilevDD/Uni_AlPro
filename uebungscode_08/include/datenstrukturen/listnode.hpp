#pragma once

#include <memory>

namespace Datenstrukturen {

// A ListNode stores its left child and right child and some data
class ListNode{
public:
  ListNode(int data);

// Für ein nachvollziehbares Projekt sollte der folgende, schlechte Stil (!)
// nicht verwendet werden. Der schlechte Stil (Membervariablen sind public) wird
// hier nur deshalb verwendet, um die Datenstruktur schnell zu entwickeln.
public:
  std::shared_ptr<ListNode> next;
  
  int data_;
};

// In the end, the ListNodes are dynamically organized on the heap.
// Therefore, we use Shared Pointer for the organization of ListNodes.
// It will turn out, that shared_ptr is the best way because we want
// to iterate through the nodes (i.e., we want multiple references at once).

// The type "std::shared_ptr<ListNode>" is abbriviated with "ListNodeptr"
using ListNodeptr = std::shared_ptr<ListNode>;

}
