#include <bits/stdc++.h>
#define ll long long

using namespace std;


int main() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> queue;

	queue.push({1, 0});
	queue.push({1, 3});
	queue.push({0, 4});
	
	while (queue.size() > 0) {
		cout<<queue.top().second<<endl;queue.pop();
	}

	return 0;
}