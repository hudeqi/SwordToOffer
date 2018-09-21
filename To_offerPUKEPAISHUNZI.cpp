#include<iostream>
#include<vector>
using namespace std;

int partion(vector<int>& data, int left, int right) {
	int temp = data[left];
	while (left < right)
	{
		while (left < right && temp <= data[right])
		{
			right--;
		}
		data[left] = data[right];
		while (left < right && data[left] <= temp)
		{
			left++;
		}
		data[right] = data[left];
		data[left] = temp;
	}
	return left;
}

void quickSort(vector<int>& data, int left, int right) {
	if (left >= right) {
		return;
	}
	int part = partion(data, left, right);
	quickSort(data, left, part - 1);
	quickSort(data, part + 1, right);
}

bool IsContinuous(vector<int> numbers) {
	if (numbers.size() <= 4)
		return false;
	quickSort(numbers, 0, numbers.size() - 1);
	int count = 0;
	int sum = 0;
	for (int i = 0; i < numbers.size(); i++) {
		if (numbers[i] == 0)
			count++;
		else
		{
			if (i < numbers.size() - 1) {
				sum += (numbers[i + 1] - numbers[i]);
			}
			if (numbers[i + 1] == numbers[i])
				return false;
		}
	}
	if (count == 4)
		return true;
	else {
		if (sum > numbers.size() - 1)
			return false;
		else {
			return true;
		}
	}
}