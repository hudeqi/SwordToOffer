#include<iostream>
#include"ListNode.h"
#include<vector>
using namespace std;

vector<int> PrintFromTopToBottom(TreeNode* root) {
	if (!root)
		return vector<int>();
	vector<int> result;
	vector<TreeNode*> temp;
	temp.push_back(root);
	while (temp.size() != 0)
	{
		result.push_back(temp[0]->val);
		if (temp[0]->left) temp.push_back(temp[0]->left);
		if (temp[0]->right) temp.push_back(temp[0]->right);
		temp.erase(temp.begin());
	}
	return result;
}

vector<vector<int>> levelOrder(TreeNode* root) {
	if (!root)
		return vector<vector<int>>();
	vector<vector<int>> result;
	vector<vector<TreeNode*>> temp;
	temp.push_back(vector<TreeNode*>(1, root));
	while (temp.size() != 0)
	{
		vector<TreeNode*> next;
		vector<int> cur;
		if (temp[0].size() == 0)
			break;
		while (temp[0].size() != 0) {
			cur.push_back(temp[0][0]->val);
			if (temp[0][0]->left) next.push_back(temp[0][0]->left);
			if (temp[0][0]->right) next.push_back(temp[0][0]->right);
			temp[0].erase(temp[0].begin());
		}
		temp.push_back(next);
		temp.erase(temp.begin());
		result.push_back(cur);

	}
	return result;
}

int main_BinaryTreeLevelOrderTraverse() {
	TreeNode t1(4);
	TreeNode t2(9);
	TreeNode t3(0);
	TreeNode t4(5);
	TreeNode t5(1);
	t1.left = &t2;
	t1.right = &t3;
	t2.left = &t4;
	t2.right = &t5;
	//vector<int> result = PrintFromTopToBottom(&t1);
	vector<vector<int>> result = levelOrder(&t1);
	/*for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}*/
	system("pause");
	return 0;
}