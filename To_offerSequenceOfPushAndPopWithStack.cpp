#include<iostream>
#include<vector>
#include<stack>
using namespace std;

bool IsPopOrder(vector<int> pushV, vector<int> popV) {
	if (pushV.size() < 1)
		return true;
	stack<int> temp;
	temp.push(pushV[0]);
	for (int i = 1; i < pushV.size(); i++) {
		while (temp.size() != 0 && popV.size() != 0 && popV[0] == temp.top()) {
			popV.erase(popV.begin());
			temp.pop();
		}
		temp.push(pushV[i]);
	}
	while (temp.size() != 0 && popV.size() != 0 && popV[0] == temp.top()) {
		popV.erase(popV.begin());
		temp.pop();
	}
	if (popV.size() == 0)
		return true;
	else
	{
		return false;
	}
}

int main_SequenceOfPushAndPopWithStack() {
	vector<int> push;
	vector<int> pop;
	push.push_back(1);
	push.push_back(2);
	push.push_back(3);
	push.push_back(4);
	push.push_back(5);
	pop.push_back(4);
	pop.push_back(3);
	pop.push_back(5);
	pop.push_back(1);
	pop.push_back(2);
	cout << IsPopOrder(push, pop);
	system("pause");
	return 0;
}