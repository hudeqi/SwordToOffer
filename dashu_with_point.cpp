#include <iostream>
#include <string>
using namespace std;

int getcha(int a, int b) {
	if (a >= b) {
		return a - b;
	}
	else
	{
		return b - a;
	}
}

string add(string s1, string s2)
{
	bool flag1 = false;
	bool flag2 = false;
	int point_pos1 = -1;
	int point_pos2 = -1;
	for (int i = 0; i < s1.length(); i++) {
		if (s1[i] == '.') {
			flag1 = true;
			point_pos1 = i;
			break;
		}
	}
	for (int i = 0; i < s2.length(); i++) {
		if (s2[i] == '.') {
			flag2 = true;
			point_pos2 = i;
			break;
		}
	}
	if (!flag1) {
		s1 = s1 + ".0";
		point_pos1 = s1.length() - 2;
	}
	if (!flag2) {
		s2 = s2 + ".0";
		point_pos2 = s2.length() - 2;
	}
	int point_pos_cha = getcha(s1.length() - point_pos1, s2.length() - point_pos2);
	if (point_pos_cha > 0) {
		if ((s1.length() - point_pos1) > (s2.length() - point_pos2)) {
			for (int i = 0; i < point_pos_cha; i++) {
				s2 += "0";
			}
		}
		else {
			for (int i = 0; i < point_pos_cha; i++) {
				s1 += "0";
			}
		}
	}
	string max, min;
	max = s1;
	min = s2;
	if (max.size()<min.size())
	{
		max = s2;
		min = s1;
	}
	int La = max.size();
	int Lb = min.size();
	int j = La - 1;
	for (int i = Lb - 1; i >= 0; i--, j--) {
		if (min[i] == '.')
			continue;
		max[j] += min[i] - '0';
	}
	for (int i = La - 1; i >= 1; i--) {
		if (max[i] == '.')
			continue;
		if (max[i] > '9' && max[i - 1] != '.')
		{
			max[i] -= 10;
			max[i - 1]++;
		}
		else if (max[i] > '9' && max[i - 1] == '.') {
			max[i] -= 10;
			max[i - 2]++;
		}
	}
	if (max[0]>'9')
	{
		max[0] -= 10;
		max = '1' + max;
	}
	return max;
}

bool elligal(string s) {
	if (s[0] == '.' || s[s.length() - 1] == '.') {
		return false;
	}
	else if (s[0] == '0' && s[1] != '.') {
		return false;
	}
	else {
		int count = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '.')
				count++;
		}
		if (count > 1)
			return false;
		else
		{
			return true;
		}
	}
}

int main_mmc()
{
	string s1 = "";
	string s2 = "";
	cin >> s1 >> s2;
	if (!elligal(s1) || !elligal(s2)) {
		return false;
	}
	else {
		cout << add(s1, s2);
	}
	system("pause");
	return 0;
}