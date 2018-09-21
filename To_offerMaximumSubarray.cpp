#include<iostream>
#include<vector>
using namespace std;

int FindGreatestSumOfSubArray(vector<int> array) {
	if (array.size() == 0)
		return -1;
	if (array.size() == 1)
		return array[0];
	int result = array[0];
	int sum = array[0];
	for (int i = 1; i < array.size(); i++) {
		if (sum <= 0) {
			sum = 0;
		}
		sum += array[i];
		result = result >= sum ? result : sum;
	}
	return result;
}

int main_MaximumSubarray() {
	vector<int> test;
	test.push_back(-1);
	test.push_back(-2);
	test.push_back(-3);
	cout << FindGreatestSumOfSubArray(test);
	system("pause");
	return 0;
}