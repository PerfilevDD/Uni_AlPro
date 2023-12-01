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
        std::cout << "head  " << head << std::endl;
        std::cout << "n  " << n << std::endl;
        n->next = head;
        head = n;
        std::cout << "n->next  " << n->next << std::endl;
        std::cout << "head 2  " << head << std::endl;
        return head;
    }

    ListNodeptr List::remove_front(){
        head = head->next;
        return head;
    }

    void List::print() const {
        ListNodeptr aktuell = head;
        while (aktuell) {
            std::cout << aktuell->data_ << "->";
            aktuell = aktuell->next;
        }
        std::cout << "null" << std::endl;
        std::cout << head << std::endl;
        // std::cout << "ss" << std::endl;
    }
}  // namespace Datenstrukturen