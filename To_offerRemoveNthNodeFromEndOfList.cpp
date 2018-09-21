#include<iostream>
#include<vector>
#include"ListNode.h"
using namespace std;

ListNode* removeNthFromEnd(ListNode* head, int n) {
	if (head->next == NULL)
		return NULL;
	vector<ListNode*> address;
	ListNode* cur = head;
	address.push_back(cur);
	while (cur->next != NULL)
	{
		cur = cur->next;
		address.push_back(cur);
	}
	cur = head;
	if (address.size() - n == 0) {
		cur->next = NULL;
		return address[1];
	}
	while (cur->next != address[address.size() - n])
	{
		cur = cur->next;
	}
	if (address.size() - n == address.size() - 1) {
		cur->next = NULL;
	}
	else {
		cur->next = address[address.size() - n + 1];
	}
	return head;
}

ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
	vector<ListNode*> temp;
	if (pListHead == NULL)
		return NULL;
	while (pListHead != NULL) {
		temp.push_back(pListHead);
		pListHead = pListHead->next;
	}
	if (k == 0 || k > temp.size())
		return NULL;
	return temp[temp.size() - k];
}

void main_REmoveNthNodeFromEndOfList() {
	ListNode a(1);
	ListNode b(2);
	a.next = &b;
	//ListNode *head = removeNthFromEnd(&a, 2);
	//ListNode* cur = head;
	//cout << cur->val << " ";
	//while (cur->next != NULL)
	//{
	//	cur = cur->next;
	//	cout << cur->val << " ";
	//}
	ListNode* result = FindKthToTail(&a, 2);
	cout<<result->val;
	system("pause");
}