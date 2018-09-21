#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool dfs(vector<vector<char>>& matrix, int i, int j, int rows, int cols, string str, int start) {
	if (start == str.size())
		return true;
	else if (i < 0 || i >= rows || j < 0 || j >= cols || str[start] != matrix[i][j])
		return false;
	matrix[i][j] ^= 255;
	bool result = (dfs(matrix, i - 1, j, rows, cols, str, start + 1) ||
		dfs(matrix, i + 1, j, rows, cols, str, start + 1) ||
		dfs(matrix, i, j - 1, rows, cols, str, start + 1) ||
		dfs(matrix, i, j + 1, rows, cols, str, start + 1));
	matrix[i][j] ^= 255;
	return result;
}

bool hasPath(char* matrix, int rows, int cols, char* str)
{
	vector<vector<char>> mat;
	for (int i = 0; i < rows; i++) {
		vector<char> temp;
		for (int j = 0; j < cols; j++) {
			temp.push_back(*matrix);
			matrix++;
		}
		mat.push_back(temp);
	}
	string s(str);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (mat[i][j] == *str) {
				bool flag = dfs(mat, i, j, rows, cols, s, 0);
				if (flag)
					return true;
			}
		}
	}
	return false;
}

int main_WordSearch() {
	string s1, s2;
	int a, b;
	getline(cin, s1);
	getline(cin, s2);
	do {
		cin >> a>>b;
	} while (cin.get() != '\n');
	char* m = (char*)s1.data();
	char* s = (char*)s2.data();
	cout << hasPath(m, a, b, s);
	system("pause");
	return 0;
}