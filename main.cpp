#include <iostream>
#include "AVLBinarySearchTree.h"

using std::cout;

int main()
{
    AVLBinarySearchTree tree(10);
    tree.addItem(8);
    tree.addItem(12);
    tree.addItem(6);

    tree.printPreorder();
    cout << "\n";
    tree.printInorder();
    cout << "\n";
    tree.printPostorder();
    cout << "\n";

    tree.deleteItem(12);
    tree.printPreorder();
    cout << "\n";
    tree.printInorder();
    cout << "\n";
    tree.printPostorder();
    cout << "\n";
}