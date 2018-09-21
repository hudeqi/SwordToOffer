#include<iostream>
#include<vector>
#include<map>
using namespace std;

int MoreThanHalfNum_Solution(vector<int> numbers) {
	int num = numbers.size();
	if (num == 0)
		return 0;
	if (num == 1)
		return numbers[0];
	map<int, int> count;
	for (int i = 0; i < numbers.size(); i++) {
		if (count.find(numbers[i]) == count.end()) {
			count.insert(make_pair(numbers[i], 1));
		}
		else
		{
			count[numbers[i]]++;
			if (count[numbers[i]] > num / 2) {
				return numbers[i];
			}
		}
	}
	return 0;
}