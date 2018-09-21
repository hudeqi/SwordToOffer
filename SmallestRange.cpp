#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
	return a.first < b.first;
}

vector<int> getMinInterval(vector<vector<int>>& input, int K, int N) {
	vector<pair<int, int>> temp;
	for (int i = 0; i < K; i++) {
		for (int j = 0; j < N; j++) {
			temp.push_back(make_pair(input[i][j], i));
		}
	}
	sort(temp.begin() ,temp.end(), compare);
	int minValue = 9999999;
	int min = 0, max = 0;
	set<int> Kl;
	vector<int> pos;
	int start = 0;
	for (int i = 0; i < temp.size(); i++) {
		if (Kl.size() < K) {
			Kl.insert(temp[i].second);
			pos.push_back(temp[i].second);
		}
		if (Kl.size() == K)
		{
		here:
			int dis = temp[i].first - temp[start].first;
			if (dis < minValue) {
				minValue = dis;
				min = temp[start].first;
				max = temp[i].first;
			}
			int pre = pos[0];
			pos.erase(pos.begin());
			if (find(pos.begin(), pos.end(), pre) != pos.end()) {
				start++;
				goto here;
			}
			else {
				start++;
				Kl.erase(pre);
			}
		}
	}
	vector<int> result;
	result.push_back(min);
	result.push_back(max);
	return result;
}

int main_SmallestRange() {
	int K;
	int N;
	vector<vector<int>> input;
	cin >> K;
	cin >> N;
	for (int i = 0; i < K; i++) {
		vector<int> t;
		for (int j = 0; j < N; j++) {
			int temp;
			cin >> temp;
			t.push_back(temp);
		}
		input.push_back(t);
	}
	vector<int> result = getMinInterval(input, K, N);
	cout << result[0] << " " << result[1] << endl;
	system("pause");
	return 0;
}