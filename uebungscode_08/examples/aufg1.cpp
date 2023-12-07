#include <datenstrukturen/list.hpp>
#include <iostream>
#include <memory>

int main() {
    Datenstrukturen::List list;
    auto insert_1 = list.insert_front(1);  // Fuegt ein Element am Anfang der Liste hinzu
    auto insert_4 = list.insert_front(4);
    list.print();  // Druck die Liste

    std::cout << "=========" << std::endl;

    auto insert_2 = list.insert_after(insert_4, 2);  // Fuegt ein Element nach einem Element der Liste hinzu
    auto insert_3 = list.insert_after(insert_4, 3);
    auto insert_5 = list.insert_front(5);
    auto insert_6 = list.insert_after(insert_3, 6);
    list.remove_front();                            // Entfernt ein Element am Anfang der Liste
    auto insert_7 = list.insert_after(nullptr, 7);  // Fuegt ein Element am Anfang der Liste durch insert_after hinzu
    auto insert_0 = list.insert_after(insert_7, 0);
    list.print();  // Druck die Liste

    std::cout << "=========" << std::endl;

    auto remove_3 = list.remove_after(insert_3);  // Entfernt ein Element nach einem Element der Liste
    list.print();

    std::cout << "=========" << std::endl;

    std::cout << "Ein naechstes Element ist " << list.next(insert_4)->data_ << std::endl; // Druckt ein Element nach einem Element aus
}
