#include<iostream>
#include<vector>
#include<map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
	vector<int> result;
	map<int, int> hashmap;
	for (int i = 0; i < nums.size(); i++) {
		if (hashmap.find(nums[i]) != hashmap.end()) {
			result.push_back(hashmap[nums[i]]);
			result.push_back(i);
			break;
		}
		int temp = target - nums[i];
		//hashmap[temp] = i;
		hashmap.insert(map<int, int>::value_type(temp, i));
	}
	return result;
}

void main_twoSum() {
	vector<int> array;
	array.push_back(3);
	array.push_back(2);
	array.push_back(4);
	vector<int> res = twoSum(array, 6);
	cout << res[0] << " " << res[1] << endl;
	system("pause");
}