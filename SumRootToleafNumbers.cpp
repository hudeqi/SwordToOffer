#include<iostream>
#include<vector>
#include"ListNode.h"
using namespace std;

void BFStoGetAllLeaf(vector<int>& result, TreeNode* root, int temp) {
	if (root->left == NULL && root->right == NULL) {
		result.push_back(temp);
		return;
	}
	if (root->left != NULL) BFStoGetAllLeaf(result, root->left, temp * 10 + root->left->val);
	if (root->right != NULL) BFStoGetAllLeaf(result, root->right, temp * 10 + root->right->val);
}

int sumNumbers(TreeNode* root) {
	if (root == NULL)
		return 0;
	vector<int> res;
	int result = 0;
	BFStoGetAllLeaf(res, root, root->val);
	for (int i = 0; i < res.size(); i++) {
		result += res[i];
	}
	return result;
}

int main_SumRootToleafNumbers() {
	TreeNode t1(4);
	//TreeNode t2(9);
	//TreeNode t3(0);
	//TreeNode t4(5);
	//TreeNode t5(1);
	//t1.left = &t2;
	//t1.right = &t3;
	//t2.left = &t4;
	//t2.right = &t5;
	int result = sumNumbers(&t1);
	cout << result << endl;
	system("pause");
	return 0;
}