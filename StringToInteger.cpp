#include<iostream>
#include<string>
using namespace std;

int myAtoi(string str) {
	if (str.compare("") == 0) {
		return 0;
	}
	int negative = 1;
	bool finish = false;
	bool start = false;
	char* s = (char*)str.data();
	int result = 0;
	for (int i = 0; i < str.length(); i++) {
		if (!start && s[i] == ' ') {
			continue;
		}
		if (start && (s[i] < 48 || s[i] > 57)) {
			return result * negative;
		}
		if ((s[i] >= 48 && s[i] <= 57) || s[i] == '-' || s[i] == '+') {
			start = true;
			if (s[i] >= 48 && s[i] <= 57) {
				int temp = s[i] - '0';
				if (result * negative > INT_MAX / 10 || (result * negative == INT_MAX / 10 && temp * negative > 7))
					return INT_MAX ;
				else if (result * negative < INT_MIN / 10 || (result * negative == INT_MIN / 10 && temp * negative < -8))
				{
					return INT_MIN;
				}
				else
				{
					result = result * 10 + temp;
				}
			}
			if (s[i] == '-') {
				negative = -1;
			}
			if (s[i] == '+') {
				negative = 1;
			}
		}
		if (!start && ((s[i] < 48 || s[i] > 57) && s[i] != '-')) {
			return 0;
		}
	}
	if (!start) {
		return 0;
	}
	else
	{
		return result * negative;
	}
}

void main_StringToInteger() {
	string s = "-2147483649";
	cout << myAtoi(s) << endl;
	system("pause");
}