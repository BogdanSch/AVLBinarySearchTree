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
	bool isEmpty() const;
	bool isFull();
	size_t getSize() const { return size; }
	void addItem(int newValue);
	void deleteItem(int valueToDelete);
	TreeNode *search(int value);
	AVLBinarySearchTree* symmetricalBBST();
	bool isEqual(const AVLBinarySearchTree& other) const;
	void printPreorder();
	void printInorder();
	void printPostorder();
	TreeNode* getRoot() const { return root; }
protected:
	void printPreorder(TreeNode *root);
	void printInorder(TreeNode *root);
	void printPostorder(TreeNode *root);
	TreeNode *addItem(int newValue, TreeNode *node);
	TreeNode *deleteItem(int valueToDelete, TreeNode *node);
	TreeNode* mirror(TreeNode* node);
	bool isEqualHelper(TreeNode* node1, TreeNode* node2) const;
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