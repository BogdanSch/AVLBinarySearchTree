#include "AVLBinarySearchTree.h"
#include <iostream>

using std::cout;
using std::max;

AVLBinarySearchTree::~AVLBinarySearchTree()
{
    destroyRecursive(root);
}

int AVLBinarySearchTree::retrieveHeight(TreeNode *node)
{
    if (node == nullptr)
    {
        return 0;
    }
    return node->getHeight();
}

int AVLBinarySearchTree::getBalanceFactor(TreeNode *node)
{
    return node == nullptr ? 0 : retrieveHeight(node->getRightNode()) - retrieveHeight(node->getLeftNode());
}

void AVLBinarySearchTree::destroyRecursive(TreeNode *node)
{
    if (node)
    {
        destroyRecursive(node->getLeftNode());
        destroyRecursive(node->getRightNode());
        delete node;
    }
}

bool AVLBinarySearchTree::isEmpty()
{
    return root == nullptr;
}

bool AVLBinarySearchTree::isFull(TreeNode *node)
{
    if (node == nullptr)
        return true;
    if (node->getRightNode() == nullptr && node->getLeftNode() == nullptr)
        return true;
    if (node->getRightNode() != nullptr && node->getLeftNode() != nullptr)
        return (isFull(node->getLeftNode()) && isFull(node->getRightNode()));

    return false;
}

bool AVLBinarySearchTree::isFull()
{
    return isFull(root);
}

TreeNode *AVLBinarySearchTree::addItem(int newValue, TreeNode *node)
{
    if (node == nullptr)
    {
        size++;
        return new TreeNode(newValue);
    }
    else if (node->getValue() == newValue)
    {
        return node;
    }
    else if (newValue < node->getValue())
    {
        // left sub-tree
        node->setLeftTreeNode(addItem(newValue, node->getLeftNode()));
    }
    else
    {
        // right sub-tree
        node->setRightTreeNode(addItem(newValue, node->getRightNode()));
    }

    node->setHeight(max(retrieveHeight(node->getLeftNode()), retrieveHeight(node->getRightNode())) + 1);
    int balanceFactor = getBalanceFactor(node);

    if (balanceFactor > 1 && newValue < node->getLeftNode()->getValue())
    {
        return rightRotate(node);
    }
    if (balanceFactor < -1 && newValue > node->getRightNode()->getValue())
    {
        return leftRotate(node);
    }
    if (balanceFactor > 1 && newValue > node->getLeftNode()->getValue())
    {
        node->setLeftTreeNode(leftRotate(node->getLeftNode()));
        return rightRotate(node);
    }
    if (balanceFactor < -1 && newValue < node->getRightNode()->getValue())
    {
        node->setRightTreeNode(rightRotate(node->getRightNode()));
        return leftRotate(node);
    }

    return node;
}

TreeNode *AVLBinarySearchTree::leftRotate(TreeNode *node)
{
	if (node == nullptr || node->getRightNode() == nullptr)
		return node;

    TreeNode *right = node->getRightNode();
    TreeNode *leftChildOfRight = right->getLeftNode();

    node->setRightTreeNode(leftChildOfRight);
    right->setLeftTreeNode(node);

    node->setHeight(max(node->getLeftNode()->getHeight(), node->getRightNode()->getHeight()) + 1);
    right->setHeight(max(right->getLeftNode()->getHeight(), right->getRightNode()->getHeight()) + 1);

    return right;
}

TreeNode *AVLBinarySearchTree::rightRotate(TreeNode *node)
{
	if (node == nullptr || node->getLeftNode() == nullptr)
		return node;

    TreeNode *left = node->getLeftNode();
    TreeNode *rightChildOfLeft = left->getRightNode();

    node->setLeftTreeNode(rightChildOfLeft);
    left->setRightTreeNode(node);

    node->setHeight(max(retrieveHeight(node->getLeftNode()), retrieveHeight(node->getRightNode())) + 1);
    left->setHeight(max(retrieveHeight(left->getLeftNode()), retrieveHeight(left->getRightNode())) + 1);

    return left;
}

void AVLBinarySearchTree::addItem(int newValue)
{
    root = addItem(newValue, root);
}

TreeNode *AVLBinarySearchTree::getMinNode(TreeNode *node)
{
    if (node == nullptr || node->getLeftNode() == nullptr)
        return node;
    return getMinNode(node->getLeftNode());
}

TreeNode *AVLBinarySearchTree::deleteItem(int valueToDelete, TreeNode *node)
{
	if (isEmpty())
	{
		cout << "Tree is empty. Cannot delete the item.\n";
		return nullptr;
	}

    if (node == nullptr)
    {
        return node;
    }
    else if (valueToDelete < node->getValue())
    {
        node->setLeftTreeNode(deleteItem(valueToDelete, node->getLeftNode()));
    }
    else if (valueToDelete > node->getValue())
    {
        node->setRightTreeNode(deleteItem(valueToDelete, node->getRightNode()));
    }
    else
    {
        if (node->getLeftNode() == nullptr)
        {
            TreeNode *temp = node->getRightNode();
            delete node;
            size--;
            return temp;
        }
        else if (node->getRightNode() == nullptr)
        {
            TreeNode *temp = node->getLeftNode();
            delete node;
            size--;
            return temp;
        }
        // find inorder successor
        TreeNode *temp = getMinNode(node->getRightNode());
        node->setValue(temp->getValue());
        node->setRightTreeNode(deleteItem(temp->getValue(), temp->getRightNode()));
    }

    node->setHeight(1 + max(retrieveHeight(node->getLeftNode()), retrieveHeight(node->getRightNode())));
    int balanceFactor = getBalanceFactor(node);

    if (balanceFactor > 1 && getBalanceFactor(node->getLeftNode()) >= 0)
    {
        return rightRotate(node);
    }
    if (balanceFactor < -1 && getBalanceFactor(node->getRightNode()) <= 0)
    {
        return leftRotate(node);
    }
    if (balanceFactor > 1 && getBalanceFactor(node->getLeftNode()) < 0)
    {
        node->setLeftTreeNode(leftRotate(node->getLeftNode()));
        return rightRotate(node);
    }
    if (balanceFactor < -1 && getBalanceFactor(node->getRightNode()) > 0)
    {
        node->setRightTreeNode(rightRotate(node->getRightNode()));
        return leftRotate(node);
    }

    return node;
}

void AVLBinarySearchTree::deleteItem(int valueToDelete)
{
    root = deleteItem(valueToDelete, root);
}

// O(log[n])
TreeNode *AVLBinarySearchTree::search(int value)
{
    TreeNode *currentNode = root;

    while (root != nullptr && currentNode->getValue() != value)
    {
        if (value < currentNode->getValue())
        {
            currentNode = currentNode->getLeftNode();
        }
        else
        {
            currentNode = currentNode->getRightNode();
        }
    }

    return currentNode;
}

void AVLBinarySearchTree::printPreorder()
{
    printPreorder(root);
}

void AVLBinarySearchTree::printInorder()
{
    printInorder(root);
}

void AVLBinarySearchTree::printPostorder()
{
    printPostorder(root);
}

void AVLBinarySearchTree::printPreorder(TreeNode *node)
{
    if (node == nullptr)
        return;

    cout << node->getValue() << " ";
    printPreorder(node->getLeftNode());
    printPreorder(node->getRightNode());
}

void AVLBinarySearchTree::printInorder(TreeNode *node)
{
    if (node == nullptr)
        return;

    printInorder(node->getLeftNode());
    cout << node->getValue() << " ";
    printInorder(node->getRightNode());
}

void AVLBinarySearchTree::printPostorder(TreeNode *node)
{
    if (node == nullptr)
        return;

    printPostorder(node->getLeftNode());
    printPostorder(node->getRightNode());
    cout << node->getValue() << " ";
}