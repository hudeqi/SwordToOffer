#include<iostream>
using namespace std;

/*负数用原码表示*/
int hammingWeight(uint32_t n) {
	int count = 0;
	if (n < 0) {
		count += 1;
		n = n * (-1);
	}
	while (n != 0)
	{
		int mod = n % 2;
		if (mod == 1) {
			count++;
		}
		n /= 2;
	}
	return count;
}

/*负数用补码表示的情况*/
int  NumberOf1(int n) {
	int count = 0;
	if (n < 0) {
		count += 1;
	}
	if (n >= 0) {
		while (n != 0)
		{
			int mod = n % 2;
			if (mod == 1) {
				count++;
			}
			n /= 2;
		}
		return count;
	}
	else
	{
		n = n * (-1);
		int p = 1;
		int temp = 0;
		int c = 0;
		while (n != 0)
		{
			int mod = n % 2;
			if (mod == 0) {
				temp = temp + p;
			}
			p *= 2;
			n /= 2;
			c++;
		}
		for (int i = 0; i < 31 - c; i++) {
			temp += p;
			p *= 2;
		}
		temp += 1;
		while (temp != 0)
		{
			int mod = temp % 2;
			if (mod == 1) {
				count++;
			}
			temp /= 2;
		}
		return count;
	}
}

int main_NumberOf1bits() {
	//cout << hammingWeight(128);
	cout << NumberOf1(-2147483648);
	system("pause");
	return 0;
}