#include<iostream>
#include<stack>
#include"ListNode.h"
using namespace std;

ListNode* addTwoNumbersII(ListNode* l1, ListNode* l2) {
	stack<int> s1, s2, res;
	ListNode* head = l1;
	ListNode* result = head;
	while (l1)
	{
		s1.push(l1->val);
		if (l1->next == NULL) {
			l1->next = l2;
			break;
		}
		l1 = l1->next;
	}
	while (l2)
	{
		s2.push(l2->val);
		l2 = l2->next;
	}
	int h = 0;
	while (s1.size() != 0 && s2.size() != 0)
	{
		int s = s1.top() + s2.top() + h;
		int mod = s % 10;
		res.push(mod);
		h = s / 10;
		s1.pop();
		s2.pop();
	}
	while (s1.size() != 0)
	{
		int s = s1.top() + h;
		int mod = s % 10;
		res.push(mod);
		h = s / 10;
		s1.pop();
	}
	while (s2.size() != 0)
	{
		int s = s2.top() + h;
		int mod = s % 10;
		res.push(mod);
		h = s / 10;
		s2.pop();
	}
	if (h != 0)
		res.push(1);
	while (res.size() != 0)
	{
		head->val = res.top();
		res.pop();
		if (res.size() == 0) {
			head->next = NULL;
			break;
		}
		head = head->next;
	}
	return result;
}

int main_AddTwoNumbersII() {
	ListNode a1(7);
	ListNode a2(2);
	ListNode a3(4);
	ListNode a4(3);
	ListNode b1(5);
	ListNode b2(6);
	ListNode b3(4);
	a1.next = &a2;
	a2.next = &a3;
	a3.next = &a4;
	b1.next = &b2;
	b2.next = &b3;
	ListNode* result = addTwoNumbersII(&a1, &b1);
	while (result)
	{
		cout << result->val << endl;
		result = result->next;
	}
	system("pause");
	return 0;
}