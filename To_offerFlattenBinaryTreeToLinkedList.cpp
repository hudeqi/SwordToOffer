#include<iostream>
#include<stack>
#include"ListNode.h"
using namespace std;

TreeNode* Convert(TreeNode* pRootOfTree)
{
	if (!pRootOfTree)
		return NULL;
	if (!pRootOfTree->left && !pRootOfTree->right) {
		return pRootOfTree;
	}
	stack<TreeNode*> s;
	TreeNode* cur = pRootOfTree;
	TreeNode* pre = NULL;
	while (cur || !s.empty())
	{
		while (cur)
		{ 
				s.push(cur); 
				cur = cur->left;
		}
		TreeNode* top = s.top();
		top->left = pre;
		pre = top;
		s.pop();
		cur = top->right;
	}
	//TreeNode* head = pre;
	pre->right = NULL;
	TreeNode* temp = NULL;
	while (pre->left)
	{
		temp = pre;
		pre = pre->left;
		pre->right = temp;
	}
	return pre;
}

int main_FlattenBinaryTreeToLinkedList() {
	TreeNode t1(4);
	TreeNode t2(9);
	TreeNode t3(0);
	TreeNode t4(5);
	TreeNode t5(1);
	t1.left = &t2;
	t1.right = &t3;
	t2.left = &t4;
	t2.right = &t5;
	TreeNode* result = Convert(&t1);
	system("pause");
	return 0;
}