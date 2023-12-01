#include <datenstrukturen/list.hpp>
#include <datenstrukturen/listnode.hpp>
#include <iostream>
#include <memory>

namespace Datenstrukturen {
    ListNode::ListNode(int data) : data_(data), next(nullptr) {
        // Erstellt ein Node mit eingegebener Zahl
    }
    List::List() : head(nullptr) {
        // Initializieren Nullpointer
    }
    ListNodeptr List::insert_front(const int x) {
        ListNodeptr n = std::make_shared<ListNode>(x);
        n->next = head;
        head = n;
        return head;
    }

    void List::print() const {
        ListNodeptr aktuell = head;
        while (aktuell) {
            std::cout << "ss" << std::endl;
            std::cout << aktuell->data_ << "->";
            aktuell = aktuell->next;
        }
        std::cout << "null" << std::endl;
        std::cout << head << std::endl;
        // std::cout << "ss" << std::endl;
    }
}  // namespace Datenstrukturen