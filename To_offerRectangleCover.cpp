#include<iostream>
using namespace std;

/*����Ϊ1��2��쳲���������*/
int rectCover(int number) {
	if (number == 0)
		return 0;
	if (number == 1)
		return 1;
	if (number == 2)
		return 2;
	int prepre = 1, pre = 2;
	for (int i = 3; i < number + 1; i++) {
		int temp = pre;
		pre = pre + prepre;
		prepre = temp;
	}
	return pre;
}