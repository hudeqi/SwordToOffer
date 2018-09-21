#include<iostream>
#include<vector>
using namespace std;

int GetNumberOfK(vector<int> data, int k) {
	if (data.size() < 1) {
		return 0;
	}
	int midpos = 0;
	int count = 1;
	int left = 0, right = data.size() - 1;
	int mid = left + (right - left) / 2;
	while (left <= right && data[mid] != k)
	{
		right = data[mid] > k ? mid - 1 : right;
		left = data[mid] < k ? mid + 1 : left;
		mid = left + (right - left) / 2;
	}
	if (mid >= data.size() || mid < 0) return 0;
	midpos = data[mid] == k ? mid : midpos;
	if (data[mid] != k) return 0;
	int i = midpos - 1, j = midpos + 1;
	while (i >= 0 && data[i] == k)
	{
		i--;
		count++;
	}
	while (j <= data.size() - 1 && data[j] == k)
	{
		j++;
		count++;
	}
	return count;
}

int main_NumberOfADigitInSortedArray() {
	vector<int> test;
	test.push_back(2);
	test.push_back(2);
	test.push_back(2);
	test.push_back(2);
	test.push_back(2);
	cout << GetNumberOfK(test, 2);
	system("pause");
	return 0;
}