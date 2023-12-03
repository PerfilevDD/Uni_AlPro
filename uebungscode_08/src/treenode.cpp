#include <datenstrukturen/binarytree.hpp>
#include <datenstrukturen/treenode.hpp>
#include <iostream>
#include <memory>

namespace Datenstrukturen {
    TreeNode::TreeNode(int data) : data_(data), left_child(nullptr), right_child(nullptr) {
        // Init. data und children von Tree
    }
    BinaryTree::BinaryTree(int root_data) : root(nullptr) {
        // Init. root von Tree
        std::cout << root_data << std::endl;
        root = std::make_shared<TreeNode>(root_data);
    }

    int TreeNode::get_data() const {
        return data_;
    }

    void TreeNode::set_data(int data) {
        TreeNodeptr n = std::make_shared<TreeNode>(data);
    }

    void TreeNode::set_left_child(int data) {
    }

    void BinaryTree::print() const {
        std::cout << root->get_data() << std::endl;
    }

}  // namespace Datenstrukturen