#include<iostream>
#include<stack>
using namespace std;

class MyQueue {
public:
	/** Initialize your data structure here. */
	MyQueue() {
		while (!stack1.empty())
		{
			stack1.pop();
		}
		while (!stack2.empty())
		{
			stack2.pop();
		}
	}

	/** Push element x to the back of queue. */
	void push(int x) {
		if (stack1.empty() && stack2.empty()) {
			stack1.push(x);
		}
		else if (stack1.empty()) {
			if (flag) {
				stack2.push(x);
			}
			else
			{
				while (!stack2.empty())
				{
					stack1.push(stack2.top());
					stack2.pop();
				}
				stack1.push(x);
			}
		}
		else
		{
			if (flag) {
				stack1.push(x);
			}
			else
			{
				while (!stack1.empty())
				{
					stack2.push(stack1.top());
					stack1.pop();
				}
				stack2.push(x);
			}
		}
		flag = 1;
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		if (stack1.empty()) {
			if (flag) {
				while (!stack2.empty())
				{
					stack1.push(stack2.top());
					stack2.pop();
				}
				int result = stack1.top();
				stack1.pop();
				flag = 0;
				return result;
			}
			else
			{
				int result = stack2.top();
				stack2.pop();
				flag = 0;
				return result;
			}
		}
		else
		{
			if (flag) {
				while (!stack1.empty())
				{
					stack2.push(stack1.top());
					stack1.pop();
				}
				int result = stack2.top();
				stack2.pop();
				flag = 0;
				return result;
			}
			else
			{
				int result = stack1.top();
				stack1.pop();
				flag = 0;
				return result;
			}
		}
	}

	/** Get the front element. */
	int peek() {
		if (stack1.empty()) {
			if (flag) {
				while (!stack2.empty())
				{
					stack1.push(stack2.top());
					stack2.pop();
				}
				int result = stack1.top();
				flag = 0;
				return result;
			}
			else
			{
				int result = stack2.top();
				flag = 0;
				return result;
			}
		}
		else
		{
			if (flag) {
				while (!stack1.empty())
				{
					stack2.push(stack1.top());
					stack1.pop();
				}
				int result = stack2.top();
				flag = 0;
				return result;
			}
			else
			{
				int result = stack1.top();
				flag = 0;
				return result;
			}
		}
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		if (stack1.empty() && stack2.empty())
			return true;
		else
		{
			return false;
		}
	}

private:
	stack<int> stack1;
	stack<int> stack2;
	static int flag;
};
int MyQueue::flag = 1;
int main_TwoStackToQuene() {
	MyQueue mq;
	mq.push(1);
	mq.push(2);
	int p1 = mq.peek();
	int p2 = mq.pop();
	bool result = mq.empty();
	cout << p1 << " " << p2 << " " << result << endl;
	system("pause");
	return 0;
}