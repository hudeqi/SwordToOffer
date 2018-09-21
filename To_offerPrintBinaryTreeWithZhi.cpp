#include<iostream>
#include<vector>
#include"ListNode.h"
using namespace std;

vector<vector<int>> Print(TreeNode* pRoot) {
	if (!pRoot)
		return vector<vector<int>>();
	vector<vector<int>> resuslt;
	resuslt.push_back(vector<int>(1, pRoot->val));
	vector<TreeNode*> tempEven;
	vector<TreeNode*> tempOdd;
	vector<int> t;
	int count = 0;
	tempOdd.push_back(pRoot);
	while (tempEven.size() != 0 || tempOdd.size() != 0)
	{
		if (count % 2 == 0) {
			while (tempOdd.size() != 0)
			{
				TreeNode* tree = tempOdd.back();
				tempOdd.pop_back();
				if (tree->right) {
					tempEven.push_back(tree->right);
					t.push_back(tree->right->val);
				}
				if (tree->left) {
					tempEven.push_back(tree->left);
					t.push_back(tree->left->val);
				}
			}
			if (t.size() != 0) {
				resuslt.push_back(t);
				t.clear();
			}
		}
		count++;
		if (count % 2 == 1) {
			while (tempEven.size() != 0)
			{
				TreeNode* tree = tempEven.back();
				tempEven.pop_back();
				if (tree->left) {
					tempOdd.push_back(tree->left);
					t.push_back(tree->left->val);
				}
				if (tree->right) {
					tempOdd.push_back(tree->right);
					t.push_back(tree->right->val);
				}
			}
			if (t.size() != 0) {
				resuslt.push_back(t);
				t.clear();
			}
		}
		count++;
	}
	return resuslt;
}

int main_PrintBinaryTreeWithZhi() {
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
	vector<vector<int>> result = Print(&t1);
	system("pause");
	return 0;
}