#include<iostream>
#include"ListNode.h"
using namespace std;

ListNode* deleteDuplication(ListNode* pHead)
{
	if (!pHead)
		return NULL;
	ListNode* pre = NULL;
	ListNode* cur = pHead;
	while (cur)
	{
		if (cur->next && cur->val == cur->next->val) {
			int value = cur->val;
			while (cur->next && cur->next->val == value)
			{
				cur = cur->next;
			}
			if (!pre)
				pHead = cur->next;
			else {
				pre->next = cur->next;
			}
		}
		else {
			pre = cur;
		}
		cur = cur->next;
	}
	return pHead;
}

int main_RemoveDuplicateInSortedListII() {
	ListNode l1(2);
	ListNode l2(2);
	ListNode l3(3);
	ListNode l4(3);
	ListNode l5(4);
	ListNode l6(4);
	//ListNode l7(5);
	l1.next = &l2;
	l2.next = &l3;
	l3.next = &l4;
	l4.next = &l5;
	l5.next = &l6;
	//l6.next = &l7;
	ListNode* result = deleteDuplication(&l1);
	system("pause");
	return 0;
}