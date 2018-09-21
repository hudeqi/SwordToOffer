#include<iostream>
using namespace std;

bool hasAlternatingBits(int n) {
	if (n <= 0)
		return false;
	if (n == 1)
		return true;
	int pre = n % 2;
	n = n / 2;
	while (n != 0)
	{
		int cur = n % 2;
		if (cur != pre)
			pre = cur;
		else
		{
			return false;
		}
		n = n / 2;
	}
	return true;
}

int main_BinaryNumberWithAlternatingBits() {
	cout << hasAlternatingBits(10) << endl;
	system("pause");
	return 0;
}