#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int GetUglyNumber_Solution(int index) {
	if (index < 1)
		return -1;
	if (index == 1)
		return 1;
	vector<int> temp(index, 0);
	temp[0] = 1;
	int p2 = 0, p3 = 0, p5 = 0;
	for (int i = 1; i < index; i++) {
		temp[i] = min(temp[p2] * 2, min(temp[p3] * 3, temp[p5] * 5));
		if (temp[i] == temp[p2] * 2) p2++;
		else if (temp[i] == temp[p3] * 3) p3++;
		else p5++;
		if (i > 0 && temp[i] == temp[i - 1])
			i--;
	}
	return temp[index - 1];
}

int main_UglyNumber() {
	cout << GetUglyNumber_Solution(7);
	system("pause");
	return 0;
}