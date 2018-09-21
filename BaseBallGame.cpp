#include<iostream>
#include<vector>
#include<string>
using namespace std;

int calPoints(vector<string>& ops) {
	vector<int> temp;
	int result = 0;
	if (ops[0].compare("D") == 0 || ops[0].compare("+") == 0 || ops[0].compare("C") == 0) {
		return 0;
	}
	for (int i = 0; i < ops.size(); i++) {
		if (ops[i].compare("+") == 0) {
			temp.push_back(temp[temp.size() - 1] + temp[temp.size() - 2]);
		}
		else if (ops[i].compare("D") == 0) {
			temp.push_back(temp[temp.size() - 1] * 2);
		}
		else if (ops[i].compare("C") == 0) {
			temp.pop_back();
		}
		else
		{
			temp.push_back(atoi(ops[i].c_str()));
		}
	}
	for (int i = 0; i < temp.size(); i++) {
		result += temp[i];
	}
	return result;
}

int main_BaseBallGame() {
	vector<string> t;
	t.push_back("5");
	t.push_back("2");
	t.push_back("C");
	t.push_back("D");
	t.push_back("+");
	cout << calPoints(t) << endl;
	system("pause");
	return 0;
}