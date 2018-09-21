#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;

string convert(string s, int numRows) {
	if (numRows == 1)
		return s;
	map<int, vector<int>> pos;
	for (int i = 0; i < numRows; i++) {
		vector<int> temp;
		pos[i] = temp;
	}
	int level = numRows * 2 - 2;
	int len = s.length();
	char* str = (char*)s.data();
	for (int i = 0; i < len; i++) {
		int mod = i % level;
		int row = mod;
		if (mod >= numRows)
			row = 2 * numRows - mod - 2;
		pos[row].push_back(i);
	}
	char* res = new char[s.length() + 1];
	int count = 0;
	for (int i = 0; i < numRows; i++) {
		for (int j = 0; j < pos[i].size(); j++) {
			res[count++] = str[pos[i][j]];
		}
	}
	res[count] = '\0';
	string result(res);
	delete[] res;
	return result;
}

void main_ZigZagConversion() {
	string s1 = "ltqtmpyyeqtujuiokcowswqyxntndxqqsgkhvihbaawjugagloddktdjizynyoesuozryityjrifxi";
	cout << convert(s1, 65) << endl;
	system("pause");
}