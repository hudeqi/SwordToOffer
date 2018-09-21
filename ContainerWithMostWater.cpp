#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxArea(vector<int>& height) {
	int result = 0;
	int i = 0;
	int j = height.size() - 1;
	while (i < j)
	{
		int area = (j - i) * min(height[i], height[j]);
		if (area > result)
			result = area;
		if (height[i] >= height[j]) {
			j--;
		}
		else
		{
			i++;
		}
	}
	return result;
}

void main_ContainerWithMostWater() {
	vector<int> a;
	a.push_back(1);
	a.push_back(8);
	a.push_back(6);
	a.push_back(2);
	a.push_back(5);
	a.push_back(4);
	a.push_back(8);
	a.push_back(3);
	a.push_back(7);
	cout << maxArea(a) << endl;
	system("pause");
}