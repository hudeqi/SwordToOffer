#include<iostream>
#include<stack>
#include"ListNode.h"
using namespace std;

TreeNode* KthNode(TreeNode* pRoot, int k)
{
	TreeNode* result = NULL;
	int count = 0;
	if (pRoot == NULL)
		return result;
	stack<TreeNode*> S;
	TreeNode* cur = pRoot;
	while (cur != NULL || !S.empty())
	{
		while (cur != NULL)
		{
			S.push(cur);
			cur = cur->left;
		}
		TreeNode* temp = S.top();
		count++;
		if (count == k)
			return temp;
		S.pop();
		cur = temp->right;
	}
	return result;
}