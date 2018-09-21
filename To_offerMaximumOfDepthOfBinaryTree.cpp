#include<iostream>
#include"ListNode.h"
#include<algorithm>
using namespace std;

int TreeDepth(TreeNode* pRoot)
{
	if (!pRoot)
		return 0;
	if (!pRoot->left && !pRoot->right)
		return 1;
	return max(TreeDepth(pRoot->left), TreeDepth(pRoot->right)) + 1;
}