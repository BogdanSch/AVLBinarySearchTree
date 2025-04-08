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
	cout << "\nDeleting 9:\n";
	tree.deleteItem(9);
	printTree(tree);
	cout << "Is tree full? " << (tree.isFull() ? "Yes" : "No") << "\n";

	/*cout << "\n";
	cout << "Deleting all the items and adding 120: \n";
    tree.deleteItem(12);
    tree.deleteItem(6);
    tree.deleteItem(10);
	tree.deleteItem(11);
    tree.deleteItem(8);
    tree.addItem(120);*/
	cout << "\n";
	cout << "Creating the mirror of the tree:\n";
	AVLBinarySearchTree* mirroredTree = tree.symmetricalBBST();
	printTree(*mirroredTree);
	cout << "Is tree full? " << (tree.isFull() ? "Yes" : "No") << "\n";
}