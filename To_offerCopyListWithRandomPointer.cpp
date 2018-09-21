#include<iostream>
using namespace std;

struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :
		label(x), next(NULL), random(NULL) {
	}
};

RandomListNode* Clone(RandomListNode* pHead)
{
	if (!pHead)
		return NULL;
	/*复制过程*/
	RandomListNode* result = pHead;
	while (pHead)
	{
		RandomListNode* next = pHead->next;
		RandomListNode* copy = new RandomListNode(pHead->label);
		pHead->next = copy;
		copy->next = next;
		pHead = next;
	}
	/*复制的random构造*/
	RandomListNode* again = result;
	while (again)
	{
		if (again->random) {
			again->next->random = again->random->next;
		}
		again = again->next->next;
	}
	/*拆分*/
	RandomListNode* pCurrent = result;
	RandomListNode *pClonedHead = result->next;
	RandomListNode *pCurrentCloned = NULL;
	while (pCurrent->next)
	{
		pCurrentCloned = pCurrent->next;
		pCurrent->next = pCurrent->next->next;
		pCurrent = pCurrentCloned;
	}
	return pClonedHead;
}

int main_CopyListWithRandomPointer () {
	RandomListNode r1(1);
	RandomListNode r2(2);
	RandomListNode r3(3);
	RandomListNode r4(4);
	r1.next = &r2;
	r2.next = &r3;
	r3.next = &r4;
	r2.random = &r1;
	r3.random = &r4;
	RandomListNode* result = Clone(&r1);
	system("pause");
	return 0;
}