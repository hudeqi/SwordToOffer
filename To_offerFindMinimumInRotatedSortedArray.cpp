#include<iostream>
#include<vector>
using namespace std;

int findMin(vector<int>& nums) {
	if (nums.size() == 0)
		return 0;
	for (int i = 1; i < nums.size() - 1; i++) {
		if (nums[i] < nums[i + 1] && nums[i] < nums[i - 1]) {
			return nums[i];
		}
		else
		{
			continue;
		}
	}
	if (nums[0] < nums[nums.size() - 1])
		return nums[0];
	else
	{
		return nums[nums.size() - 1];
	}
}

int main_FindMinimumInRotatedSortedArray() {
	vector<int> test;
	test.push_back(2);
	test.push_back(3);
	test.push_back(4);
	test.push_back(5);
	test.push_back(1);
	cout << findMin(test);
	system("pause");
	return 0;
}