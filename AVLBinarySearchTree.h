#pragma once
#include "TreeNode.h"

class AVLBinarySearchTree
{
public:
	AVLBinarySearchTree() { root = nullptr; size = 0; }
	AVLBinarySearchTree(int initValue) { root = new TreeNode(initValue); size = 1; }
	AVLBinarySearchTree(TreeNode* otherRoot) { root = otherRoot; }
	~AVLBinarySearchTree();
	void destroyRecursive(TreeNode *node);
	bool isEmpty();
	bool isFull();
	size_t getSize() const { return size; }
	void addItem(int newValue);
	void deleteItem(int valueToDelete);
	TreeNode *search(int value);
	AVLBinarySearchTree* symmetricalBBST();
	void printPreorder();
	void printInorder();
	void printPostorder();

protected:
	void printPreorder(TreeNode *root);
	void printInorder(TreeNode *root);
	void printPostorder(TreeNode *root);
	TreeNode *addItem(int newValue, TreeNode *node);
	TreeNode *deleteItem(int valueToDelete, TreeNode *node);
	TreeNode* mirror(TreeNode* node);
private:
	TreeNode* root = nullptr;
	size_t size = 0;
	TreeNode *leftRotate(TreeNode *node);
	TreeNode *rightRotate(TreeNode *node);
	int getBalanceFactor(TreeNode *node);
	TreeNode *getMinNode(TreeNode *node);
	int retrieveHeight(TreeNode *node);
	bool isFull(TreeNode* node);
};