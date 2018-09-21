#include<iostream>
#include"ListNode.h"
using namespace std;

//��û��Ŀ����������һֱ�����ߣ����ߵ�Ҷ�ӽڵ㣬�������Ҿ��գ�����NULL��
//�����Ϸ���NULL�����������������ߵ�Ŀ���ʱ���ͷ���Ŀ��㣬���ĸ��ڵ�Ҳ����Ŀ��㣬
//��һ����������ӽڵ㷵�صľ�����NULL��˵���ýڵ��������������Ƚڵ㡣
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