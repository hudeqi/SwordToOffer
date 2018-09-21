#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

int flipgame(vector<int>& fronts, vector<int>& backs) {
	set<int> n;
	for (int i = 0; i < fronts.size(); i++) {
		if (fronts[i] == backs[i]) {
			n.insert(fronts[i]);
		}
	}
	vector<int> y;
	for (int i = 0; i < fronts.size(); i++) {
		if (n.find(fronts[i]) == n.end()) {
			y.push_back(fronts[i]);
		}
	}
	for (int i = 0; i < backs.size(); i++) {
		if (n.find(backs[i]) == n.end()) {
			y.push_back(backs[i]);
		}
	}
	if (y.size() == 0) {
		return 0;
	}
	else
	{
		sort(y.begin(), y.end());
		return y[0];
	}
}

int main_CardFlippingGame() {
	vector<int> f;
	f.push_back(1);
	//f.push_back(2);
	//f.push_back(4);
	f.push_back(4);
	f.push_back(7);
	vector<int> b;
	b.push_back(1);
	//b.push_back(3);
	//b.push_back(4);
	b.push_back(1);
	b.push_back(3);
	cout << flipgame(f, b) << endl;
	system("pause");
	return 0;
}