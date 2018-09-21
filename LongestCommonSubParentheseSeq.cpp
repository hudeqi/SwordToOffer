#include <string>
#include <vector>
#include<stack>
#include <iostream>
using namespace std;

int lcs(string str1, string str2) {
	int len1 = str1.size();
	int len2 = str2.size();
	vector<vector<int>> c(len1 + 1, vector<int>(len2 + 1, 0));
	for (int i = 0; i <= len1; i++) {
		for (int j = 0; j <= len2; j++) {
			if (i == 0 || j == 0) {
				c[i][j] = 0;
			}
			else if (str1[i - 1] == str2[j - 1]) {
				c[i][j] = c[i - 1][j - 1] + 1;
			}
			else if (c[i - 1][j] >= c[i][j - 1]) {
				c[i][j] = c[i - 1][j];
			}
			else {
				c[i][j] = c[i][j - 1];
			}
		}
	}
	return c[len1][len2];
}

extern bool isValid(string s);

int main_LongestCommonSubParentheseSeq() {
	char input[50];
	cin >> input;
	string in(input);
	int count = 0;
	vector<string> res;
	for (int i = 0; i < in.size(); i++) {
		string single = in.substr(i, 1);
		string left = in.substr(0, i);
		string right = "";
		if (i < in.size() - 1)
			right = in.substr(i + 1, in.size() - i - 1);
		string l_and_r = left + right;
		for (int j = 0; j <= l_and_r.size(); j++) {
			string l = l_and_r.substr(0, j);
			string r = "";
			if (j < l_and_r.size()) {
				r = l_and_r.substr(j, l_and_r.size() - j);
			}
			string test = l + single + r;
			vector<string>::iterator iter = find(res.begin(), res.end(), test);
			if (isValid(test) && (test.compare(in) != 0) && iter == res.end()){
				count++;
				res.push_back(test);
			}
		}
	}
	cout << count;
	system("pause");
	return 0;
}