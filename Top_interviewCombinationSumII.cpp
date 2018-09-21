#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

void combination(int cur, vector<vector<int>>& result, vector<int>& candidates, set<vector<int>>& s, 
	vector<int>& temp, int sum, int target) {
	if (cur >= candidates.size() || sum > target)
		return;
	temp.push_back(candidates[cur]);
	sum += candidates[cur];
	if (sum == target && s.find(temp) == s.end()) {
		s.insert(temp);
		result.push_back(temp);
	}
	combination(cur + 1, result, candidates, s, temp, sum, target);
	sum -= temp.back();
	temp.pop_back();
	combination(cur + 1, result, candidates, s, temp, sum, target);
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
	vector<vector<int>> result;
	set<vector<int>> s;
	vector<int> temp;
	int sum = 0;
	sort(candidates.begin(), candidates.end());
	combination(0, result, candidates, s, temp, sum, target);
	return result;
}

int main() {
	vector<int> test;
	test.push_back(2);
	test.push_back(5);
	test.push_back(3);
	test.push_back(1);
	test.push_back(2);
	vector<vector<int>> result = combinationSum2(test, 5);
	system("pause");
	return 0;
}