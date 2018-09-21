#include<iostream>
#include<string>
using namespace std;

int findNthDigit(int n) {
	long long count = 9;
	int w = 1;
	long long base = 10;
	while (n > count)
	{
		count += (9 * base * (w + 1));
		w++;
		base *= 10;
	}
	long long cha = count - n;
	long long num = cha / w;
	int m = cha % w;
	long long digit = base - num - 1;
	long long result = digit / pow(10, m);
	return result % 10;
}

int main_NthDigit() {
	cout << findNthDigit(1000000000) << endl;
	system("pause");
	return 0;
}