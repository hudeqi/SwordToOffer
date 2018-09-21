#include<iostream>
#include<vector>
using namespace std;

vector<int> multiply(const vector<int>& A) {
	if (A.size() == 0)
		return vector<int>();
	if (A.size() == 1)
		return vector<int>(1, 1);
	vector<int> front;
	vector<int> back;
	front.push_back(A[0]);
	back.push_back(A.back());
	for (int i = 1; i < A.size() - 1; i++) {
		int f = front.back() * A[i];
		front.push_back(f);
		int b = back.back() * A[A.size() - 1 - i];
		back.push_back(b);
	}
	vector<int> result;
	result.push_back(back.back());
	for (int i = 0; i < front.size() - 1; i++) {
		result.push_back(front[i] * back[back.size() - i - 2]);
	}
	result.push_back(front.back());
	return result;
}