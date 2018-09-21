#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int superEggDrop(int K, int N) {
	int **temp = new int*[K + 1];
	for (int i = 0; i < K + 1; i++)
		temp[i] = new int[N + 1];
	for (int i = 0; i < K + 1; i++) {
		for (int j = 0; j < N + 1; j++) {
			if (j == 0 || i == 0) {
				temp[i][j] = 0;
			}
			else
			{
				temp[i][j] = j;
			}
		}
	}
	for (int i = 2; i < K + 1; i++) {
		for (int j = 2; j < N + 1; j++) {
			for (int k = 1; k < j + 1; k++) {
				temp[i][j] = min(temp[i][j], max(temp[i - 1][k - 1], temp[i][j - k]) + 1);
			}
		}
	}
	return temp[K][N];
}

int superEggDrop_1(int K, int N) {
	vector<int> dp(K + 1);
	int step = 0;
	for (; dp[K] < N; step++) {
		for (int i = K; i > 0; i--)
			dp[i] += (1 + dp[i - 1]);
	}
	return step;
}

int main_superEggDrop() {
	cout << superEggDrop_1(3, 14);
	system("pause");
	return 0;
}