#include<iostream>
using namespace std;

int Sum_Solution(int n) {
	if (n == 1)
		return 1;
	return n + Sum_Solution(n - 1);
}

int main_Sum_Solution () {
	cout << Sum_Solution(100);
	system("pause");
	return 0;
}