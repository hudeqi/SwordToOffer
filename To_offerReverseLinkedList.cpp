#include<iostream>
#include"ListNode.h"
using namespace std;

ListNode* reverseList(ListNode* head) {
	if (head == NULL)
		return NULL;
	if (head->next == NULL)
		return head;
	ListNode* h = reverseList(head->next);
	head->next->next = head;	//5☞4，4☞null，回溯，4☞3，3☞null，直到2☞1，1☞null，最后返回
	head->next = NULL;
	return h;
}

int main_ReverseLinkedList() {
	ListNode l1(1);
	ListNode l2(2);
	ListNode l3(3);
	l1.next = &l2;
	l2.next = &l3;
	ListNode *result = reverseList(&l1);
	while (result != NULL)
	{
		cout << result->val << endl;
		result = result->next;
	}
	system("pause");
	return 0;
}