#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> oprateSeq(vector<int>& input, int n){
	vector<int> result;
	int m = n % 2 == 0 ? n / 2 : n / 2 + 1;
	for (int i = 0; i < m; i++) {
		result.push_back(input[n - 1 - i * 2]);
	}
	if ((n - 1 - (m - 1) * 2) == 0) {
		for (int i = 0; i < m - 1; i++) {
			result.push_back(input[1 + i * 2]);
		}
	}
	else
	{
		for (int i = 0; i < m; i++) {
			result.push_back(input[i * 2]);
		}
	}
	return result;
}

int main_OprateSeq() {
	int n;
	vector<int> input;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		input.push_back(temp);
	}
	vector<int> result = oprateSeq(input, n);
	for (int i = 0; i < result.size() - 1; i++) {
		cout << result[i] << " ";
	}
	cout << result[result.size() - 1] << endl;
	system("pause");
	return 0;
}