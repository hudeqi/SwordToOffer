#include<iostream>
#include<vector>
#include<set>
using namespace std;

bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
	if (numCourses <= 1 || prerequisites.size() <= 1)
		return true;
	vector<set<int>> pre(numCourses);
	for (int i = 0; i < prerequisites.size(); i++) {
		if (prerequisites[i].second < numCourses) {
			pre[prerequisites[i].first].insert(prerequisites[i].second);
		}
		else {
			return false;
		}
	}
	int count = 0;
	while (count < numCourses)
	{
		bool flag = false;
		int indegreeZero = 0;
		for (int i = 0; i < pre.size(); i++) {
			if (pre[i].size() == 0) {
				flag = true;
				pre[i].insert(-1);
				indegreeZero = i;
				count++;
				break;
			}
		}
		if (!flag)
			return false;
		else
		{
			for (int i = 0; i < pre.size(); i++) {
				if (pre[i].size() > 0 && (pre[i].find(-1) == pre[i].end())) {
					if (pre[i].find(indegreeZero) != pre[i].end()) {
						pre[i].erase(indegreeZero);
					}
				}
			}
		}
	}
	return true;
}

int main_CourseSchedule() {
	int num = 3;
	vector<pair<int, int>> c;
	c.push_back(make_pair(1, 0));
	c.push_back(make_pair(2, 0));
	cout << canFinish(num, c) << endl;
	system("pause");
	return 0;
}