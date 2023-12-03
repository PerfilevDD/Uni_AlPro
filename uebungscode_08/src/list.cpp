#include <datenstrukturen/list.hpp>
#include <datenstrukturen/listnode.hpp>
#include <iostream>
#include <memory>

namespace Datenstrukturen {
    ListNode::ListNode(int data) : data_(data), next(nullptr) {
        // Erstellt ein Node mit eingegebener Zahl
    }
    List::List() : head(nullptr) {
        // Initializiert head
    }
    ListNodeptr List::insert_front(const int x) {
        ListNodeptr n = std::make_shared<ListNode>(x);  // Erstellen neu Knoten
        n->next = head;                                 // Setzen pointer von n auf head
        head = n;                                       // n ist jetzt head
        return head;
    }

    ListNodeptr List::insert_after(const ListNodeptr& pred, const int x) {
        // Funktion fuegt ein Element nach dem anderen Element hinzu
        if (pred != nullptr) {
            ListNodeptr n = std::make_shared<ListNode>(x);  // Erstellen neu Knoten
            ListNodeptr alt_pointer = pred->next;           // Alter Pointer, der auf den naechsten Element nach pred zeigte
            pred->next = n;                                 // Setzen Pointer von altem Element auf neuem Pointer
            n->next = alt_pointer;                          // Setzen naechster Pointer nach n auf vorherigen naechsten Poninter
            return n;
        } else {
            // Falls nullptr gegeben wuerden, rufen insert_front auf
            return insert_front(x);
        }
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

    ListNodeptr List::remove_after(const ListNodeptr& pred) {
        // Funktion entfenrnt ein Element nach dem anderen Element
        if (pred != nullptr && pred->next != NULL) {
            // Pruefen damit nicht Element 'ausser oder vor' der Liste zu entfernen
            pred->next = pred->next->next;
            return pred;
        } else if (pred->next == NULL) {
            // Falls letzter Element gegeben wurde, return 0
            return 0;
        } else {
            // Falls nullptr gegeben wurde, entfernen ersten Element der Liste
            return remove_front();
        }
    }

    void List::print() const {
        // Funktuion drueckt die Liste
        ListNodeptr aktuell = head;
        // Gehen jeder Element der Liste durch, um alle auszudruecken
        while (aktuell) {
            std::cout << aktuell->data_ << "->";
            aktuell = aktuell->next;
        }
        std::cout << "null" << std::endl;
    }
}  // namespace Datenstrukturen