#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

void permutation(vector<string>& result, int begin, string str) {
	if (begin == str.size() - 1)
		result.push_back(str);
	for (int i = begin; i < str.size(); i++) {
		if (i != begin && str[i] == str[begin]) {
			continue;
		}
		swap(str[i], str[begin]);
		permutation(result, begin + 1, str);
	}
}

vector<string> Permutation(string str) {
	if (str == "")
		return vector<string>();
	vector<char> temp;
	for (int i = 0; i < str.size(); i++) {
		temp.push_back(str[i]);
	}
	sort(temp.begin(), temp.end());
	string strc = "";
	for (int i = 0; i < temp.size(); i++) {
		strc = strc + temp[i];
	}
	vector<string> result;
	permutation(result, 0, strc);
	sort(result.begin(), result.end());
	return result;
}

int main_PermutationsII() {
	vector<string> result = Permutation("2211");
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << endl;
	}
	system("pause");
	return 0;
}