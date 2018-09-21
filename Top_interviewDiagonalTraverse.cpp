#include<iostream>
#include<vector>
using namespace std;

vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
	if (matrix.size() == 0)
		return vector<int>();
	vector<int> result;
	int i = 0, j = 0;
	int M = matrix.size() - 1, N = matrix[0].size() - 1;
	for (int n = 0; n < (M + 1) * (N + 1); n++) {
		result.push_back(matrix[i][j]);
		if ((i + j) % 2 == 0) {
			if (i == 0 && j < N) j++;
			else if (j == N) i++;
			else { i--; j++; }
		}
		else
		{
			if (j == 0 && i < M) i++;
			else if (i == M) j++;
			else { i++; j--; }
		}
	}
	return result;
}

int main_DiagonalTraverse() {
	vector<vector<int>> input;
	vector<int> temp;
	temp.push_back(1);
	temp.push_back(2);
	temp.push_back(3);
	input.push_back(temp);
	temp.clear();
	temp.push_back(4);
	temp.push_back(5);
	temp.push_back(6);
	input.push_back(temp);
	temp.clear();
	temp.push_back(7);
	temp.push_back(8);
	temp.push_back(9);
	input.push_back(temp);
	vector<int> result = findDiagonalOrder(input);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	system("pause");
	return 0;
}