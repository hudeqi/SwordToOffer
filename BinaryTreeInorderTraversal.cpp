#include<iostream>
#include<vector>
#include<stack>
#include"ListNode.h"
using namespace std;

vector<int> inorderTraversal(TreeNode* root) {
	vector<int> result;
	if (!root)
		return result;
	if (root->left == NULL && root->right != NULL) {
		vector<int> right = inorderTraversal(root->right);
		result.push_back(root->val);
		for (int i = 0; i < right.size(); i++)
			result.push_back(right[i]);
	}
	else if (root->right == NULL && root->left != NULL) {
		vector<int> left = inorderTraversal(root->left);
		for (int i = 0; i < left.size(); i++)
			result.push_back(left[i]);
		result.push_back(root->val);
	}
	else if (root->left != NULL && root->right != NULL) {
		vector<int> left = inorderTraversal(root->left);
		vector<int> right = inorderTraversal(root->right);
		for (int i = 0; i < left.size(); i++)
			result.push_back(left[i]);
		result.push_back(root->val);
		for (int i = 0; i < right.size(); i++)
			result.push_back(right[i]);
	}
	else
	{
		result.push_back(root->val);
	}
	return result;
}

vector<int> inorderTraversalWithIterator(TreeNode* root) {
	vector<int> result;
	if (root == NULL)
		return result;
	stack<TreeNode*> S;
	TreeNode* cur = root;
	while (cur != NULL || !S.empty())
	{
		while (cur != NULL)
		{
			S.push(cur);
			cur = cur->left;
		}
		TreeNode* temp = S.top();
		result.push_back(temp->val);
		S.pop();
		cur = temp->right;
	}
	return result;
}

int main_BinaryTreeorderTraversal() {
	TreeNode t1(1);
	TreeNode t2(2);
	TreeNode t3(3);
	TreeNode t4(4);
	TreeNode t5(5);
	TreeNode t6(6);
	t1.left = &t2;
	t1.right = &t3;
	t2.left = &t4;
	t2.right = &t5;
	t3.left = &t6;
	//vector<int> result = inorderTraversal(&t1);
	vector<int> result = inorderTraversalWithIterator(&t1);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << endl;
	}
	system("pause");
	return 0;
}