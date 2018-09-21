#include<iostream>
#include"ListNode.h"
using namespace std;

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	if (l1 == NULL || l2 == NULL) {
		return l1 == NULL ? l2 : l1;
	}
	if (l1->val < l2->val) {
		l1->next = mergeTwoLists(l1->next, l2);
		return l1;
	}
	else
	{
		l2->next = mergeTwoLists(l1, l2->next);
		return l2;
	}
}

void main_MergeTwoSortedLists() {
	ListNode a(1);
	ListNode b(3);
	ListNode c(4);
	ListNode d(1);
	ListNode e(2);
	ListNode f(4);
	a.next = &b;
	b.next = &c;
	d.next = &e;
	e.next = &f;
	ListNode* result = mergeTwoLists(&a, &d);
	ListNode* cur = result;
	while (cur != NULL)
	{
		cout << cur->val << endl;
		cur = cur->next;
	}
	system("pause");
}