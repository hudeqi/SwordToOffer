#include<iostream>
#include<vector>
#include<stack>
#include<set>
#include<algorithm>
#include"ListNode.h"
using namespace std;

bool lenCompare(vector<int> a, vector<int> b) {
	return a.size() > b.size();
}

vector<vector<int>> FindPath(TreeNode* root, int expectNumber) {
	vector<vector<int>> result;
	if (!root)
		return vector<vector<int>>();
	stack<TreeNode*> temp;
	vector<int> path;
	set<TreeNode*> tset;
	int sum = 0;
	temp.push(root);
	tset.insert(root);
	path.push_back(root->val);
	sum += temp.top()->val;
	while (temp.size() != 0)
	{
		TreeNode* cur = temp.top();
		bool flag = cur->left || cur->right;
		if (cur->left && tset.find(cur->left) == tset.end()) {
				temp.push(cur->left);
				path.push_back(cur->left->val);
				sum += cur->left->val;
				tset.insert(cur->left);
		}
		else if (cur->right && tset.find(cur->right) == tset.end()) {
				temp.push(cur->right);
				path.push_back(cur->right->val);
				sum += cur->right->val;
				tset.insert(cur->right);
		}
		else
		{
			if (sum == expectNumber && !flag) {
				result.push_back(path);
			}
			sum -= temp.top()->val;
			temp.pop();
			path.pop_back();
		}
	}
	sort(result.begin(), result.end(), lenCompare);
	return result;
}

int main_FindPathWithSumInBinaryTree() {
	TreeNode t1(4);
	TreeNode t2(9);
	TreeNode t3(0);
	TreeNode t4(5);
	TreeNode t5(1);
	t1.left = &t2;
	t1.right = &t3;
	t2.left = &t4;
	t2.right = &t5;
	vector<vector<int>> result = FindPath(&t1, 14);
	system("pause");
	return 0;
}