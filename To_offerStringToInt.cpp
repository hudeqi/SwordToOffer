#include<iostream>
#include<string>
using namespace std;

int StrToInt(string str) {
	if (str.size() == 0)
		return 0;
	int sum = 0;
	bool negative = false;
	for (int i = 0; i < str.size(); i++) {
		if (i == 0) {
			if (str[i] == '-')
				negative = true;
			else if ((str[i] >= 48 && str[i] <= 57))
				sum = sum * 10 + (str[i] - '0');
			else if (str[i] == '+') {
				continue;
			}
			else {
				return 0;
			}
		}
		else {
			if ((str[i] >= 48 && str[i] <= 57)) {
				sum = sum * 10 + (str[i] - '0');
			}
			else
			{
				return 0;
			}
		}
	}
	return negative ? -1 * sum : sum;
}