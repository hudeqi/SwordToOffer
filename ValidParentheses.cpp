#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool isValid(string s) {
	if (s.length() == 0) {
		return true;
	}
	if (s.length() % 2 == 1) {
		return false;
	}
	stack<char> S;
	S.push(s[0]);
	for (int i = 1; i < s.size(); i++) {
		char temp = s[i];
		if (!S.empty()) {
			if (S.top() == '(') {
				if (temp == ')')
					S.pop();
				else if (temp == ']' || temp == '}')
					return false;
				else {
					S.push(temp);
				}
			}
			else if (S.top() == '[') {
				if (temp == ']')
					S.pop();
				else if (temp == ')' || temp == '}')
					return false;
				else {
					S.push(temp);
				}
			}
			else if (S.top() == '{') {
				if (temp == '}')
					S.pop();
				else if (temp == ')' || temp == ']')
					return false;
				else {
					S.push(temp);
				}
			}
			else {
				return false;
			}
		}
		else {
			S.push(temp);
		}
	}
	if (S.empty())
		return true;
	else
	{
		return false;
	}
}

void main_ValidParentheses() {
	string s = "([])";
	cout << isValid(s)<<endl;
	system("pause");
}