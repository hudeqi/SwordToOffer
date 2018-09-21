#include <iostream>
#include <vector>
#include <stack>
#include"ListNode.h"
using namespace std;

vector<int> printListFromTailToHead(ListNode* head) {
	vector<int> result;
	stack<int> temp;
	if (head->next == NULL)
		return result;
	ListNode* cur = head->next;
	temp.push(cur->val);
	//result.push_back(cur->val);
	while (cur->next != NULL) {
		cur = cur->next;
		temp.push(cur->val);
		//result.insert(result.begin(), cur->val);
	}
	while (!temp.empty())
	{
		//result.push_back(temp.top);
		temp.pop();
	}
	return result;
}

void main_plft() {
	//ListNode a(1);
	//ListNode b(2);
	//ListNode c(3);
	//ListNode d(4);
	//ListNode *head = new ListNode;
	//head->next = &a;
	//a.next = &b;
	//b.next = &c;
	//c.next = &d;
	//d.next = NULL;
	//vector<int> res = printListFromTailToHead(head);
	//for (int i = 0; i < res.size(); i++) {
	//	cout << res[i] << endl;
	//}
}
