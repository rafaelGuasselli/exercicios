	#include <bits/stdc++.h>
	using namespace std;

	#define rep(i, a, b) for(int i = a; i < (b); ++i)
	#define all(x) begin(x), end(x)
	#define sz(x) (int)(x).size()
	typedef long long ll;
	typedef pair<int, int> pii;
	typedef vector<int> vi;
	map<vi, int> memo;

	int n; 
	vi solution;
	set<int> removePosition;
	vi temp = {1,2,3,1,2,3};

	int big(vi positions){
		vi t(n+1);
		int biggest = 0;
		for (int i: positions) {
			t[temp[i]]++;
			if (t[temp[i]] >= 2) {
				biggest = max(biggest, temp[i]);
			}
		}
		return biggest;
	} 

	int biggestValueOnIndexes(vi positions) {
		vi search;
		for (int i: positions) {
			if (removePosition.find(i) == removePosition.end()) {
				search.push_back(i);
			}
		}

		if (search.size() <= 1) {
			return 0;
		}

		if (memo.find(positions) != memo.end()) {
			return memo[positions];
		}	

		stringstream output;
		output<<"? "<<search.size()<<" ";
		for (int i: search) {
			output<<i+1<<" ";
		}

		cout<<output.str()<<endl;
		cout.flush();

		//int biggest; cin>>biggest;
		int biggest = big(search);
		memo[search] = biggest;
		return biggest;
	}

	void printSolution() {
		stringstream output;
		output<<"! ";
		for (int i: solution) {
			output<<i<<" ";
		}

		cout<<output.str()<<endl;
		cout.flush();
	}

	vi generateRangeInclusive(int l, int r) {
		vi result;
		for (int i = l; i <= r; i++) {
			result.push_back(i);
		}
		return result;
	}

	pair<int, int> findTheSplit(int val) {
		int l = 0;
		int r = 2*n-1;
		int m = l+(r-l)/2;
		
		while (1) {
			vi left = generateRangeInclusive(l, m);
			vi right = generateRangeInclusive(m+1, r);

			int lRes = biggestValueOnIndexes(left);
			if (lRes == val) {
				r = m;
				m = l+(r-l)/2;
				continue;
			}

			int rRes = biggestValueOnIndexes(right);
			if (lRes != val && rRes != val) {
				return {l, r};
			} else {
				l = m+1;
				m = l+(r-l)/2;
			}
		}
	}

	int findTheIndex(int val, int l0, int r0, vi half) {
		int r  = r0;
		int l = l0;
		int m = l+(r-l)/2;
		
		while (1) {
			if (l == r) {
				return l;
			}

			// cout<<"index: "<<l<<" "<<r<<endl;
			vi left = generateRangeInclusive(l, m);
			for (int i: half) {
				left.push_back(i);
			}

			int lRes = biggestValueOnIndexes(left);
			if (lRes == val) {
				r = m;
				m = l+(r-l)/2;
			} else {
				l = m+1;
				m = l+(r-l)/2;
			}
		}
	}

	// 1 2 3 4 5 6
	// 1 2 3 1 2 3
	void solve(int val) {
		auto [l, r]= findTheSplit(val);
		int m = l+(r-l)/2;

		// cout<<"split: "<<l<<" "<<r<<endl;
		int i1 = findTheIndex(val, l, m, generateRangeInclusive(m+1, r));
		int i2 = findTheIndex(val, m+1, r, {i1});

		solution[i1] = val;
		solution[i2] = val;

		removePosition.insert(i1);
		removePosition.insert(i2);
	}		


	//2 2 1 1
	signed main() {
		cout.tie(0);
		cin.tie(0)->sync_with_stdio(0);
		cin.exceptions(cin.failbit);

		int t; cin>>t;
		while (t--) {
			cin>>n;
			solution.clear();
			solution.assign(2*n, 0);
			removePosition.clear();
			memo.clear();
			for (int i = n; i >= 1; i--) {
				solve(i);
			}

			printSolution();
		}
	}