#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<string> letterCombinations(string digits) {
	if (digits.length() == 0) {
		return vector<string>();
	}
	vector<string> result = {""};
	vector<string> dic = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
	for (int i = 0; i < digits.length(); i++) {
		int cur = digits[i] - '0';
		string current = dic[cur - 2];
		vector<string> temp;
		for (int j = 0; j < current.length(); j++) {
			for (int k = 0; k < result.size(); k++) {
				temp.push_back(result[k] + current[j]);
			}
		}
		result.swap(temp);
	}
	return result;
}

void main_LetterCombination() {
	vector<string> temp = letterCombinations("23");
	for (int i = 0; i < temp.size(); i++) {
		cout << temp[i] << " " << endl;
	}
	system("pause");
}