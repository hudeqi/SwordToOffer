#include<iostream>
#include<vector>
#include<set>
using namespace std;

/*最小的k个数*/
vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
	if (input.size() == 0 || k < 1 || k > input.size())
		return vector<int>();
	vector<int> result;
	multiset<int> temp;
	for (int i = 0; i < input.size(); i++) {
		temp.insert(input[i]);
	}
	int count = 0;
	auto iter = temp.begin();
	while (count != k)
	{
		result.push_back(*iter);
		iter++;
		count++;
	}
	return result;
}

/*找第K大个数，不忽略重复*/
int findKthLargest(vector<int>& nums, int k) {
	if (nums.size() == 0 || k < 1 || k > nums.size())
		return -1;
	int result;
	multiset<int> temp;
	for (int i = 0; i < nums.size(); i++) {
		temp.insert(nums[i]);
	}
	int count = 0;
	auto iter = temp.end();
	iter--;
	while (true)
	{
		if (count == k - 1) {
			result = *iter;
			break;
		}
		iter--;
		count++;
	}
	return result;
}

/*第三大且唯一出现的数*/
int thirdMax(vector<int>& nums) {
	if (nums.size() == 0)
		return -1;
	int result;
	set<int> temp;
	for (int i = 0; i < nums.size(); i++) {
		temp.insert(nums[i]);
	}
	int count = 0;
	auto iter = temp.end();
	iter--;
	int tempMax = *iter;
	if (temp.size() < 3) {
		return tempMax;
	}
	while (true)
	{
		if (count == 2) {
			return *iter;
		}
		iter--;
		count++;
	}
	return tempMax;
}

int main_MinKNumbers() {
	vector<int> input;
	input.push_back(4);
	input.push_back(5);
	input.push_back(1);
	input.push_back(6);
	input.push_back(2);
	input.push_back(7);
	input.push_back(3);
	input.push_back(8);
	/*vector<int> result = GetLeastNumbers_Solution(input, 4);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << endl;
	}*/
	/*int result = findKthLargest(input, 4);
	cout << result;*/
	int result = thirdMax(input);
	cout << result;
	system("pause");
	return 0;
}