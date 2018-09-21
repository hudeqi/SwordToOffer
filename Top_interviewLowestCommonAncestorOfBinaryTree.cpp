#include<iostream>
#include"ListNode.h"
using namespace std;

//在没有目标点的子树下一直往下走，若走到叶子节点，由于左右均空，返回NULL，
//就往上返回NULL。而在其他子树上走到目标点时，就返回目标点，他的父节点也返回目标点，
//当一个点的左右子节点返回的均不是NULL，说明该节点就是最近公共祖先节点。
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	if (!root || p == root || q == root)
		return root;
	TreeNode* left = lowestCommonAncestor(root->left, p, q);
	TreeNode* right = lowestCommonAncestor(root->right, p, q);
	return !left ? right : !right ? left : root;
}

int main_LowestCommonAncestorOfBinaryTree() {
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
	TreeNode* result = lowestCommonAncestor(&t1, &t4, &t6);
	cout << result->val;
	system("pause");
	return 0;
}