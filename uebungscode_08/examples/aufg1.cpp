#include <datenstrukturen/list.hpp>
#include <iostream>
#include <memory>

int main() {
  Datenstrukturen::List list;
  list.insert_front(2);
  //list.insert_front(3);
  list.print();
  std::cout << "=========" <<std::endl;


  
  list.insert_after(nullptr, 2);

  list.print();
}
