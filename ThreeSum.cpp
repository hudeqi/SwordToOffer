#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
	vector<vector<int>> result;
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size(); i++) {
		int front = i + 1;
		int behind = nums.size() - 1;
		while (front < behind)
		{
			int sum = nums[front] + nums[behind];
			if (sum == (-1 * nums[i])) {
				vector<int> triplet(3, 0);
				triplet[0] = nums[i];
				triplet[1] = nums[front];
				triplet[2] = nums[behind];
				result.push_back(triplet);
				while (triplet[1] == nums[front])
				{
					front++;
				}
				while (triplet[2] == nums[behind])
				{
					behind--;
				}
			}
			else if(sum > (-1 * nums[i])){
				behind--;
			}
			else
			{
				front++;
			}
		}
		while (i + 1 < nums.size() && nums[i] == nums[i + 1])
		{
			i++;
		}
	}
	return result;
}

void main_ThreeSum() {
	vector<int> test;
	test.push_back(-1);
	test.push_back(0);
	test.push_back(1);
	test.push_back(0);
	vector<vector<int>> res = threeSum(test);
	for (int i = 0; i < res.size(); i++) {
		cout << endl;
		for (int j = 0; j < res[i].size(); j++)
			cout << res[i][j] << " ";
	}
	system("pause");
}