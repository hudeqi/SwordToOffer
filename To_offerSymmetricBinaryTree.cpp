#include<iostream>
#include"ListNode.h"
using namespace std;

bool isEqual(TreeNode* left, TreeNode* right) {
	if (!left && !right) {
		return true;
	}
	if (!left)
		return false;
	if (!right)
		return false;
	return left->val == right->val && isEqual(left->left, right->right)
		&& isEqual(left->right, right->left);
}

bool isSymmetrical(TreeNode* pRoot)
{
	if (!pRoot || (!pRoot->left && !pRoot->right))
		return true;
	return isEqual(pRoot->left, pRoot->right);
}