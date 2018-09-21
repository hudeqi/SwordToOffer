#include<iostream>
using namespace std;

void replaceSpace(char *str, int length) {
	if (str == NULL || length < 0)
		return;
	int originalLength = 0;
	int spaceCount = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == ' ') {
			spaceCount++;
		}
		originalLength++;
	}
	int newLength = originalLength + 2 * spaceCount;
	while (originalLength >= 0 && newLength > originalLength) {
		if (str[originalLength] == ' ') {
			str[newLength--] = '0';
			str[newLength--] = '2';
			str[newLength--] = '%';
			originalLength--;
		}
		else {
			str[newLength--] = str[originalLength--];
		}
	}
}