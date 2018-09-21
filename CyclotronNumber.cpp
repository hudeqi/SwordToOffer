#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> getCyclotronMartix(int n) {
	vector<vector<int>> result;
	for (int i = 0; i < n; i++) {
		vector<int> temp(n, 0);
		result.push_back(temp);
	}
	int initialPos = n % 2 == 0 ? n / 2 - 1 : n / 2;
	int curPosRow = initialPos;
	int curPosCol = initialPos;
	result[curPosRow][curPosCol] = 1;
	int sort = 0;
	for (int i = 2; i <= n * n; i++) {
		sort = sort % 4;
		again:
		switch (sort)
		{
		case 0:
			if (curPosCol < n - 1 && result[curPosRow][curPosCol + 1] == 0) {
				result[curPosRow][curPosCol + 1] = i;
				curPosCol++;
				sort++;
			}
			else {
				sort = (sort + 3) % 4;
				goto again;
			}
			break;
		case 1:
			if (curPosRow < n - 1 && result[curPosRow + 1][curPosCol] == 0) {
				result[curPosRow + 1][curPosCol] = i;
				curPosRow++;
				sort++;
			}
			else {
				sort = (sort + 3) % 4;
				goto again;
			}
			break;
		case 2:
			if (curPosCol > 0 && result[curPosRow][curPosCol - 1] == 0) {
				result[curPosRow][curPosCol - 1] = i;
				curPosCol--;
				sort++;
			}
			else {
				sort = (sort + 3) % 4;
				goto again;
			}
			break;
		case 3:
			if (curPosRow > 0 && result[curPosRow - 1][curPosCol] == 0) {
				result[curPosRow - 1][curPosCol] = i;
				curPosRow--;
				sort++;
			}
			else {
				sort = (sort + 3) % 4;
				goto again;
			}
			break;
		default:
			break;
		}
	}
	return result;
}

int main_CyclotronNumber() {
	int n = 100;
	vector<vector<int>> result = getCyclotronMartix(n);
	for (int i = 0; i < result.size(); i++) {
		cout << endl;
		for (int j = 0; j < result[i].size(); j++) {
			cout << result[i][j] << " ";
		}
	}
	system("pause");
	return 0;
}