#include <datenstrukturen/list.hpp>
#include <iostream>

int main() {
  Datenstrukturen::List list;
  list.insert_front(2);
  list.insert_front(3);
  list.print();
  std::cout << "=========" <<std::endl;
  list.remove_front();
  list.print();
}
