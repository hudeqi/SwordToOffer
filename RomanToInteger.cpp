#include<iostream>
#include<string>
using namespace std;

int romanToInt(string s) {
	int result = 0;
	char* str = (char*)s.data();
	for (int i = 0; i < s.length();) {
		char cur = str[i];
		char next = 0;
		if (i + 1 < s.length())
			next = str[i + 1];
		switch (cur)
		{
		case 'I': 
			if (next == 'V' || next == 'X') {
				result += (next == 'V' ? 4 : 9);
				i += 2;
			}
			else
			{
				result += 1;
				i++;
			}
			break;
		case 'X':
			if (next == 'L' || next == 'C') {
				result += (next == 'L' ? 40 : 90);
				i += 2;
			}
			else
			{
				result += 10;
				i++;
			}
			break;
		case 'C':
			if (next == 'D' || next == 'M') {
				result += (next == 'D' ? 400 : 900);
				i += 2;
			}
			else
			{
				result += 100;
				i++;
			}
			break;
		case 'V':
			result += 5;
			i++;
			break;
		case 'L':
			result += 50;
			i++;
			break;
		case 'D':
			result += 500;
			i++;
			break;
		case 'M':
			result += 1000;
			i++;
			break;
		default:
			break;
		}
	}
	return result;
}

void main_RomanToInteger() {
	string s = "MCMXCIV";
	cout << romanToInt(s) << endl;
	system("pause");
}