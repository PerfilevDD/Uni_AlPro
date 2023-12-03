#include <datenstrukturen/binarytree.hpp>
#include <iostream>

int main() {
    Datenstrukturen::BinaryTree binaryTree(2);
    auto root = binaryTree.get_root();

    std::cout << "main " << root << std::endl;
    root->set_left_child(3);
    auto left1 = root->get_left_child();
    left1->set_left_child(5);
    binaryTree.print();
}
