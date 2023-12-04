#include <iostream>
#include <string>

#include <datenstrukturen/binary_tree.hpp>

int main() {
  Datenstrukturen::BinaryTree bt;
  bt.set_root(42);
  auto root = bt.get_root();
  root->set_left_child(6500);
  std::cout
    << " " << std::to_string(root->get_data())
    << " " << std::to_string(root->get_left_child_data()) << std::endl;
  
  // 
  //                       KEINE PANIK
  //
  //       NUR EIN BEISPIEL FÜR EINEN ZUGRIFFSFEHLER
  // 
  std::cout << std::to_string(root->get_right_child_data()) << std::endl;
}
