#include<iostream>
#include<string>
#include<vector>
#include"ListNode.h"
using namespace std;

string getStr(TreeNode* root) {
	if (!root)
		return "#,";
	string res = "";
	res += (to_string(root->val) + ",");
	res += getStr(root->left);
	res += getStr(root->right);
	return res;
}

char* Serialize(TreeNode *root) {
	string s = getStr(root);
	s = s.substr(0, s.length() - 1);
	char* a = new char[s.size() + 1];
	strcpy(a, s.c_str());
	return a;
}

TreeNode* Deserialize(char* &str) {
	if (!str || *str == '#') {
		str++;
		str++;
		return NULL;
	}
	int val = 0;
	while (*str != ',')
	{
		val = 10 * val + (*str - '0');
		str++;
	}
	str++;
	TreeNode* cur = new TreeNode(val);
	cur->left = Deserialize(str);
	cur->right = Deserialize(str);
	return cur;
}

int main_SeralizeAndDeseralizeOfBinaryTree() {
	TreeNode t1(8);
	TreeNode t2(6);
	TreeNode t3(10);
	TreeNode t4(5);
	TreeNode t5(7);
	TreeNode t6(9);
	TreeNode t7(11);
	t1.left = &t2;
	t1.right = &t3;
	t2.left = &t4;
	t2.right = &t5;
	t3.left = &t6;
	t3.right = &t7;
	char* c = Serialize(&t1);
	TreeNode* root = Deserialize(c);
	system("pause");
	return 0;
}