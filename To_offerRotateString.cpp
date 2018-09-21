#include<iostream>
#include<string>
using namespace std;

string LeftRotateString(string str, int n) {
	if (str == "")
		return "";
	if (n == 0)
		return str;
	int len = str.size();
	if (n > 0) {
		int num = n / len;
		int mod = n % len;
		string str1 = str.substr(0, mod);
		string str2 = str.substr(mod, len - mod);
		return str2 + str1;
	}
	else
	{
		int num = n * (-1) / len;
		int mod = n * (-1) % len;
		string str1 = str.substr(len - mod, mod);
		string str2 = str.substr(0, len - mod);
		return str1 + str2;
	}
}