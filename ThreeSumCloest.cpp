#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
	if (nums.size() < 3) {
		int sum = 0;
		for (int i = 0; i < nums.size(); i++) {
			sum += nums[i];
		}
		return sum;
	}
	int minNeed = 9999999;
	int negative = 1;
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size(); i++) {
		int front = i + 1;
		int behind = nums.size() - 1;
		while (front < behind)
		{
			int need = target - nums[i] - nums[front] - nums[behind];
			if (abs(need) < minNeed) {
				minNeed = abs(need);
				negative = need > 0 ? 1 : -1;
			}
			if (need == 0) {
				return target;
			}
			else if (need > 0)
			{
				while (front + 1 < nums.size() && nums[front] == nums[front + 1])
				{
					front++;
				}
				front++;
			}
			else
			{
				while (behind - 1 > 0 && nums[behind] == nums[behind - 1])
				{
					behind--;
				}
				behind--;
			}
		}
	}
	return target - negative * minNeed;
}

void main_ThreeSumCloest() {
	vector<int> test(4, 0);
	test[0] = -1;
	test[1] = 2;
	test[2] = 1;
	test[3] = 4;
	cout << threeSumClosest(test, 1)<<endl;
	system("pause");
}