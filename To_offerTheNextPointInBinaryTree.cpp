#include<iostream>
using namespace std;

struct TreeLinkNode {
	int val;
	struct TreeLinkNode *left;
	struct TreeLinkNode *right;
	struct TreeLinkNode *next;
	TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {}
};

TreeLinkNode* GetNext(TreeLinkNode* pNode)
{
	if (!pNode)
		return NULL;
	if (!pNode->next) {
		if (!pNode->right)
			return NULL;
		TreeLinkNode* cur = pNode->right;
		while (cur->left)
		{
			cur = cur->left;
		}
		return cur;
	}
	if (pNode->next && pNode->next->right != pNode) {
		if (!pNode->right) {
			return pNode->next;
		}
		else {
			if (pNode->right && pNode->right->left) {
				TreeLinkNode* cur = pNode->right->left;
				while (cur->left)
				{
					cur = cur->left;
				}
				return cur;
			}
			else if (pNode->right && !pNode->right->left) {
				return pNode->right;
			}
		}
	}
	if (pNode->next && pNode->next->right == pNode) {
		if (!pNode->right){
			if (pNode->next->next) {
				if (pNode->next->next->left == pNode->next)
					return pNode->next->next;
				else {
					return NULL;
				}
			}
			else {
				return NULL;
			}
		}
		else {
			TreeLinkNode* cur = pNode->right;
			while (cur->left)
			{
				cur = cur->left;
			}
			return cur;
		}
	}
	if (pNode->next && !pNode->next->right)
	{
		return pNode->next;
	}
	return NULL;
}