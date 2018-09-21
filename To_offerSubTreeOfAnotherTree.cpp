#include<iostream>
#include"ListNode.h"
using namespace std;

/*找到两棵树的相同的根，在往下左右各个比对，直到比到最末尾*/
bool isSame(TreeNode* s, TreeNode* t) {
	if (s == NULL && t == NULL) return true;
	else if (s == NULL || t == NULL) return false;
	else return s->val == t->val && isSame(s->left, t->left) && isSame(s->right, t->right);
}

/*大树的根从上到下各个和子树的根慢慢比对*/
bool isSubtree(TreeNode* s, TreeNode* t) {
	if (t == NULL)
		return false;
	return s != NULL && (isSame(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t));
}


bool isSame1(TreeNode* s, TreeNode* t) {
	if (s == NULL && t == NULL) return true;
	else if (s != NULL && t == NULL) return true;
	else if (s == NULL && t != NULL) return false;
	else return s->val == t->val && isSame1(s->left, t->left) && isSame1(s->right, t->right);
}

/*不完全匹配的子树判断*/
bool isSubtree1(TreeNode* s, TreeNode* t) {
	if (t == NULL)
		return false;
	return s != NULL && (isSame1(s, t) || isSubtree1(s->left, t) || isSubtree1(s->right, t));
}

int main_SubTreeOfAnotherTree() {
	TreeNode s1(3);
	TreeNode s2(4);
	TreeNode s3(5);
	TreeNode s4(1);
	TreeNode s5(2);
	s1.left = &s2;
	s1.right = &s3;
	s2.left = &s4;
	s2.right = &s5;
	TreeNode t1(4);
	TreeNode t2(1);
	TreeNode t3(2);
	t1.left = &t2;
	t1.right = &t3;
	cout << isSubtree(&s1, &t1);
	system("pause");
	return 0;
}