#include<iostream>
#include<vector>
using namespace std;

bool VerifySquenceOfBST(vector<int> sequence) {
	if (sequence.size() == 0)
		return false;
	if (sequence.size() == 1)
		return true;
	int i = 0, mid = 0;
	int root = sequence.back();
	for (i = 0; i < sequence.size() - 1; i++) {
		if (sequence[i] < root) {
			mid++;
		}
		else {
			break;
		}
	}
	for (; i < sequence.size() - 1; i++) {
		if (sequence[i] < root) {
			return false;
		}
	}
	vector<int> left, right;
	left.assign(sequence.begin(), sequence.begin() + mid);
	right.assign(sequence.begin() + mid + 1, sequence.begin() + sequence.size());
	bool l = true, r = true;
	if (left.size() > 0) {
		l = VerifySquenceOfBST(left);
	}
	if (right.size() > 0) {
		r = VerifySquenceOfBST(right);
	}
	return l && r;
}