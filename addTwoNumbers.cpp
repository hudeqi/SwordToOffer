#include<iostream>
#include"ListNode.h"
using namespace std;

 ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	 ListNode* res = new ListNode(0);
	 ListNode* cur = res;
	 ListNode* cur1 = l1;
	 ListNode* cur2 = l2;
	 int pre = 0;
	 while (cur1 != NULL || cur2 != NULL) {
		 int temp1 = cur1 == NULL ? 0 : cur1->val;
		 int temp2 = cur2 == NULL ? 0 : cur2->val;
		 int temp = temp1 + temp2 + pre;
		 pre = temp / 10;
		 int lae = temp - pre * 10;
		 cur->next = new ListNode(lae);
		 cur = cur->next;
		 if (cur1 != NULL)
			 cur1 = cur1->next;
		 if (cur2 != NULL)
			 cur2 = cur2->next;
	 }
	 if (pre > 0)
		 cur->next = new ListNode(pre);
	 return res->next;
 }

 void main_addtwoNumbers() {
	 ListNode a(2);
	 ListNode b(4);
	 ListNode d(5);
	 ListNode e(6);
	 ListNode f(4);
	 a.next = &b;
	 d.next = &e;
	 e.next = &f;
	 ListNode* res = addTwoNumbers(&a,&d);
	 ListNode* cur = res;
	 while (cur != NULL)
	 {
		 cout << cur->val << endl;
		 cur = cur->next;
	 }
	 system("pause");
 }