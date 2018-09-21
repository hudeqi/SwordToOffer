#include<iostream>
#include<vector>
using namespace std;

/*µ›πÈ–¥∑®*/
int uniquePaths(int m, int n) {
	if (m <= 0 || n <= 0)
		return -1;
	if (m == 1 || n == 1)
		return 1;
	return uniquePaths(m, n - 1) + uniquePaths(m - 1, n);
}

/*∑«µ›πÈ–¥∑®*/
int uniquePaths1(int m, int n) {
	if (m <= 0 || n <= 0)
		return -1;
	vector<vector<int>> result(n, vector<int>(m, 1));
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			result[i][j] = result[i - 1][j] + result[i][ j - 1];
		}
	}
	return result[n - 1][m - 1];
}

int main_DiffrientPaths() {
	cout << uniquePaths1(2, 2);
	system("pause");
	return 0;
}
