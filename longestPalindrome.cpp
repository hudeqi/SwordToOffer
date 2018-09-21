#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string longestPalindrome(string s) {
	if (s == "") {
		return "";
	}
	char* str = (char*)s.data();
	char* newstr = new char[s.length() * 2 + 2];
	for (int i = 0; i < s.length() * 2 + 1; i++) {
		if (i % 2 == 0) {
			newstr[i] = '#';
		}
		else
		{
			newstr[i] = str[(i - 1) / 2];
		}
	}
	newstr[s.length() * 2 + 1] = '\0';
	int id = 0, mx = 0;
	int* p = new int[s.length() * 2 + 1];
	int maxLength = 0, index = 0;
	for (int i = 0; i < s.length() * 2 + 1; i++) {
		p[i] = 1;
	}
	for (int i = 1; i < s.length() * 2 + 1; i++) {
		if (mx >= i) {
			p[i] = min(p[2 * id - i], mx - i);
		}
		else
		{
			p[i] = 1;
		}
		while (newstr[i - p[i]] == newstr[i + p[i]])
		{
			p[i]++;
		}
		if (p[i] + i - 1 > mx) {
			mx = p[i] + i - 1;
			id = i;
		}
		if (p[i] > maxLength) {
			maxLength = p[i];
			index = i;
		}
	}
	delete[] p;
	delete[] newstr;
	int start = (index - maxLength + 1) / 2;
	string result = s.substr(start < 0 ? 0 : start, maxLength - 1);
	return result;
}

void main_longestPalindrome() {
	string test1 = "babad";
	string test2 = "cbbd";
	string test3 = "abcba";
	string test4 = "a";
	cout << longestPalindrome(test2)<<endl;
	system("pause");
}