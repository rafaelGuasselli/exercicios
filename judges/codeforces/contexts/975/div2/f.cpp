#include<bits/stdc++.h>
#define max(a, b) a > b ? a : b 
#define min(a, b) a > b ? b : a 
//#define int long long
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
	int rInEvenPos, rInOddPos, size;
	int ideal() {
		return rInEvenPos || (size %2 == 0 && rInOddPos);
	}
	int maxPicks(){
		return ceil(double(size)/double(2));
	}
};
 
typedef struct Block Block;
typedef struct DSU DSU;
 
 
int amountIdeals = 0;
map<int, vector<int>> order;
vector<Block> blocks;
vector<int> values;
DSU dsu;
 
void mergeBlocks(Block& left, Block& right) {
	if (left.ideal()) {
		amountIdeals--;
	}

	if (right.ideal()) {
		amountIdeals--;
	}

	if (left.size % 2 == 1) {
		swap(right.rInEvenPos, right.rInOddPos);
	}

	left.rInEvenPos = right.rInEvenPos = left.rInEvenPos || right.rInEvenPos;
	left.rInOddPos = right.rInOddPos = left.rInOddPos || right.rInOddPos;
	right.size = left.size = right.size + left.size;
 
	if (right.ideal()) {
		amountIdeals++;
	}
}
 
signed main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	
	int t; cin>>t;
	while (t--) {
		int n; cin>>n;
		int r = 0;
 
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
 
		for (int i = 0; i < n; i++) {
			blocks[i].rInEvenPos = 0;
			blocks[i].rInOddPos = 0;
			blocks[i].size = 1;
 
			if (values[i] == r) {
				blocks[i].rInEvenPos = 1;
				amountIdeals++;
			}
		}
 
		int size = 0;
		int count = 0;
		int maxScore = 0;
 
		for (pair<int, vector<int>> current: order) {
			int l = -current.first;

			for (int pos: current.second) {
				if (blocks[dsu.find(pos)].size == 1) {
					size++;
				}
			}

			for (int pos: current.second) {
				if (pos < n-1 && values[pos+1] >= l && dsu.find(pos) != dsu.find(pos+1)) {
					Block& middle = blocks[dsu.find(pos)];
					Block& right = blocks[dsu.find(pos+1)];

					size -= middle.maxPicks() + right.maxPicks();
					
					mergeBlocks(middle, right);
					dsu.join(pos, pos+1);
					
					middle = blocks[dsu.find(pos)];
					size += middle.maxPicks();
				} 
				
				if (pos > 0 && values[pos-1] >= l && dsu.find(pos) != dsu.find(pos-1)) {
					Block& left = blocks[dsu.find(pos-1)];
					Block& middle = blocks[dsu.find(pos)];
					size -= middle.maxPicks() + left.maxPicks();
 
					mergeBlocks(left, middle);
					dsu.join(pos, pos-1);
					
					middle = blocks[dsu.find(pos)];
					size += middle.maxPicks();
				}
			}
 
			int currentScore = r + l + size - (amountIdeals == 0);
			maxScore = max(maxScore, currentScore);
		}
 
		cout<<maxScore<<endl;
	}
 
	return 0;
}