#include<iostream>
#include<vector>
#include<stack>
#include"ListNode.h"
using namespace std;

//ǰ���ǰ�濪ʼѹջ����ջ����������Ԫ����ͬ��ջpop������ȥ�ף�ֱ�������գ����غ������ʼ����ָ��
//������ɺ������ý�����ֲ��������ݶ�ʧ�����
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
	if (preorder.size() == 0 || inorder.size() == 0)
		return NULL;
	stack<TreeNode*> pre;
	TreeNode *root = new TreeNode(preorder[0]);
	TreeNode* toRight = NULL;
	TreeNode* t = NULL;
	pre.push(root);
	preorder.erase(preorder.begin());
	while (inorder.size() != 0)
	{
		bool flag = false;
		while (pre.size() != 0 && pre.top()->val == inorder[0])
		{
			toRight = pre.top();
			pre.pop();
			inorder.erase(inorder.begin());
			flag = true;
		}
		if (inorder.size() > 0) {
			if (!flag) {
				t = pre.top();
				t->left = new TreeNode(preorder[0]);
				pre.push(t->left);
				preorder.erase(preorder.begin());
			}
			else
			{
				toRight->right = new TreeNode(preorder[0]);
				pre.push(toRight->right);
				preorder.erase(preorder.begin());
			}
		}
	}
	return root;
}

int main_ConstrcutBinaryTreeFromPreAndIn() {
	vector<int> preorder;
	vector<int> inorder;
	preorder.push_back(3);
	preorder.push_back(9);
	preorder.push_back(20);
	preorder.push_back(15);
	preorder.push_back(7);
	inorder.push_back(9);
	inorder.push_back(3);
	inorder.push_back(15);
	inorder.push_back(20);
	inorder.push_back(7);
	TreeNode* result = buildTree(preorder, inorder);

	system("pause");
	return 0;
}