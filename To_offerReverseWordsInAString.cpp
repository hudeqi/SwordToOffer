#include<iostream>
#include<string>
#include<stack>
using namespace std;
/*没有多空格的复杂情况*/
string ReverseSentence(string str) {
	if (str == "")
		return "";
	string result = "";
	int count = 0;
	for (int i = str.size() - 1; i >= 0; i--) {
		if (str[i] != ' ')
			count++;
		else {
			result += str.substr(i + 1, count) + " ";
			count = 0;
		}
		if (i == 0 && count != 0)
			result += str.substr(0, count);
	}
	return result;
}

void reverseWords(string &s) {
	if (s == "")
		return;
	stack<string> st;
	string temp;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != ' ') {
			temp += s[i];
		}
		else
		{
			if (temp.size() > 0)
				st.push(" " + temp);
			temp = "";
		}
		if (i == s.size() - 1 && temp.size() > 0) {
			st.push(" " + temp);
		}
	}
	s = "";
	while (!st.empty())
	{
		s += st.top();
		st.pop();
	}
	if (s[0] == ' ')
		s = s.substr(1, s.size() - 1);
}

int main_ReverseWordsInAString() {
	string s = " cvf  vvg bb  ";
	reverseWords(s);
	cout << s;
	system("pause");
	return 0;
}