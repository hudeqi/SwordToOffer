#include<iostream>
#include<vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
	if (nums.size() <= 1) {
		return nums.size();
	}
	int maxValue = nums[0];
	int count = 0;
	for (int i = 1; i < nums.size(); i++) {
		if (maxValue < nums[i]) {
			maxValue = nums[i];
			nums[i - count] = nums[i];
		}
		else
		{
			count++;
		}
	}
	return nums.size() - count;
}

int main_RemoveDdeplicatesFromSortedArray() {
	vector<int> deplicate;
	deplicate.push_back(1);
	deplicate.push_back(1);
	deplicate.push_back(2);
	int num = removeDuplicates(deplicate);
	cout << num << endl;
	for (int i = 0; i < num; i++) {
		cout << deplicate[i] << " ";
	}
	system("pause");
	return 0;
}