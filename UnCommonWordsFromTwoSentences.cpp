#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;

vector<string> uncommonFromSentences(string A, string B) {
	vector<string> result;
	map<string, int> temp;
	int start = 0;
	int end = 0;
	bool flag = false;
	string all = A + " " + B;
	for (int i = 0; i < all.length(); i++) {
		if (all[i] != ' ') {
			if (!flag) {
				if (i == all.length() - 1) {
					end = i;
					string s = all.substr(start, end - start + 1);
					map<string, int>::iterator iter = temp.find(s);
					if (iter == temp.end()) {
						temp.insert(map<string, int>::value_type(s, 1));
					}
					else
					{
						temp[s]++;
					}
				}
				continue;
			}
			else
			{
				start = i;
				if (i == all.length() - 1) {
					end = i;
					string s = all.substr(start, end - start + 1);
					map<string, int>::iterator iter = temp.find(s);
					if (iter == temp.end()) {
						temp.insert(map<string, int>::value_type(s, 1));
					}
					else
					{
						temp[s]++;
					}
				}
				flag = false;
			}
		}
		else
		{
			if (!flag) {
				end = i;
				string s = all.substr(start, end - start);
				map<string, int>::iterator iter = temp.find(s);
				if (iter == temp.end()) {
					temp.insert(map<string, int>::value_type(s, 1));
				}
				else
				{
					temp[s]++;
				}
				flag = true;
			}
			else
			{
				continue;
			}
		}
	}
	map<string, int>::iterator iter = temp.begin();
	while (iter != temp.end())
	{
		if ((*iter).second == 1)
			result.push_back((*iter).first);
		iter++;
	}
	return result;
}

int main_UnCommonWordsFromTwoSentences() {
	string a = "ppz wl ppz";
	string b = "wl e b b";
	vector<string> result = uncommonFromSentences(a, b);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << endl;
	}
	system("pause");
	return 0;
}