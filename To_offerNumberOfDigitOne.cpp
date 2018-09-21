#include<iostream>
using namespace std;

int NumberOf1Between1AndN_Solution(int n)
{
	int factor = 1;
	int high = 0;
	int cur = 0;
	int low = 0;
	int count = 0;
	while ((n / factor) != 0)
	{
		high = n / (factor * 10);
		cur = n / factor % 10;
		low = n - n / factor * factor;
		switch (cur)
		{
		case 0:
			count += (high * factor);
			break;
		case 1:
			count += (high * factor + 1 + low);
			break;
		default:
			count += (high + 1) * factor;
		}
		factor *= 10;
	}
	return count;
}

int main_NumberOf1Between1AndN_Solution() {
	cout << NumberOf1Between1AndN_Solution(10);
	system("pause");
	return 0;
}