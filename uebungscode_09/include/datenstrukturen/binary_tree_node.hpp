#pragma once

#include <memory>

namespace Datenstrukturen {

// A BinaryTreeNode stores its parent and its two children
// Diese Verwendung von std::enable_shared_from_this ist nötig, siehe Vorlesungsfolien.
class BinaryTreeNode : public std::enable_shared_from_this<BinaryTreeNode> {
public:
  using NodeSharedPtr = std::shared_ptr<BinaryTreeNode>;
  using NodeWeakPtr   = std::weak_ptr<BinaryTreeNode>;
  using data_t = int64_t;
  
  BinaryTreeNode(data_t data, NodeWeakPtr parent = NodeWeakPtr());
  const data_t get_data() const;
  const data_t get_left_child_data() const;
  const data_t get_right_child_data() const;
  NodeWeakPtr get_parent();
  NodeSharedPtr get_left_child();
  NodeSharedPtr get_right_child();
  void set_left_child(data_t data);
  void set_right_child(data_t data);
  void del_left_child();
  void del_right_child();
  
private:
  NodeWeakPtr _parent;
  NodeSharedPtr _left_child;
  NodeSharedPtr _right_child;
  const int _data;
};

using BinaryTreeNodeSharedPtr = std::shared_ptr<BinaryTreeNode>;

}
