#include<iostream>
#include<vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
	if (matrix.size() == 0) {
		return false;
	}
	int rows = matrix.size();
	int cols = matrix[0].size();
	int i = rows - 1, j = 0;
	while (i >= 0 && j<cols) {
		if (target<matrix[i][j])
			i--;
		else if (target>matrix[i][j])
			j++;
		else
			return true;
	}
	return false;
}