#include<iostream>
#include<vector>
using namespace std;

vector<int> printMatrix(vector<vector<int>>& matrix) {
	if (matrix.size() == 0)
		return vector<int>();
	vector<int> result;
	int fx = 0;
	int m = matrix.size();
	int n = matrix[0].size();
	while (result.size() < matrix.size() * matrix[0].size())
	{
		int num = fx / 4;
		if (fx % 4 == 0) {
			for (int i = num; i < n - num; i++) {
				result.push_back(matrix[num][i]);
			}
		}
		else if (fx % 4 == 1) {
			for (int i = 1 + num; i < m - num; i++) {
				result.push_back(matrix[i][n - num - 1]);
			}
		}
		else if (fx % 4 == 2) {
			for (int i = n - num - 2; i >= num; i--) {
				result.push_back(matrix[m - num - 1][i]);
			}
		}
		else
		{
			for (int i = m - num - 2; i >= num + 1; i--) {
				result.push_back(matrix[i][num]);
			}
		}
		fx++;
	}
	return result;
}

int main_SpiralMatrix() {
	vector<vector<int>> input;
	vector<int> t1;
	t1.push_back(1);
	t1.push_back(2);
	vector<int> t2;
	t2.push_back(3);
	t2.push_back(4);
	input.push_back(t1);
	input.push_back(t2);
	vector<int> result = printMatrix(input);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	system("pause");
	return 0;
}
