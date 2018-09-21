#include<iostream>
using namespace std;

bool isPalindrome(int x) {
	if (x < 0)
		return false;
	int orignal = x;
	int pal = 0;
	int mod = x % 10;
	x = x / 10;
	pal = pal * 10 + mod;
	while (x != 0)
	{
		mod = x % 10;
		x = x / 10;
		pal = pal * 10 + mod;
	}
	if (pal == orignal) {
		return true;
	}
	else
	{
		return false;
	}
}

void main_PalindromeNumber() {
	int a = 10;
	cout << isPalindrome(a) << endl;
	system("pause");
}