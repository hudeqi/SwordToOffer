#include <iostream>
#include <vector>
using namespace std;

bool Find(int target, vector<vector<int>> array) {
	int rows = array.size();
	int cols = array[0].size();
	int i = rows - 1, j = 0;
	while (i >= 0 && j<cols) {
		if (target<array[i][j])
			i--;
		else if (target>array[i][j])
			j++;
		else
			return true;
	}
	return false;
}