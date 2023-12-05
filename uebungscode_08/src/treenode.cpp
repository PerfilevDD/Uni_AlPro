#include <datenstrukturen/binarytree.hpp>
#include <datenstrukturen/treenode.hpp>
#include <iostream>
#include <memory>
#include <queue>
#include <vector>

namespace Datenstrukturen {
    TreeNode::TreeNode(int data) : data_(data), left_child(nullptr), right_child(nullptr) {
        //  Init. data und children von Tree
    }

    BinaryTree::BinaryTree(int root_data) : root(nullptr) {
        // Init. root von Tree
        root = std::make_shared<TreeNode>(root_data);
    }

    // Returns a Shares Pointer to the current root
    TreeNodeptr BinaryTree::get_root() const {
        return root;
    }

    // Funktion mit Data
    int TreeNode::get_data() const {
        // Returns the data
        return data_;
    }

    void TreeNode::set_data(int data) {
        // Sets the data
        this->data_ = data;
    }

    // Funktion mit children
    std::shared_ptr<TreeNode> TreeNode::get_left_child() const {
        // Returns a Shared Pointer to the (current) left child
        return left_child;
    }
    std::shared_ptr<TreeNode> TreeNode::get_right_child() const {
        // Returns a Shared Pointer to the (current) right child
        return right_child;
    }

    // Funktion mit set child
    void TreeNode::set_left_child(int data) {
        // Sets the value of the left child (and creates the child if necessary)
        if (left_child == nullptr) {
            left_child = std::make_shared<TreeNode>(data);
            this->left_child;
        }
    }

    void TreeNode::set_right_child(int data) {
        // Sets the value of the right child (and creates the child if necessary)
        if (right_child == nullptr) {
            right_child = std::make_shared<TreeNode>(data);
            this->right_child;
        }
    }

    // Funktionen mit remove
    void TreeNode::remove_left_child() {
        // Removes the left child (if it exists)
        if (left_child != nullptr) {
            left_child = nullptr;
        }
    }

    void TreeNode::remove_right_child() {
        // Removes the right child (if it exists)
        if (right_child != nullptr) {
            right_child = nullptr;
        }
    }

    // Print-Funktion

    bool check_knoten(std::vector<TreeNodeptr> &arr, const TreeNodeptr &j) {
        // Funktion prueft, ob ein Knoten im Array schon ist
        for (const auto &unerk_knoten : arr) {
            if (unerk_knoten == j) {
                return true;
            }
        }

        return false;
    }

    void BinaryTree::print() const {
        std::queue<TreeNodeptr> queue;
        std::vector<TreeNodeptr> folge;  // Folge, um besuchte Knoten zu pruefen

        queue.push(nullptr);            // Push nullptr zu queue, damit BinaryTree mit Ebenen auszudrucken
        queue.push(root);               // Erste Knote in Tree (fuer queue)
        folge.push_back(root);          // Erste Knote in Tree (fuer folge)
        std::cout << root->get_data();  // Druckt die erste Knote in Tree

        // BreitenSuche-Funktion
        while (!queue.empty()) {
            // Gehen Queue durch
            TreeNodeptr v = queue.front();
            queue.pop();

            // Druckt die Knoten auf gleichem Level
            if (v == nullptr) {
                // Ende eines Levels erreicht
                if (!queue.empty()) {
                    // Wenn die Warteschlange noch weitere Elemente enthält, füge einen neuen Level hinzu
                    queue.push(nullptr);
                    std::cout << std::endl;  // Neue Zeile für das nächste Level
                }
            } else {
                if (v->get_left_child() != nullptr) {
                    TreeNodeptr left = v->get_left_child();
                    std::cout << left->get_data() << "  ";  // Druckt den aktuellen Knoten

                    // Pruefen falls der Knoten schon besucht war
                    if (!check_knoten(folge, left)) {
                        folge.push_back(left);
                        queue.push(left);
                    }
                }

                if (v->get_right_child() != nullptr) {
                    TreeNodeptr right = v->get_right_child();
                    std::cout << right->get_data() << "  ";  // Druckt den aktuellen Knoten

                    // Pruefen falls der Knoten schon besucht war
                    if (!check_knoten(folge, right)) {
                        folge.push_back(right);
                        queue.push(right);
                    }
                }
            }
        }
    }

}  // namespace Datenstrukturen