#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(vector<int>& a, vector<int>& b) {
	return a[0] < b[0];
}

vector<vector<int> > FindContinuousSequence(int sum) {
	vector<vector<int>> result;
	for (int k = 2; k < sqrt(2 * sum); k++) {
		if ((2 * sum - k * (k - 1)) % (2 * k) == 0) {
			vector<int> temp;
			int x = (2 * sum - k * (k - 1)) / (2 * k);
			for (int i = 0; i < k; i++) {
				temp.push_back(x + i);
			}
			result.push_back(temp);
		}
	}
	sort(result.begin(), result.end(), compare);
	return result;
}