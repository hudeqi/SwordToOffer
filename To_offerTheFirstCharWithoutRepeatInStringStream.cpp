#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

class StringStream
{
public:
	static bool compare (const pair<char, vector<int>>& a, const pair<char, vector<int>>& b) {
		if (a.second[0] != b.second[0]) {
			return a.second[0] < b.second[0];
		}
		else {
			return a.second[1] < b.second[1];
		}
	}

	//Insert one char from stringstream
	void Insert(char ch)
	{
		if (m.find(ch) == m.end()) {
			vector<int> temp;
			temp.push_back(1);
			temp.push_back(i++);
			m.insert(make_pair(ch, temp));
		}
		else {
			m[ch][0]++;
		}
	}
	//return the first appearence once char in current stringstream
	char FirstAppearingOnce()
	{
		char c;
		if (m.size() == 0)
			c = '#';
		vector<pair<char, vector<int>>> v(m.begin(), m.end());
		sort(v.begin(), v.end(), compare);
		if (v.begin()->second[0] == 1)
			c = v.begin()->first;
		else
		{
			c = '#';
		}
		result += c;
		return c;
	}

private:
	map<char, vector<int>> m;
	string result;
	int i = 0;
};

int main_TheFirstCharInStringStream() {
	StringStream s;
	s.Insert('g');
	cout << s.FirstAppearingOnce();
	s.Insert('o');
	cout << s.FirstAppearingOnce();
	s.Insert('o');
	cout << s.FirstAppearingOnce();
	s.Insert('g');
	cout << s.FirstAppearingOnce();
	s.Insert('l');
	cout << s.FirstAppearingOnce();
	s.Insert('e');
	cout << s.FirstAppearingOnce();
	system("pause");
	return 0;
}