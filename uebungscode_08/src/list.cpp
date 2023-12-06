#include <datenstrukturen/list.hpp>
#include <datenstrukturen/listnode.hpp>
#include <iostream>
#include <memory>

namespace Datenstrukturen {
    // Konstruktor für die Klasse ListNode, der ein Node mit eingegebener Zahl erstellt
    ListNode::ListNode(int data) : data_(data), next(nullptr) { /* Zeiger auf das nächste Element next wird auf
                                                 nullptr gesetzt, da unserer neue Node noch keine Nachfolger hat */
    }
     // Konstruktor für die Klasse List
    List::List() : head(nullptr) {
        // Initializiert head
    }
    // ein neues Element wird am Anfang der Liste hinzugefügt
    ListNodeptr List::insert_front(const int x) {
        ListNodeptr n = std::make_shared<ListNode>(x);  // Erstellen neu Knoten; Shared Pointer verwaltet x
        n->next = head;                                 // Setzen pointer von n auf head;
        head = n;                                       // n ist jetzt head
        return head;
    }

    ListNodeptr List::insert_after(const ListNodeptr& pred, const int x) {
        // Funktion fuegt ein Element nach dem anderen Element hinzu
        if (pred != nullptr) { // um sicherzustellen, dass das Einfügen nach einem gültigen Element erfolgt
            ListNodeptr n = std::make_shared<ListNode>(x);  // Ein neuer Knoten n wird erstellt; Shared Pointer verwaltet x
            ListNodeptr alt_pointer = pred->next;           // temporärer Zeiger (alt_pointer) speichert nächste Element von pred
            pred->next = n;                                 // next Zeiger wird auf n gesetzt, also n folgt jetzt nach pred
            n->next = alt_pointer;                          // nächster Element von n ist jetzt der damals nächster Element von pred
            return n;
        } else {
            // Falls nullptr gegeben wuerden, rufen insert_front auf
            return insert_front(x);
        }
    }

    ListNodeptr List::remove_front() { // um sicherzustellen, dass die Liste nicht leer ist
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
            pred->next = pred->next->next; // next von pred wird auf das übernächste Element gesetzt
            return pred;
        } else if (pred->next == NULL) {
            // Falls letzter Element gegeben wurde, return 0
            return nullptr;
        } else {
            // Falls nullptr gegeben wurde, entfernen ersten Element der Liste
            return remove_front();
        }
    }

    ListNodeptr List::next(const ListNodeptr& n) const {
        // Get the next Node of the current List
        if (n != nullptr && n->next != NULL) {
            // Pruefen damit 'ausser' der Liste nicht zu gehen
            return n->next;
        } else if (n->next == NULL) {
            // Falls letzter Element gegeben wurde, return 0
            return nullptr;
        } else {
            return nullptr;
        }
    }

    void List::print() const {
        // Funktuion drueckt die Liste
        ListNodeptr aktuell = head; // Anfang der Liste
        // Gehen jeder Element der Liste durch, um alle auszudruecken
        while (aktuell) {
            std::cout << aktuell->data_ << "->";
            aktuell = aktuell->next; // aktuell wird auf das nächste Element in der Liste verschoben
        }
        std::cout << "null" << std::endl;
    }
}  // namespace Datenstrukturen
