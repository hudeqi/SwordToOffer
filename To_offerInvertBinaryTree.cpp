#include<iostream>
#include "ListNode.h"
#include<stack>
using namespace std;

void Mirror(TreeNode *pRoot) {
	if (!pRoot)
		return;
	stack<TreeNode*> temp;
	temp.push(pRoot);
	while (!temp.empty())
	{
		TreeNode* t = temp.top();
		temp.pop();
		TreeNode* tempt = t->left;
		t->left = t->right;
		t->right = tempt;
		if (t->left) temp.push(t->left);
		if (t->right) temp.push(t->right);
	}
}

int main_InvertBinary() {
	TreeNode s1(3);
	TreeNode s2(4);
	TreeNode s3(5);
	TreeNode s4(1);
	TreeNode s5(2);
	s1.left = &s2;
	s1.right = &s3;
	s2.left = &s4;
	s2.right = &s5;
	system("pause");
	return 0;
}