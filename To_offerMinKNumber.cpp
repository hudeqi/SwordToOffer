#include<iostream>
#include<vector>
#include<set>
using namespace std;

vector<int> GetLeastNumbers(vector<int> input, int k) {
	if (k > input.size())
		return vector<int>();
	multiset<int> temp;
	vector<int> result;
	for (int i = 0; i < input.size(); i++) {
		temp.insert(input[i]);
	}
	int count = 0;
	auto iter = temp.begin();
	while (count < k)
	{
		result.push_back(*iter);
		iter++;
		count++;
	}
	return result;
}