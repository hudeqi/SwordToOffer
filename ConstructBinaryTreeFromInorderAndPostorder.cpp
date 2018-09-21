#include<iostream>
#include<vector>
#include<stack>
#include"ListNode.h"
using namespace std;

TreeNode* buildTree1(vector<int>& inorder, vector<int>& postorder) {
	if (postorder.size() == 0 || inorder.size() == 0)
		return NULL;
	stack<TreeNode*> pre;
	TreeNode *root = new TreeNode(postorder[postorder.size() - 1]);
	TreeNode* toLeft = NULL;
	TreeNode* t = NULL;
	pre.push(root);
	postorder.pop_back();
	while (inorder.size() != 0)
	{
		bool flag = false;
		while (pre.size() != 0 && pre.top()->val == inorder[inorder.size() - 1])
		{
			toLeft = pre.top();
			pre.pop();
			inorder.pop_back();
			flag = true;
		}
		if (inorder.size() > 0) {
			if (!flag) {
				t = pre.top();
				t->right = new TreeNode(postorder[postorder.size() - 1]);
				pre.push(t->right);
				postorder.pop_back();
			}
			else
			{
				toLeft->left = new TreeNode(postorder[postorder.size() - 1]);
				pre.push(toLeft->left);
				postorder.pop_back();
			}
		}
	}
	return root;
}

int main_ConstrcutBinaryFromInAndPost() {
	vector<int> postorder;
	vector<int> inorder;
	postorder.push_back(9);
	postorder.push_back(15);
	postorder.push_back(7);
	postorder.push_back(20);
	postorder.push_back(3);
	inorder.push_back(9);
	inorder.push_back(3);
	inorder.push_back(15);
	inorder.push_back(20);
	inorder.push_back(7);
	TreeNode* result = buildTree1(inorder, postorder);

	system("pause");
	return 0;
}