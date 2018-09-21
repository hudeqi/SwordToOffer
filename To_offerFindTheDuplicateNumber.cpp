#include<iostream>
#include<vector>
#include<set>
using namespace std;

int findDuplicate(vector<int>& nums) {
	if (nums.size() > 1)
	{
		int slow = nums[0];
		int fast = nums[nums[0]];
		while (slow != fast)
		{
			slow = nums[slow];
			fast = nums[nums[fast]];
		}

		fast = 0;
		while (fast != slow)
		{
			fast = nums[fast];
			slow = nums[slow];
		}
		return slow;
	}
	return -1;
}

bool duplicate(int numbers[], int length, int* duplication) {
	if (length < 1)
		return false;
	set<int> temp;
	for (int i = 0; i < length; i++) {
		if (temp.find(numbers[i]) != temp.end()) {
			duplication[0] = numbers[i];
			return true;
		}
		else {
			temp.insert(numbers[i]);
		}
	}
	return false;
}

int main_FindTheDuplicateNumber() {
	int numbers[] = {1, 0, 0, 3, 1, 5, 6, 5};
	int* dup = new int[100];
	cout << duplicate(numbers, 8, dup);
	cout << dup[0];

	//vector<int> input;
	//input.push_back(2);
	//input.push_back(1);
	//input.push_back(6);
	//input.push_back(3);
	//input.push_back(2);
	//input.push_back(7);
	//input.push_back(4);
	//input.push_back(5);
	//cout << findDuplicate(input);
	system("pause");
	return 0;
}