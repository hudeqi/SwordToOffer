#include<iostream>
#include"ListNode.h"
#include<algorithm>
using namespace std;

extern int TreeDepth(TreeNode* root);

bool IsBalanced_Solution(TreeNode* pRoot) {
	if (!pRoot)
		return true;
	return abs(TreeDepth(pRoot->left) - TreeDepth(pRoot->right)) < 2 &&
		IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
}

int main_BalancedBinaryTree() {
	TreeNode t1(3);
	TreeNode t2(9);
	TreeNode t3(20);
	TreeNode t4(15);
	TreeNode t5(17);
	TreeNode t6(8);
	t1.left = &t2;
	t1.right = &t3;
	t3.left = &t4;
	t3.right = &t5;
	t5.right = &t6;
	cout << IsBalanced_Solution(&t1);
	system("pause");
	return 0;
}