#include<iostream>
using namespace std;

bool isNumeric(char* string)
{
	if (string == NULL)
		return false;
	if (string[1] == '\0') {
		if (string[0] >= 48 && string[0] <= 57) {
			return true;
		}
		else {
			return false;
		}
	}
	int count = 0;
	int pos = 9999999999;
	for (int i = 0; string[i] != '\0'; i++) {
		if (i == 0) {
			if (string[i] == '+' || string[i] == '-' || (string[i] >= 48 && string[i] <= 57)) {
				continue;
			}
			else
				return false;
		}
		if (string[i] == '.') {
			if (i > pos)
				return false;
			if (string[i - 1] >= 48 && string[i - 1] <= 57 && string[i + 1] >= 48 && string[i + 1] <= 57) {
				count++;
			}
			else {
				if ((string[i - 1] == '-' || string[i - 1] == '+') && i == 1)
				{
					continue;
				}
				else {
					return false;
				}
			}
		}
		if (count > 1)
			return false;
		if (!(string[i] == '.' || string[i] == '+' || string[i] == '-' || string[i] == 'E' ||
			string[i] == 'e' || (string[i] >= 48 && string[i] <= 57)))
		{
			return false;
		}
		if (string[i] == '+' || string[i] == '-') {
			if (i != 0 && (string[i - 1] != 'E' && string[i - 1] != 'e')) {
				return false;
			}
			pos = i;
		}
		if (string[i] == 'E' || string[i] == 'e') {
			if ((!(string[i - 1] >= 48 && string[i - 1] <= 57)) || (string[i + 1] == '\0'))
				return false;
		}
	}
	return true;
}

int main_StringIsNumOrNot() {
	char* str = "12e";
	cout << isNumeric(str);
	system("pause");
	return 0;
}