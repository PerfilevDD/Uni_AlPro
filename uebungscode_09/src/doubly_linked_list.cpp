#include <datenstrukturen/doubly_linked_list.hpp>
#include <datenstrukturen/doubly_linked_listnode.hpp>
#include <iostream>
#include <memory>

namespace Datenstrukturen {
    DoublyLinkedList::DoublyLinkedList() : head(nullptr), tail(nullptr) {
        // Init. head und tail fuer die Liste
    }

    DoublyLinkedListNode::DoublyLinkedListNode(int data) : next(nullptr), prev(), data_(data) {
        // Init. ein Knoten der Liste
    }

    DListNodeptr DoublyLinkedList::get_first() const {
        // Get the first Node of the current List
        return head;
    }

    DListNodeptr DoublyLinkedList::get_last() const {
        // Get the last Node of the current List
        return tail;
    }

    DListNodeptr DoublyLinkedList::insert_front(int x) {
        // Setzen neu head
        DListNodeptr n = std::make_shared<DoublyLinkedListNode>(x);
        n->next = head;
        head = n;
        head->prev.lock() = nullptr;
        if (tail == nullptr) {
            // Setzten tail zu head, falls die Liste erstmal erstellt wurde
            tail = head;
        }
        return head;
    }

    DListNodeptr DoublyLinkedList::insert_after(const DListNodeptr& pred, int x) {
        DListNodeptr n = std::make_shared<DoublyLinkedListNode>(x);  // Erstellen neu Knoten
        DListNodeptr alt_pointer = pred->next;                       // Alter Pointer, der auf den naechsten Element nach pred zeigte

        n->prev = pred;         // WeakPointer von n zeigt auf pred
        n->next = alt_pointer;  // Setzen naechster Pointer nach n auf vorherigen naechsten Poninter
        pred->next = n;         // Setzen Pointer von altem Element auf neuem Pointer

        // Pruefen, falls ein naechster Pointer nach pred exestiert
        if (alt_pointer) {
            // Fall ja, setzen prev dieses Pointers aus n
            alt_pointer->prev = n;
        } else {
            // Falls nein, dann n ist tail
            tail = n;
        }
        return n;
    }

    DListNodeptr DoublyLinkedList::remove(const DListNodeptr& n) {
        // Entfernt das Element
        if (n == head) {
            // Falls head entfernet wird
            head = head->next;
            return n;
        } else if (n == tail) {
            // Falls tail entfernet wird
            tail = n->prev.lock();
            tail->next = nullptr;
            return n;
        } else {
            // Falls ein Element der Liste entfernet wird
            n->next->prev = n->prev.lock();
            n->prev.lock()->next = n->next;
            return n;
        }
    }

    DListNodeptr DoublyLinkedList::next(const DListNodeptr& n) const {
        // Get the next Node of the current List
        if (n == tail) {
            // Falls tail ausgewaehlt wurde, return tail
            return tail;
        } else {
            return n->next;
        }
    }

    DListNodeptr DoublyLinkedList::prev(const DListNodeptr& n) const {
        // Get the previous Node of the current List=
        if (n == head) {
            // Falls tail ausgewaehlt wurde, return tail
            return head;
        } else {
            return n->prev.lock();
        }
    }

    void DoublyLinkedList::print() const {
        DListNodeptr aktuell = head;

        while (aktuell) {
            std::cout << aktuell->data_ << " -> ";
            aktuell = aktuell->next;
        }
        std::cout << "null" << std::endl;
    }

}  // namespace Datenstrukturen