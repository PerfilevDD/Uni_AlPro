#include <datenstrukturen/binary_tree.hpp>

namespace Datenstrukturen {

// Konstruktor
// Bei der Objekterzeugung werdne zuerst die Membervariablen initialisiert,
// dabei wird das Member _root mit dem Wert nullptr initialisiert, das heißt, es ist zunächst keine Wurzel vorhanden,
// das entspricht also dem leeren Baum.
// Anschließend wird der Funktionscode des Konstruktors ausgeführt, dieser ist hier leer,
// da wir neben der Initialisierung nichts weiteres tun wollen.
BinaryTree::BinaryTree()
  : _root(nullptr)
{  
}
  
const BinaryTreeNodeSharedPtr BinaryTree::get_root() const {
  return _root;
}

void BinaryTree::set_root(BinaryTreeNode::data_t data) {
  _root = std::make_shared<BinaryTreeNode>(data);
}

}
