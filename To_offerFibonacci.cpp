#include<iostream>
using namespace std;

int Fibonacci(int n) {
	/*递归不好*/
	//if (n == 0)
	//	return 0;
	//if (n == 1)
	//	return 1;
	//return Fibonacci(n - 1) + Fibonacci(n - 2);

	/*迭代好*/
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	int prepre = 0, pre = 1;
	for (int i = 2; i < n + 1; i++) {
		int temp = pre;
		pre = pre + prepre;
		prepre = temp;
	}
	return pre;
}

int main_Fibonacci() {
	cout << Fibonacci(4);
	system("pause");
	return 0;
}