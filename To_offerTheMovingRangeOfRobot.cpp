#include<iostream>
#include<vector>
using namespace std;

int getSumForNum(int num) {
	int sum = 0;
	while (num != 0)
	{
		sum += (num % 10);
		num /= 10;
	}
	return sum;
}

void moving(int& count, vector<vector<int>>& pass, int rows, int cols, int threshold, int x, int y) {
	if (x < 0 || x >= rows || y < 0 || y >= cols || getSumForNum(x) + getSumForNum(y) > threshold)
		return;
	else if (pass[x][y] == 0)
	{
		if (getSumForNum(x) + getSumForNum(y) <= threshold) {
			pass[x][y] = 1;
			count += 1;
		}
	}
	if (x + 1 < rows && pass[x + 1][y] == 0) moving(count, pass, rows, cols, threshold, x + 1, y);
	if (x - 1 >= 0 && pass[x - 1][y] == 0) moving(count, pass, rows, cols, threshold, x - 1, y);
	if (y - 1 >= 0 && pass[x][y - 1] == 0) moving(count, pass, rows, cols, threshold, x, y - 1);
	if (y + 1 < cols && pass[x][y + 1] == 0) moving(count, pass, rows, cols, threshold, x, y + 1);
}

int movingCount(int threshold, int rows, int cols)
{
	int count = threshold < 0 ? 0 : 1;
	vector<vector<int>> pass(rows, vector<int>(cols, 0));
	pass[0][0] = 1;
	moving(count, pass, rows, cols, threshold, 0, 0);
	return count;
}

int main_TheMovingRangeOfRobot() {
	cout << movingCount(18, 50, 50);
	system("pause");
	return 0;
}