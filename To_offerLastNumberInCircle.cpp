#include<iostream>
#include<vector>
using namespace std;

int LastRemaining_Solution(int n, int m)
{
	vector<int> l;
	for (int i = 0; i < n; i++) {
		l.push_back(i);
	}
	int count = 0;
	int index = 0;
	for (index = 0; l.size() > 1; index++) {
		count++;
		index = index == l.size() ? 0 : index;
		if (count % m == 0) {
			l.erase(l.begin() + index);
			if (index == 0)
				index = l.size() - 1;
			else {
				index--;
			}
		}
		if (l.size() == 1)
			return l[0];
	}
	return index - 1;
}

int main_LastNumberInCircle() {
	cout << LastRemaining_Solution(6, 3);
	system("pause");
	return 0;
}