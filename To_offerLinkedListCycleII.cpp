#include<iostream>
#include"ListNode.h"
#include<set>
using namespace std;

ListNode* EntryNodeOfLoop(ListNode* pHead)
{
	if (!pHead)
		return NULL;
	set<ListNode*> s;
	while (pHead)
	{
		if (s.find(pHead) != s.end())
			return pHead;
		s.insert(pHead);
		pHead = pHead->next;
	}
	return NULL;
}