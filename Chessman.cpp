#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> minOperateNum(vector<int>& CoordX, vector<int>& CoordY, int n) {
	vector<int> result(n, INT_MAX);
	for (int i = 0; i < CoordX.size(); i++) {
		for (int j = 0; j < CoordY.size(); j++) {
			vector<int> dis(n, 0);
			for (int k = 0; k < n; k++){
				int moveNum = abs(CoordX[k] - CoordX[i]) + abs(CoordY[k] - CoordY[j]);
				dis[k] = moveNum;
			}
			sort(dis.begin(), dis.end());
			for (int m = 1; m <= n; m++) {
				int count = 0;
				for (int p = 0; p < m; p++) {
					count += dis[p];
				}
				if (count < result[m - 1]) {
					result[m - 1] = count;
				}
			}
		}
	}
	return result;
}

int main_Chessman() {
	int n;
	vector<int> CoordX;
	vector<int> CoordY;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		CoordX.push_back(temp);
	}
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		CoordY.push_back(temp);
	}
	vector<int> result = minOperateNum(CoordX, CoordY, n);
	for (int i = 0; i < n - 1; i++) {
		cout << result[i] << " ";
	}
	cout << result[result.size() - 1];
	system("pause");
	return 0;
}