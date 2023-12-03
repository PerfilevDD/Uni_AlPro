#include <datenstrukturen/treenode.hpp>
#include <datenstrukturen/binarytree.hpp>
#include <memory>

namespace Datenstrukturen{
    TreeNode::TreeNode(int data) : data_(data), left_child(nullptr), right_child(nullptr){
        // Init. data und children von Tree
    }
    BinaryTree::BinaryTree(int root_data) : root(nullptr){
        // Init. root von Tree
    }

    void BinaryTree::print() const{
        
    }

}