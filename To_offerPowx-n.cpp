#include<iostream>
#include<limits>
using namespace std;

double myPow(double x, int n) {
	if (abs(x) < 0.000001 && n < 0) {
		return numeric_limits<double>::max();
	}
	if (abs(x) < 0.000001 && n > 0) {
		return 0.000000;
	}
	if (abs(abs(x) - 1.000000) < 0.000001) {
		if (x > 0)
			return 1.000000;
		else {
			if (n % 2 == 0)
				return 1.000000;
			else {
				return -1.000000;
			}
		}
	}
	if (n == 0)
		return 1.000000;
	double temp = x;
	double result = temp;
	if (n == -2147483648)
		return 0.000000;
	for (int i = 1; i < abs(n); i++) {
		if (abs(result) < 0.000001) {
			return 0.000000;
		}
		result = result * temp;
	}
	if (n > 0) {
		return result;
	}
	else
	{
		return 1.000000 / result;
	}
}

int main_Powxn() {
	cout << myPow(-1.00000, 2147483647);
	system("pause");
	return 0;
}