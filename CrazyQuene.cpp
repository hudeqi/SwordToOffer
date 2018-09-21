#include<iostream>
#include<vector>
#include<algorithm>
#include<deque>
using namespace std;

int maxCrazy(vector<int>& input, int n){
	int result = 0;
	deque<int> q;
	sort(input.begin(), input.end());
	int flag = n % 2;
	int start = flag == 0 ? n / 2 : n / 2 + 1;
	for (int i = 0; i < n / 2; i++) {
		if (i % 2 == 0) {
			q.push_front(input[i]);
			q.push_back(input[n - 1 - i]);
		}
		else
		{
			q.push_front(input[n - 1 - i]);
			q.push_back(input[i]);
		}
	}
	if (flag == 0) {
		for (int i = 0; i < n - 1; i++) {
			result += abs(q[i + 1] - q[i]);
		}
	}
	if (flag == 1) {
		for (int i = 0; i < n - 2; i++) {
			result += abs(q[i + 1] - q[i]);
		}
		int left = result + abs(q[0] - input[n / 2]);
		int right = result + abs(q[q.size() - 1] - input[n / 2]);
		result = left > right ? left : right;
	}
	return result;
}

int main_CrazyQuene() {
	int n;
	vector<int> input;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		input.push_back(temp);
	}
	int result = maxCrazy(input, n);
	cout << result;
	system("pause");
	return 0;
}