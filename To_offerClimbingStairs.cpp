#include<iostream>
using namespace std;

int climbStairs(int n) {
	if (n < 1)
		return 0;
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;
	int prepre = 1, pre = 2;
	for (int i = 3; i < n + 1; i++) {
		int temp = pre;
		pre = prepre + pre;
		prepre = temp;
	}
	return pre;
}

int climbStairsII(int n) {
	if (n == 1 || n == 0)
		return 1;
	if (n == 2)
		return 2;
	int sum = 1, pre = 2;
	for (int i = 3; i < n + 1; i++) {
		int temp = pre;
		pre = sum + pre + 1;
		sum = sum + temp;
	}
	return pre;
}

int main_ClimbingStairs() {
	//cout << climbStairs(4);
	cout << climbStairsII(5);
	system("pause");
	return 0;
}