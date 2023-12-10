#include <datenstrukturen/binary_tree_node.hpp>

namespace Datenstrukturen {

    // Konstruktor
    // Bei der Objekterzeugung werden zuerst die Membervariablen initialisiert,
    // dabei wird das Member _parent mit dem übergegeben Wert parent initialisiert,
    // das Member _left_child wird mit dem Wert nullptr initialisiert (d.h., es ist noch kein linkes Kind vorhanden),
    // das Member _right_child wird mit dem Wert nullptr initialisiert (d.h., es ist noch kein rechted Kind vorhanden) und
    // das Member _data wird mit dem übergebenen Wert data initialisiert.
    // Anschließend wird der Funktionscode des Konstruktors ausgeführt, dieser ist hier leer,
    // da wir neben der Initialisierung nichts weiteres tun wollen.
    BinaryTreeNode::BinaryTreeNode(data_t data, NodeWeakPtr parent)
        : _parent(parent),
          _left_child(nullptr),
          _right_child(nullptr),
          _data(data) {
    }

    const BinaryTreeNode::data_t BinaryTreeNode::get_data() const {
        // Get Data
        return _data;
    }

    const BinaryTreeNode::data_t BinaryTreeNode::get_left_child_data() const {
        // Get Data of left child
        return _left_child->get_data();
    }

    const BinaryTreeNode::data_t BinaryTreeNode::get_right_child_data() const {
        // Get data of right child
        return _right_child->get_data();
    }

    BinaryTreeNode::NodeWeakPtr BinaryTreeNode::get_parent() {
        // Get Pointer to parent
        return this->_parent;
    }

    BinaryTreeNode::NodeSharedPtr BinaryTreeNode::get_left_child() {
        // Get pointer to left child
        return this->_left_child;
    }
    BinaryTreeNode::NodeSharedPtr BinaryTreeNode::get_right_child() {
        // Get pointer to right child
        return this->_right_child;
    }
    void BinaryTreeNode::set_left_child(data_t data) {
        // Set left child
        // Hier wird die Funktion weak_from_this verwendet, siehe auch Vorlesungsfolien.
        _left_child = std::make_shared<BinaryTreeNode>(data, weak_from_this());
    }

    void BinaryTreeNode::set_right_child(data_t data) {
        // Set left child
        // Hier wird die Funktion weak_from_this verwendet, siehe auch Vorlesungsfolien.
        _right_child = std::make_shared<BinaryTreeNode>(data, weak_from_this());
    }

    void BinaryTreeNode::del_left_child() {
        // Del left child
        this->_left_child = nullptr;
    }
    void BinaryTreeNode::del_right_child() {
        // Del right child
        this->_right_child = nullptr;
    }

}  // namespace Datenstrukturen
