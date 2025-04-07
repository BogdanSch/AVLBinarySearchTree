#include <iostream>
#include "AVLBinarySearchTree.h"

using std::cout;

void printTree(AVLBinarySearchTree& tree)
{
	cout << "Preorder: ";
	tree.printPreorder();
	cout << "\nInorder: ";
	tree.printInorder();
	cout << "\nPostorder: ";
	tree.printPostorder();
	cout << "\n";
}

int main()
{
    AVLBinarySearchTree tree(10);
    tree.addItem(8);
    tree.addItem(12);
    tree.addItem(6);
	cout << "Is tree full? " << (tree.isFull() ? "Yes" : "No") << "\n";

	printTree(tree);

	cout << "\n";
	cout << "Deleting all the items and adding 120: \n";
    tree.deleteItem(12);
    tree.deleteItem(6);
    tree.deleteItem(10);
	tree.deleteItem(8);
    tree.deleteItem(8);
    tree.addItem(120);

	printTree(tree);
}