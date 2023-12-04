#include <datenstrukturen/binarytree.hpp>
#include <datenstrukturen/treenode.hpp>
#include <iostream>
#include <memory>
#include <queue>
#include <vector>

namespace Datenstrukturen {
    TreeNode::TreeNode(int data) : data_(data), left_child(nullptr), right_child(nullptr) {
        // set_data(4);
        // std::cout << "init" << std::endl;
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
        return data_;
    }

    void TreeNode::set_data(int data) {
        // set_left_child(data);
        left_child->set_left_child(data);
    }

    // Funktion mit Shared Pointer
    std::shared_ptr<TreeNode> TreeNode::get_left_child() const {
        // TreeNodeptr n = BinaryTree::get_root();
        // std::cout << "left_child aus get left " << left_child << std::endl;
        return left_child;
    }
    std::shared_ptr<TreeNode> TreeNode::get_right_child() const {
        return right_child;
    }

    // Funktion mit set child
    void TreeNode::set_left_child(int data) {
        std::cout << "this " << this << std::endl;
        if (left_child == nullptr) {
            // TreeNodeptr left_child(new TreeNode(data));

            left_child = std::make_shared<TreeNode>(data);
            std::cout << "left_child->get_data() " << left_child->get_data() << std::endl;
            std::cout << "left_child " << left_child << std::endl;
            this->left_child;
        }
    }

    void TreeNode::set_right_child(int data) {
    }

    void BinaryTree::print() const {
        if (root == nullptr) {
            return;
        }
    }

    bool check_knoten(std::vector<int> &arr, const size_t &j) {
        // Funktion prueft ob ein Knoten im Array schon ist
        for (const auto &unerk_knoten : arr) {
            if (unerk_knoten == j) {
                return true;
            }
        }
        return false;
    }

    void BinaryTree::print() const {
        std::cout << "root->get_left_child() " << root->get_left_child() << std::endl;
        std::cout << "root->get_left_child()->get_left_child()->get_data() " << root->get_left_child()->get_left_child()->get_data() << std::endl;
        std::cout << "root->get_data() " << root->get_data() << std::endl;

        // BreitenSuche-Funktion
        std::queue<TreeNodeptr> queue;
        std::vector<int> folge;
        int knoten_anz = root.use_count();
        std::vector<bool> erkunden(knoten_anz, false);

        TreeNodeptr s = root;

        queue.push(s);
        folge.push_back(s->get_data());
        // Gehen Queue durch
        while (!queue.empty()) {
            TreeNodeptr v = queue.front();
            queue.pop();
            if (v->get_left_child() != nullptr) {
                TreeNodeptr left = v->get_left_child();
                // Pruefen falls der Knoten schon besucht war
                if (!check_knoten(folge, left->get_data())) {
                    folge.push_back(left->get_data());
                    queue.push(left);
                }
            }

            if (v->get_right_child() != nullptr) {
                TreeNodeptr right = v->get_right_child();
                // Pruefen falls der Knoten schon besucht war
                if (!check_knoten(folge, right->get_data())) {
                    folge.push_back(right->get_data());
                    queue.push(right);
                }
            }
        }
    }

}  // namespace Datenstrukturen