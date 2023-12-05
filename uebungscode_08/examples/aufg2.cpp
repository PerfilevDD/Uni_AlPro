#include <datenstrukturen/binarytree.hpp>
#include <iostream>

int main() {
    Datenstrukturen::BinaryTree binaryTree(42);
    auto root = binaryTree.get_root();  // Init root

    // Erstellen Knoten aus der Aufgabe

    // Links von root
    
        // 11
        root->set_left_child(11);
        auto left11 = root->get_left_child();

        // 9
        left11->set_left_child(9);
        auto left9 = left11->get_left_child();

        // 0
        left11->set_right_child(0);
        auto right0 = left11->get_right_child();

        // -6
        left9->set_left_child(-6);
        auto leftm6 = left9->get_left_child();

        // 22
        left9->set_right_child(22);
        auto right22 = left9->get_right_child();
    

    // Rechts von root
    
        // r22
        root->set_right_child(22);
        auto rightr22 = root->get_right_child();

        // 544
        rightr22->set_right_child(544);
        auto right544 = rightr22->get_right_child();

        // r11
        right544->set_left_child(11);
        auto leftr11 = right544->get_left_child();
    

    binaryTree.print();  // Print Tree

    std::cout << "===========" << std::endl;

    root->remove_right_child();  // Delete right child von root
    binaryTree.print();          // Print Tree

    std::cout << "===========" << std::endl;

    // Delete left child von 11(links oben)
    left11->remove_left_child();
    binaryTree.print();  // Print Tree
}
