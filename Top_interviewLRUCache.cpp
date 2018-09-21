#include<iostream>
#include<map>
#include<list>
using namespace std;

class LRUCache {
public:
	LRUCache(int capacity) {
		capacityLRU = capacity;
	}

	int get(int key) {
		if (cache.find(key) != cache.end()) {
			l.erase(find(l.begin(), l.end(), key));
			l.push_back(key);
			return cache[key];
		}
		else
		{
			return -1;
		}
	}

	void put(int key, int value) {
		if (cache.size() < capacityLRU) {
			if (cache.find(key) != cache.end()) {
				cache[key] = value;
				l.erase(find(l.begin(), l.end(), key));
				l.push_back(key);
			}
			else {
				cache.insert(make_pair(key, value));
				l.push_back(key);
			}
		}
		else
		{
			if (cache.find(key) != cache.end()) {
				cache[key] = value;
				l.erase(find(l.begin(), l.end(), key));
				l.push_back(key);
			}
			else
			{
				cache.erase(*l.begin());
				l.pop_front();
				cache.insert(make_pair(key, value));
				l.push_back(key);
			}
		}
	}

private:
	int capacityLRU;
	map<int, int> cache;
	list<int> l;
};

int main_LRUCache() {
	LRUCache obj(2);
	obj.put(1, 1);
	obj.put(2, 2);
	int get1 = obj.get(1);
	cout << get1 << endl;
	obj.put(3, 3);
	int get2 = obj.get(2);
	cout << get2 << endl;
	obj.put(4, 4);
	int get3 = obj.get(1);
	cout << get3 << endl;
	int get4 = obj.get(3);
	cout << get4 << endl;
	int get5 = obj.get(4);
	cout << get5 << endl;
	system("pause");
	return 0;
}