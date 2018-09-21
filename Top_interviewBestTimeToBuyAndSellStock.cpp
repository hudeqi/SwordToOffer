#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxProfit(vector<int>& prices) {
	if (prices.size() <= 1)
		return 0;
	int minPrice = 999999;
	int maxProfits = 0;
	for (int i = 0; i < prices.size(); i++) {
		minPrice = min(minPrice, prices[i]);
		maxProfits = max(maxProfits, prices[i] - minPrice);
	}
	return maxProfits;
}