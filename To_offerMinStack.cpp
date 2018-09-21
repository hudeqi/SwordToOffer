#include<iostream>
#include<stack>
#include<set>
using namespace std;

class MinStack {
public:
	MinStack() {
		while (!temp.empty()) {
			temp.pop();
		}
		tset.clear();
	}

	void push(int x) {
		temp.push(x);
		tset.insert(x);
	}

	void pop() {
		tset.erase(tset.lower_bound(temp.top()));
		temp.pop();
	}

	int top() {
		if (temp.empty())
			return -1;
		return temp.top();
	}

	int getMin() {
		return *tset.begin();
	}

private:
	stack<int> temp;
	multiset<int> tset;
};