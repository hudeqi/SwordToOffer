#include<iostream>
#include<string>
#include<vector>
using namespace std;

int lengthOfLongestSubstring(string s) {
	vector<char> temp;
	char* str = (char*)s.data();
	int maxLength = 0;
	for (int i = 0; i < s.length(); i++) {
		char c = str[i];
		vector<char>::iterator iter = find(temp.begin(), temp.end(), c);
		if (iter == temp.end()) {
			temp.push_back(c);
		}
		else {
			int len = temp.size();
			if (len > maxLength)
				maxLength = len;
			while (iter != temp.begin()) {
				iter = temp.erase(iter);
				--iter;
			}
			iter = temp.erase(temp.begin());
			temp.push_back(c);
		}
	}
	if (maxLength > temp.size())
		return maxLength;
	else
	{
		return temp.size();
	}
}

void main_lengthOfLongestSubstring() {
	string s1 = "abcabcbb";
	string s2 = "bbbbb";
	string s3 = "pwwkew";
	string s4 = " ";
	cout << lengthOfLongestSubstring(s4);
	system("pause");
}