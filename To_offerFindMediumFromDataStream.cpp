#include<iostream>
#include<vector>
#include<algorithm>
#include<xfunctional>
using namespace std;

class Solution_FindMediumFromDataStream {
public:
	void Insert(int num)
	{
		if ((vmax.size() + vmin.size()) % 2 == 0) {
			if (vmin.size() > 0 && num > vmin[0]) {
				vmin.push_back(num);
				push_heap(vmin.begin(), vmin.end(), greater<int>());
				num = vmin[0];
				pop_heap(vmin.begin(), vmin.end(), greater<int>());
				vmin.pop_back();
			}
			vmax.push_back(num);
			push_heap(vmax.begin(), vmax.end(), less<int>());
		}
		else {
			if (vmax.size() > 0 && num < vmax[0]) {
				vmax.push_back(num);
				push_heap(vmax.begin(), vmax.end(), less<int>());
				num = vmax[0];
				pop_heap(vmax.begin(), vmax.end(), less<int>());
				vmax.pop_back();
			}
			vmin.push_back(num);
			push_heap(vmin.begin(), vmin.end(), greater<int>());
		}
	}

	double GetMedian()
	{
		if ((vmax.size() + vmin.size()) % 2 == 0) {
			if ((vmax.size() + vmin.size()) == 0)
				return -1.0;
			return (vmax[0] + vmin[0]) / 2.0;
		}
		else {
			return vmax[0] * 1.0;
		}
	}

private:
	vector<int> vmax;
	vector<int> vmin;
};