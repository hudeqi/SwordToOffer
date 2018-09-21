#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> maxInWindows(const vector<int>& num, unsigned int size)
{
	if (num.size() == 0 || num.size() < size) {
		return vector<int>();
	}
	vector<int> result;
	vector<int> temp;
	if (num.size() == size) {
		temp.assign(num.begin(), num.end());
		sort(temp.begin(), temp.end());
		return vector<int>(1, temp.back());
	}
	if (size == 1) {
		for (int i = 0; i < num.size(); i++) {
			result.push_back(num[i]);
		}
		return result;
	}
	for (int i = 0; i < num.size(); i++) {
		if (i == 0) {
			temp.push_back(i);
			continue;
		}
		while (temp.size() != 0)
		{
			if (num[i] <= num[temp.back()]) {
				temp.push_back(i);
				if (i - temp[0] >= size) {
					temp.erase(temp.begin());
				}
				break;
			}
			else {
				temp.pop_back();
			}
		}
		if (temp.size() == 0)
			temp.push_back(i);
		if (i >= size - 1)
			result.push_back(num[temp[0]]);
	}
	return result;
}

int main_MaxmumOfSlidingWindow() {
	int a[] = { 16,14,12,10,8,6,4 };
	vector<int> test(a, a + 7);
	vector<int> result = maxInWindows(test, 5);
	system("pause");
	return 0;
}