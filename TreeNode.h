#pragma once
class TreeNode
{
public:
	TreeNode(int value) { this->value = value; right = left = nullptr; }
	int getValue() const { return value; }
	void setValue(int newValue) { value = newValue; }
	int getHeight() const { return height; }
	void setHeight(int newHeight) { height = newHeight; }
	TreeNode* getRightNode() const { return right; }
	void setRightTreeNode(TreeNode* newNode) { right = newNode; }
	TreeNode* getLeftNode() const { return left; }
	void setLeftTreeNode(TreeNode* newNode) { left = newNode; }
private:
	int value;
	int height = 1;
	TreeNode* right;
	TreeNode* left;
};

