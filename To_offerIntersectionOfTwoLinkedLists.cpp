#include<iostream>
#include"ListNode.h"
using namespace std;

ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
	if (!pHead1 || !pHead2)
		return NULL;
	ListNode* cur1 = pHead1;
	ListNode* cur2 = pHead2;
	while (cur1 != cur2)
	{
		cur1 = cur1 == NULL ? pHead2 : cur1->next;
		cur2 = cur2 == NULL ? pHead1 : cur2->next;
	}
	return cur1;
}