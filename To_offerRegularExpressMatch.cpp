#include<iostream>
#include<string>
using namespace std;

bool matchNext(char* str, char* pattern) {
	if (*str == '\0' && *pattern == '\0')
		return true;
	if (*str != '\0' && *pattern == '\0')
		return false;
	if (*(pattern + 1) == '*') {
		if (*str == *pattern || (*pattern == '.' && *str != '\0')) {
			return matchNext(str + 1, pattern + 2) || matchNext(str + 1, pattern) || matchNext(str, pattern + 2);
		}
		else {
			return matchNext(str, pattern + 2);
		}
	}
	if (*str == *pattern || (*pattern == '.' && *str != '\0')) {
		return matchNext(str + 1, pattern + 1);
	}
	return false;
}

bool match(char* str, char* pattern)
{
	if (!str || !pattern)
		return false;
	return matchNext(str, pattern);
}