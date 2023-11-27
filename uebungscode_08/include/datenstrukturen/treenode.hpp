#pragma once

#include <memory>

namespace Datenstrukturen {

// A TreeNode stores its left child and right child and some data
class TreeNode {
public:
  // Constructs a Tree Node with the given data
  TreeNode(int data);
  
  // Returns the data
  int get_data() const;
  
  // Sets the data
  void set_data(int data);
  
  // Returns a Shared Pointer to the (current) left child
  std::shared_ptr<TreeNode> get_left_child() const;
  
  // Returns a Shared Pointer to the (current) right child
  std::shared_ptr<TreeNode> get_right_child() const;
  
  // Sets the value of the left child (and creates the child if necessary)
  void set_left_child(int data);
  
  // Sets the value of the right child (and creates the child if necessary)
  void set_right_child(int data);
  
  // Removes the left child (if it exists)
  void remove_left_child();
  
  // Removes the right child (if it exists)
  void remove_right_child();
  
private:
  std::shared_ptr<TreeNode> left_child;
  std::shared_ptr<TreeNode> right_child;
  
  int data_;
};

// In the end, the TreeNodes are dynamically organized on the heap.
// Therefore, we use Shared Pointer for the organization of TreeNodes.
// It will turn out, that shared_ptr is the best way because we want
// to iterate through the nodes (i.e., we want multiple references at once).

// The type "std::shared_ptr<TreeNode>" is abbriviated with "TreeNodeptr"
using TreeNodeptr = std::shared_ptr<TreeNode>;

}
