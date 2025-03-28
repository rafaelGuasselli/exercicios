#include<bits/stdc++.h>
#define max(a, b) a > b ? a : b 

using namespace std;
 
struct DSU {
	vector<int> parent, size;
	void create(int n) {
		parent.resize(n);
		size.resize(n);
		for (int i = 0; i < n; i++) {
			parent[i] = i;
			size[i] = 1;
		}
	}
 
	int find(int x) {
		if (parent[x] == x) return x;
		return parent[x] = find(parent[x]);
	}
	void join(int a, int b) {
		a = find(a);
		b = find(b);
		if (a == b) return;
		if (size[a] < size[b]) swap(a, b);
		parent[b] = a;
		size[a] += size[b];
	}
};
 
struct Block {
	int rInEvenPos = 0;
	int rInOddPos = 0;
	int size = 1;

	int ideal() {
		return rInEvenPos || (size %2 == 0 && rInOddPos);
	}
};
 
typedef struct Block Block;
typedef struct DSU DSU;
 
int maxScore = 0;
int amountIdeals = 0;
int amountOfPicks = 0;

DSU dsu;
vector<int> values;
vector<Block> blocks;
map<int, vector<int>> order;
 
void mergeBlocks(int leftInd, int rightInd) {
	Block& left = blocks[dsu.find(leftInd)];
	Block& right = blocks[dsu.find(rightInd)];

	amountIdeals -= left.ideal() + right.ideal();
	amountOfPicks -= (left.size%2 + right.size%2)/2;

	if (left.size % 2 == 1) {
		swap(right.rInEvenPos, right.rInOddPos);
	}

	left.rInEvenPos = right.rInEvenPos = left.rInEvenPos || right.rInEvenPos;
	left.rInOddPos = right.rInOddPos = left.rInOddPos || right.rInOddPos;
	right.size = left.size = right.size + left.size;
 
	amountIdeals += right.ideal();
	dsu.join(leftInd, rightInd);
}
 
signed main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	
	int t; cin>>t;
	while (t--) {
		int n; cin>>n;
		int r = 0;
 
		amountOfPicks = 0;
		maxScore = 0;
		amountIdeals = 0;

		order.clear();
		blocks.clear();
		values.clear();
 
		dsu.create(n);
		blocks.resize(n);
		values.resize(n);
 
		for (int i = 0; i < n; i++) {
			cin>>values[i];
			order[-values[i]].push_back(i);
			r = max(r, values[i]);
		}
 
		for (int ind: order.begin()->second) {
			blocks[ind].rInEvenPos = 1;
			amountIdeals++;
		}

		for (pair<int, vector<int>> current: order) {
			int l = -current.first;
			for (int pos: current.second) {
				if (blocks[dsu.find(pos)].size == 1) {
					amountOfPicks++;
				}
			}

			for (int pos: current.second) {
				if (pos < n-1 && values[pos+1] >= l && dsu.find(pos) != dsu.find(pos+1)) {
					mergeBlocks(pos, pos+1);
				} 
				
				if (pos > 0 && values[pos-1] >= l && dsu.find(pos) != dsu.find(pos-1)) {
					mergeBlocks(pos-1, pos);
				}
			}
 
			int currentScore = r + l + amountOfPicks - (amountIdeals == 0);
			maxScore = max(maxScore, currentScore);
		}
 
		cout<<maxScore<<endl;
	}
 
	return 0;
}