#include <datenstrukturen/list.hpp>
#include <iostream>
#include <memory>

int main() {
    Datenstrukturen::List list;
    auto insert_1 = list.insert_front(1);  // Fuegt ein Element am Anfang der Liste ninzu
    auto insert_4 = list.insert_front(4);
    list.print();  // Druck die Liste

    std::cout << "=========" << std::endl;

    auto insert_2 = list.insert_after(insert_4, 2);  // Fuegt ein Element nach einem Element der Liste ninzu
    auto insert_3 = list.insert_after(insert_4, 3);
    auto insert_5 = list.insert_front(5);
    auto insert_6 = list.insert_after(insert_3, 6);
    list.remove_front();  // Entfernt ein Element am Anfang der Liste
    list.print();
}
