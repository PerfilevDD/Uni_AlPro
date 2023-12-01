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
        ListNodeptr n = std::make_shared<ListNode>(x);  // Erstellen neu Knoten
        n->next = head; // Setzen pointer von n auf head
        head = n; // n ist jetzt head
        std::cout << std::endl;

        return head;
    }
    
    ListNodeptr List::insert_after(const ListNodeptr& pred, const int x){
        std::cout << "insert after  " << pred << std::endl;
        return head;
    }

    ListNodeptr List::remove_front() {
        // Entfernen den ersten Element der Liste
        if (head != 0) {
            // Setzen head auf dem zweiten Element der Liste
            head = head->next;
            return head;
        }
        return nullptr;
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