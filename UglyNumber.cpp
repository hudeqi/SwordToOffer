#include<iostream>
using namespace std;

bool isUgly(int num) {
	if (num == 1)
		return true;
	if (num == 0 || num == -1)
		return false;
	while (num % 2 == 0)
	{
		num /= 2;
	}
	if (num == 1)
		return true;
	while (num % 3 == 0)
	{
		num /= 3;
	}
	if (num == 1)
		return true;
	while (num % 5 == 0)
	{
		num /= 5;
	}
	if (num == 1)
		return true;
	return false;
}

int main_UglyNnumber() {
	cout << isUgly(6);
	system("pause");
	return 0;
}