#include <datenstrukturen/binary_tree.hpp>
#include <iostream>
#include <stack>

namespace Datenstrukturen {

    // Konstruktor
    // Bei der Objekterzeugung werdne zuerst die Membervariablen initialisiert,
    // dabei wird das Member _root mit dem Wert nullptr initialisiert, das heißt, es ist zunächst keine Wurzel vorhanden,
    // das entspricht also dem leeren Baum.
    // Anschließend wird der Funktionscode des Konstruktors ausgeführt, dieser ist hier leer,
    // da wir neben der Initialisierung nichts weiteres tun wollen.
    BinaryTree::BinaryTree() : _root(nullptr) {
    }

    const BinaryTreeNodeSharedPtr BinaryTree::get_root() const {
        return _root;
    }

    void BinaryTree::set_root(BinaryTreeNode::data_t data) {
        _root = std::make_shared<BinaryTreeNode>(data);
    }

    void BinaryTree::print_preorder() const {
        // Print PreOrder
        std::stack<BinaryTreeNode::NodeSharedPtr> stack;
        stack.push(_root);

        // Gehen Stack durch
        while (!stack.empty()) {
            BinaryTreeNode::NodeSharedPtr aktuell = stack.top();
            stack.pop();

            // Fuehlen Stack zuerst mit rechten Kinder und dann mit linken(falls sie exsetieren)
            if (aktuell->get_right_child() != nullptr) {
                stack.push(aktuell->get_right_child());
            }
            if (aktuell->get_left_child() != nullptr) {
                stack.push(aktuell->get_left_child());
            }

            // Drucken die Data des Knotes
            if (stack.empty()) {
                // Wird ganz am Ende erfuellt
                std::cout << aktuell->get_data() << std::endl;
            } else {
                std::cout << aktuell->get_data() << " -> ";
            }
        }
    }

    void BinaryTree::print_inorder() const {
        // Print InOrder
        std::stack<BinaryTreeNode::NodeSharedPtr> stack;
        BinaryTreeNode::NodeSharedPtr aktuell = _root;

        // Gehen Stack durch
        while (aktuell != nullptr || !stack.empty()) {
            // Suchen nach allen Kindern am Links
            while (aktuell != nullptr) {
                stack.push(aktuell);
                aktuell = aktuell->get_left_child();
            }

            aktuell = stack.top();
            stack.pop();

            // std::cout << aktuell->get_data() << " -> ";
            // Drucken die Data des Knotes
            if (stack.empty() && aktuell->get_right_child() == nullptr) {
                // Wird ganz am Ende erfuellt
                std::cout << aktuell->get_data() << std::endl;
            } else {
                std::cout << aktuell->get_data() << " -> ";
            }
            aktuell = aktuell->get_right_child();
        }
    }

}  // namespace Datenstrukturen
