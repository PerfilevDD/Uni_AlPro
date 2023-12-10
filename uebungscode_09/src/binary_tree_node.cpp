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
        return _data;
    }

    const BinaryTreeNode::data_t BinaryTreeNode::get_left_child_data() const {
        return _left_child->get_data();
    }

    const BinaryTreeNode::data_t BinaryTreeNode::get_right_child_data() const {
        return _right_child->get_data();
    }

    BinaryTreeNode::NodeSharedPtr BinaryTreeNode::get_left_child() {
      return this->_left_child;
    }
    BinaryTreeNode::NodeSharedPtr BinaryTreeNode::get_right_child() {
      return this->_right_child;
    }
    void BinaryTreeNode::set_left_child(data_t data) {
        // Hier wird die Funktion weak_from_this verwendet, siehe auch Vorlesungsfolien.
        _left_child = std::make_shared<BinaryTreeNode>(data, weak_from_this());
    }

    void BinaryTreeNode::set_right_child(data_t data) {
        // Hier wird die Funktion weak_from_this verwendet, siehe auch Vorlesungsfolien.
        _right_child = std::make_shared<BinaryTreeNode>(data, weak_from_this());
    }

}  // namespace Datenstrukturen
