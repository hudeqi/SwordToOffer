#include<iostream>
#include<vector>
#include<string>
using namespace std;

void produceParent(vector<string>& result, string temp, int n, int m){
	if (n == 0 && m == 0) {
		result.push_back(temp);
		return;
	}
	if (n > 0) {
		produceParent(result, temp + "(", n - 1, m + 1);
	}
	if (m > 0) {
		produceParent(result, temp + ")", n, m - 1);
	}
}

vector<string> generateParenthesis(int n) {
	vector<string> result;
	produceParent(result, "", n, 0);
	return result;
}

void main_GenerateParentheses() {
	vector<string> result = generateParenthesis(3);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << endl;
	}
	system("pause");
}