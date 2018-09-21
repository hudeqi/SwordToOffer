#include<iostream>
#include<vector>
using namespace std;

int maxRotateFunction(vector<int>& A) {
	if (A.size() == 0)
		return 0;
	int maxValue = INT_MIN;
	for (int i = 0; i < A.size(); i++) {
		int sum = 0;
		int count = 0;
		for (int j = i;; j++) {
			if (j > (A.size() - 1))
				j = 0;
			sum += A[j] * count;
			count++;
			if (count == A.size())
				break;
		}
		if (sum > maxValue)
			maxValue = sum;
	}
	return maxValue;
}

int maxRotateFunction1(vector<int>& A) {
	if (A.size() == 0)
		return 0;
	int maxi = 0, tmp = 0, sum = 0;
	int n = A.size();

	for (int i = 0; i < n; i++) {
		sum += A[i];
		maxi += i * A[i];
	}

	tmp = maxi;
	for (int i = 0; i < n; i++) {
		tmp += n * A[i] - sum;

		maxi = maxi > tmp ? maxi : tmp;
	}

	return maxi;
}

int main_RotateFunction() {
	vector<int> test;
	test.push_back(4);
	test.push_back(3);
	test.push_back(2);
	test.push_back(6);
	int result = maxRotateFunction1(test);
	cout << result << endl;
	system("pause");
	return 0;
}