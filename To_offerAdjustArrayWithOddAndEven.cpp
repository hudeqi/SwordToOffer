#include<iostream>
#include<vector>
using namespace std;

void reOrderArray(vector<int> &array) {
	if (array.size() < 2) {
		return;
	}
	vector<int> even;
	vector<int> odd;
	for (int i = 0; i < array.size(); i++) {
		if (array[i] % 2 == 0) {
			even.push_back(array[i]);
		}
		else
		{
			odd.push_back(array[i]);
		}
	}
	array.clear();
	for (int i = 0; i < odd.size(); i++)
		array.push_back(odd[i]);
	for (int i = 0; i < even.size(); i++)
		array.push_back(even[i]);
}

int main_AdjustArrayWithOddAndEven() {
	vector<int> test;
	test.push_back(2);
	test.push_back(4);
	test.push_back(6);
	test.push_back(1);
	test.push_back(3);
	test.push_back(5);
	test.push_back(7);
	reOrderArray(test);
	return 0;
}