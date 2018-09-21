#include<iostream>
#include<vector>
#include<set>
using namespace std;

vector<int> FindNumbersWithSum(vector<int> array, int sum) {
	if (array.size() <= 1)
		return vector<int>();
	if (array[0] >= sum && sum != 0)
		return vector<int>();
	vector<int> result;
	int left = sum / 2;
	int right = sum - left;
	multiset<int> ms;
	int ji = 9999999;
	for (int i = 0; i < array.size(); i++)
		ms.insert(array[i]);
	for (int i = 0; array[i] <= left && i < array.size(); i++) {
		if (ms.find(array[i]) != ms.end() && ms.find(sum - array[i]) != ms.end()) {
			if (array[i] == sum - array[i] && array[i] != array[i - 1] && (array[i] != array[i + 1] && i + 1 < array.size())) {
				continue;
			}
			if (ji > array[i] * (sum - array[i])) {
				ji = array[i] * (sum - array[i]);
				result.clear();
				result.push_back(array[i]);
				result.push_back(sum - array[i]);
			}
			ms.erase(ms.lower_bound(array[i]));
			ms.erase(ms.lower_bound(sum - array[i]));
		}
	}
	return result;
}

int main_TwoSumIISortedArray() {
	vector<int> test;
	test.push_back(2);
	test.push_back(3);
	test.push_back(4);
	vector<int> result = FindNumbersWithSum(test, 6);
	system("pause");
	return 0;
}