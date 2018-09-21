#include<iostream>
#include<string>
#include<vector>
using namespace std;

string intToRoman(int num) {
	string result = "";
	int M = 1000;
	int count = 0;
	vector<string> dict;
	dict.push_back("M");
	dict.push_back("D");
	dict.push_back("C");
	dict.push_back("L");
	dict.push_back("X");
	dict.push_back("V");
	dict.push_back("I");
	while (num != 0)
	{
		string cur = dict[count];
		int high = num / M;
		if (count % 2 == 0) {
			if (high <= 3) {
				for (int i = 0; i < high; i++)
					result = result + cur;
			}
			else {
				result = result + cur + dict[count - 1];
			}
			num = num - high * M;
		}
		else
		{
			int temp = num / (M / 5);
			if (high == 1 && temp == 9) {
				result = result + dict[count + 1] + dict[count - 1];
				num = num - temp * (M / 5);
			}
			if (high == 1 && temp < 9) {
				result = result + cur;
				num = num - high * M;
			}
		}
		int divide = count % 2 == 0 ? 2 : 5;
		M = M / divide;
		count++;
	}
	return result;
}

void main_IntegerToRoman() {
	int a = 1994;
	cout << intToRoman(a) << endl;
	system("pause");
}