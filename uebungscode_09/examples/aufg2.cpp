#include <iostream>
#include <string>

#include <datenstrukturen/binary_tree.hpp>

int main() {
  Datenstrukturen::BinaryTree bt;
  bt.set_root(42);
  auto root = bt.get_root();
  root->set_left_child(6500);

  // Erstellen Knoten aus der Aufgabe 8

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

  std::cout << "PreOrder: ";
  bt.print_preorder();

  std::cout << std::endl;
  std::cout << "InOrder: ";
  bt.print_inorder();
  
  std::cout << std::endl;
  std::cout << "LevelOrder: ";
  bt.print_levelorder();

  /*std::cout
    << " " << std::to_string(root->get_data())
    << " " << std::to_string(root->get_left_child_data()) << std::endl;*/
  
  // 
  //                       KEINE PANIK
  //
  //       NUR EIN BEISPIEL FÜR EINEN ZUGRIFFSFEHLER
  // 
  //std::cout << std::to_string(root->get_right_child_data()) << std::endl;
}
