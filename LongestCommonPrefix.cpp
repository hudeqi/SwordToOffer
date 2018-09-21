#include<iostream>
#include<string>
#include<vector>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
	if (strs.size() == 0)
		return "";
	if (strs.size() == 1)
		return strs[0];
	int count = 0;
	char* cur = (char*)strs[0].data();
	string newstr = "";
	for (int i = 1; i < strs.size(); i++) {
		char* next = (char*)strs[i].data();
		for (int j = 0; j < strs[i].length(); j++) {
			if (cur[j] == next[j]) {
				count++;
			}
			if (cur[j] != next[j] || cur[j] == '\0' || next[j] == '\0') {
				break;
			}
		}
		if (count == 0) {
			return "";
		}
		newstr = strs[i].substr(0, count);
		cur = (char*)newstr.data();
		count = 0;
	}
	string result(cur);
	return result;
}

void main_LongestCommonPrefix() {
	vector<string> test;
	test.push_back("dof");
	test.push_back("dof");
	test.push_back("doof");
	cout << longestCommonPrefix(test)<<endl;
	system("pause");
}