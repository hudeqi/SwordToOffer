#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool greatPos(int a, int b) {
	int r1 = atoi((to_string(a) + to_string(b)).c_str());
	int r2 = atoi((to_string(b) + to_string(a)).c_str());
	return r1 <= r2;
}

int partionWithNumbers(vector<int>& data, int left, int right) {
	int temp = data[left];
	while (left < right)
	{
		while (left < right && greatPos(temp, data[right]))
		{
			right--;
		}
		data[left] = data[right];
		while (left < right && greatPos(data[left], temp))
		{
			left++;
		}
		data[right] = data[left];
		data[left] = temp;
	}
	return left;
}

void quickSortWithnumbers(vector<int>& data, int left, int right) {
	if (left >= right) {
		return;
	}
	int part = partionWithNumbers(data, left, right);
	quickSortWithnumbers(data, left, part - 1);
	quickSortWithnumbers(data, part + 1, right);
}

string PrintMinNumber(vector<int> numbers) {
	if (numbers.size() == 0) {
		return "";
	}
	quickSortWithnumbers(numbers, 0, numbers.size() - 1);
	string result;
	for (int i = 0; i < numbers.size(); i++) {
		result = result + to_string(numbers[i]);
	}
	return result;
}

int main_MinNumberWithArrayPatutation() {
	vector<int> test;
	test.push_back(3);
	test.push_back(32);
	test.push_back(321);
	string result = PrintMinNumber(test);
	cout << result;
	system("pause");
	return 0;
}