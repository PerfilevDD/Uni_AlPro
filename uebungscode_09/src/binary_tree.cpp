#include <datenstrukturen/binary_tree.hpp>
#include <iostream>
#include <queue>
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

    // Funktion fuer LevelOrder, um die besuchten Knoten zu pruefen
    bool check_knoten(std::vector<BinaryTreeNode::NodeSharedPtr> &arr, const BinaryTreeNode::NodeSharedPtr &is_visited) {
        // Funktion prueft, ob ein Knoten im Array schon ist
        for (const auto &unerk_knoten : arr) {
            if (unerk_knoten == is_visited) {
                return true;
            }
        }

        return false;
    }
    void BinaryTree::print_postorder() const {
        // Print PostOrder
        std::stack<BinaryTreeNode::NodeSharedPtr> stack;
        std::vector<BinaryTreeNode::NodeSharedPtr> folge;
        folge.push_back(_root);
        stack.push(_root);
        while (!stack.empty()) {
            BinaryTreeNode::NodeSharedPtr aktuell = stack.top();

            if ((aktuell->get_left_child() == nullptr && aktuell->get_right_child() == nullptr) ||
                check_knoten(folge, aktuell->get_left_child()) || check_knoten(folge, aktuell->get_right_child())) {
                if (stack.top() == _root) {
                    // Wird ganz am Ende erfuellt
                    std::cout << aktuell->get_data() << std::endl;
                } else {
                    std::cout << aktuell->get_data() << " -> ";
                }

                stack.pop();
            }
            if (aktuell->get_right_child() != nullptr && !check_knoten(folge, aktuell->get_right_child())) {
                folge.push_back(aktuell->get_right_child());
                stack.push(aktuell->get_right_child());
            }

            if (aktuell->get_left_child() != nullptr && !check_knoten(folge, aktuell->get_left_child())) {
                folge.push_back(aktuell->get_left_child());
                stack.push(aktuell->get_left_child());
            }
        }
    }

    void BinaryTree::print_levelorder() const {
        // LevelOreder aka BreitenSuche
        std::queue<BinaryTreeNode::NodeSharedPtr> queue;
        std::vector<BinaryTreeNode::NodeSharedPtr> folge;  // Folge, um besuchte Knoten zu pruefen
        queue.push(_root);                                 // Erste Knote in Tree (fuer queue)
        folge.push_back(_root);                            // Erste Knote in Tree (fuer folge)

        // BreitenSuche-Funktion
        while (!queue.empty()) {
            // Gehen Queue durch
            BinaryTreeNode::NodeSharedPtr aktuell = queue.front();
            queue.pop();

            if (aktuell->get_left_child() != nullptr) {
                BinaryTreeNode::NodeSharedPtr left = aktuell->get_left_child();
                // Pruefen falls der Knoten schon besucht war
                if (!check_knoten(folge, left)) {
                    folge.push_back(left);
                    queue.push(left);
                }
            }

            if (aktuell->get_right_child() != nullptr) {
                BinaryTreeNode::NodeSharedPtr right = aktuell->get_right_child();
                // Pruefen falls der Knoten schon besucht war
                if (!check_knoten(folge, right)) {
                    folge.push_back(right);
                    queue.push(right);
                }
            }
        }

        // Print alle Knoten, die in vector gespeicher sind
        for (int i = 0; i < folge.size(); i++) {
            if (i == folge.size() - 1) {
                std::cout << folge[i]->get_data() << std::endl;
            } else {
                std::cout << folge[i]->get_data() << " -> ";
            }
        }
    }
}  // namespace Datenstrukturen
