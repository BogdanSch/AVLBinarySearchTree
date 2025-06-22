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
	cout << "Creating a normal tree:\n";
    AVLBinarySearchTree tree(10);
    tree.addItem(8);
    tree.addItem(12);
    tree.addItem(6);
	tree.addItem(11);
	tree.addItem(9);
	printTree(tree);
	cout << "\n";

	cout << "Deleting 9:\n";
	tree.deleteItem(9);
	printTree(tree);
	cout << "Is tree full? " << (tree.isFull() ? "Yes" : "No") << "\n";
	cout << "\n";

	cout << "Creating the mirror of the tree:\n";
	AVLBinarySearchTree* mirroredTree = tree.symmetricalBBST();
	printTree(*mirroredTree);
	cout << "Is tree full? " << (tree.isFull() ? "Yes" : "No") << "\n";
	cout << "\n";

	cout << "Are threes equal? " << (tree.isEqual(*mirroredTree) ? "Yes" : "No") << "\n";
}