#include<iostream>
#include<vector>
using namespace std;

int maxDeadGhost(vector<int>& CoordX, vector<int>& CoordY, int n){
	if (n == 1)
		return 1;
	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int disx = CoordX[i] - CoordX[j];
			int disy = CoordY[i] - CoordY[j];
			if (disx != 0 && disy != 0) {
				float k = disy * 1.0 / disx;
				float b = CoordY[i] - k * CoordX[i];
				float k1 = -1.0 / k;
				for (int m = 0; m < n; m++) {
					int c = 0;
					if (m == n + 1)
						continue;
					else
					{
						float b1 = CoordY[m] - k1 * CoordX[m];
						for (int all = 0; all < n; all++) {
							float v1 = k * CoordX[all] + b;
							float v2 = k1 * CoordX[all] + b1;
							if (CoordY[all] * 1.0 == v1 || CoordY[all] * 1.0 == v2)
								c++;
						}
						if (c > count)
							count = c;
					}
				}
			}
			else if (disx == 0 && disy != 0) {
				int normx = CoordX[i];
				for (int m = 0; m < n; m++) {
					int c = 0;
					if (m == n + 1)
						continue;
					else
					{
						int normy = CoordY[m];
						for (int all = 0; all < n; all++) {
							if (CoordX[all] == normx || CoordY[all] == normy)
								c++;
						}
						if (c > count)
							count = c;
					}
				}
			}
			else
			{
				int normy = CoordY[i];
				for (int m = 0; m < n; m++) {
					int c = 0;
					if (m == n + 1)
						continue;
					else
					{
						int normx = CoordX[m];
						for (int all = 0; all < n; all++) {
							if (CoordX[all] == normx || CoordY[all] == normy)
								c++;
						}
						if (c > count)
							count = c;
					}
				}
			}
		}
	}
	return count;
}

int main_ShootingGames() {
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
	int result = maxDeadGhost(CoordX, CoordY, n);
	cout << result;
	system("pause");
	return 0;
}