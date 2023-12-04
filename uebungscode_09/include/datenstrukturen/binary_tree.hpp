#pragma once

#include <memory>

#include <datenstrukturen/binary_tree_node.hpp>

namespace Datenstrukturen {

class BinaryTree{
public:
  BinaryTree();
  
  // Get the root
  const BinaryTreeNodeSharedPtr get_root() const;
  void set_root(BinaryTreeNode::data_t data);

  // Print the binary tree
  void print_preorder() const;
  void print_inorder() const;
  void print_postorder() const;
  void print_levelorder() const;

private:
  BinaryTreeNodeSharedPtr _root;
};

}
