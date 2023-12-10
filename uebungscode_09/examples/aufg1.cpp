#include <datenstrukturen/doubly_linked_list.hpp>
#include <iostream>

int main() {
    Datenstrukturen::DoublyLinkedList list;

    // Erstellen eine Liste 5 4 3 2 1
    auto head = list.insert_front(5);
    auto insert_4 = list.insert_after(head, 4);
    auto insert_3 = list.insert_after(insert_4, 3);
    auto insert_2 = list.insert_after(insert_3, 2);
    auto insert_1 = list.insert_after(insert_2, 1);

    auto first = list.get_first();      // Erstes Element der Liste
    auto last = list.get_last();        // Letztes Element der Liste
    auto next_3 = list.next(insert_3);  // Naechstes nach 3
    auto prev_3 = list.prev(insert_3);  // Vor 3

    list.print();  // Print die Liste

    std::cout << "Erstes Element der Liste - " << first->data_ << std::endl;
    std::cout << "Letztes Element der Liste - " << last->data_ << std::endl;
    std::cout << "Naechstes nach 3 - " << next_3->data_ << std::endl;
    std::cout << "Vor 3 - " << prev_3->data_ << std::endl;

    // Etfernen
    std::cout << std::endl;
    std::cout << "Das Element " << list.remove(insert_4)->data_ << " wurde entfent." << std::endl;
    list.print();  // Print die Liste

    first = list.get_first();      // Erstes Element der Liste
    last = list.get_last();        // Letztes Element der Liste
    next_3 = list.next(insert_3);  // Naechstes nach 3
    prev_3 = list.prev(insert_3);  // Vor 3
    std::cout << "Erstes Element der Liste - " << first->data_ << std::endl;
    std::cout << "Letztes Element der Liste - " << last->data_ << std::endl;
    std::cout << "Naechstes nach 3 - " << next_3->data_ << std::endl;
    std::cout << "Vor 3 - " << prev_3->data_ << std::endl;
}
