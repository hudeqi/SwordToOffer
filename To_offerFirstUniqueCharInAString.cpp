#include<iostream>
#include<string>
#include<map>
#include<set>
using namespace std;

int FirstNotRepeatingChar(string str) {
	if (str == "")
		return -1;
	if (str.size() == 1)
		return 0;
	map<char, int> m;
	set<int> s;
	for (int i = 0; i < str.size(); i++) {
		if (m.find(str[i]) == m.end()) {
			m.insert(make_pair(str[i], i));
			s.insert(i);
		}
		else
		{
			if (s.find(m[str[i]]) != s.end()) {
				s.erase(m[str[i]]);
			}
		}
	}
	if (s.size() == 0) {
		return -1;
	}
	return *s.begin();
}