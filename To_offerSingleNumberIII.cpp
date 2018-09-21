#include<iostream>
#include<vector>
#include<set>
using namespace std;

void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
	set<int> temp;
	for (int i = 0; i < data.size(); i++) {
		if (temp.find(data[i]) == temp.end()) {
			temp.insert(data[i]);
		}
		else
		{
			temp.erase(data[i]);
		}
	}
	*num1 = (*temp.begin());
	*num2 = (*(++temp.begin()));
}

int main_SingleNumberIII() {
	vector<int> input;
	input.push_back(2);
	input.push_back(4);
	input.push_back(3);
	input.push_back(6);
	input.push_back(3);
	input.push_back(2);
	input.push_back(5);
	input.push_back(5);
	int a;
	int b;
	FindNumsAppearOnce(input, &a, &b);
	system("pause");
	return 0;
}