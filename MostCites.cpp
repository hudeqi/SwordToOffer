#include<iostream>
#include<vector>
using namespace std;

int mostCities(vector<int>& parent, int n, int L) {
	int* dis = new int[n];
	dis[0] = 0;
	vector<int> temp;
	temp.push_back(0);
	int maxdep = 0;
	while (temp.size() != 0)
	{
		int a = temp[temp.size() - 1];
		temp.pop_back();
		for (int i = 0; i < parent.size(); i++) {
			if (a == parent[i]) {
				dis[i + 1] = dis[a] + 1;
				temp.push_back(i + 1);
				if (dis[i + 1] > maxdep) {
					maxdep = dis[i + 1];
				}
			}
		}
	}
	if (maxdep >= L) {
		return L + 1;
	}
	else
	{
		return n < maxdep + (L - maxdep) / 2 + 1 ? n : maxdep + (L - maxdep) / 2 + 1;
	}
}

int main_MostCities() {
	int n, L;
	vector<int> parent;
	cin >> n >> L;
	for (int i = 0; i < n - 1; i++) {
		int temp;
		cin >> temp;
		parent.push_back(temp);
	}
	int maxDep = mostCities(parent, n ,L);
	cout << maxDep;
	system("pause");
	return 0;
}