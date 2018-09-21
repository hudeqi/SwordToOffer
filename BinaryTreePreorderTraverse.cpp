#include<iostream>
#include<vector>
#include<stack>
#include<set>
#include"ListNode.h"
using namespace std;

vector<int> preorderTraversal(TreeNode* root) {
	if (!root)
		return vector<int>();
	stack<TreeNode*> temp;
	set<TreeNode*> tset;
	vector<int> result;
	temp.push(root);
	result.push_back(root->val);
	while (temp.size() != 0) {
		TreeNode* t = temp.top();
		if (t->left  && (tset.find(t->left) == tset.end())) {
			temp.push(t->left);
			tset.insert(t->left);
			result.push_back(t->left->val);
		}
		else {
			if (t->right && tset.find(t->right) == tset.end()) {
				temp.push(t->right);
				tset.insert(t->right);
				result.push_back(t->right->val);
			}
			else
			{
				temp.pop();
			}
		}
	}
	return result;
}

int main_BinaryPreOrderTraverse() {
	TreeNode t1(1);
	TreeNode t2(2);
	TreeNode t3(3);
	t1.right = &t2;
	t2.left = &t3;
	vector<int> result = preorderTraversal(&t1);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	system("pause");
	return 0;
}