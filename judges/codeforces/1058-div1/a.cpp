#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


#ifdef DEBUG
#define dcout cerr
#else
struct NullBuffer : std::streambuf {
	int overflow(int c) override { return c; }
} null_buffer;
ostream dcout(&null_buffer);
#endif

int n; 
vi solution;
bitset<100000> mark;
vi temp = {1,2,1,2};
vector<pair<int, int>> ind;


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

int biggestValueOnIndexes(vi search) {
	if (search.size() <= 1) {
		return 0;
	}

	stringstream output;
	output<<"? "<<search.size()<<" ";
	for (int i: search) {
		output<<i+1<<" ";
	}

	cout<<output.str()<<endl;
	cout.flush();



	int biggest;
#ifdef DEBUG
	biggest = big(search);
#else
	cin>>biggest;
#endif
	
	dcout<<"result: "<<biggest<<endl;	
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

void printSolutionDebug() {
	stringstream output;
	output<<"! ";
	for (int i: solution) {
		output<<i<<" ";
	}

	dcout<<output.str()<<endl;
	dcout.flush();
}

signed main() {
	cout.tie(0);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
		
	int t; cin>>t;
	while (t--) {
		cin>>n;
		solution.clear();
		solution.assign(2*n, 0);
		
		mark.reset();
		ind.clear();
		ind.assign(n+1, {});
		
		vi current = {0, 1};
		while (current[1] < 2*n) {
			int biggest = biggestValueOnIndexes(current); 
			
			if (biggest == 0) {
				break;
			} else {
				ind[biggest].first = current[0];
				ind[biggest].second = current[1];
				solution[current[0]] = biggest;
				solution[current[1]] = biggest;
				mark.set(current[0]);
				mark.set(current[1]);
				current = {current[0]+2, current[1]+2};
			}	
		}

		for (int i = current[1]+1; i < 2*n; i++) {
			current.push_back(i);
			int biggest = biggestValueOnIndexes(current);
			if (biggest != 0) {
				ind[biggest].first = i;
				solution[i] = biggest;

				mark.set(i);
				current.pop_back();
			}
		}

		current.clear();
		for (int i = 1; i <= n; i++) {
			if (ind[i].second == 0) {
				current.push_back(ind[i].first);
			}
		}

		for (int i = 0; i < 2*n; i++) {
			if (mark.test(i)) {
				continue;
			}

			current.push_back(i);
			int biggest = biggestValueOnIndexes(current);
			if (biggest != 0) {
				ind[biggest].second = i;
				solution[i] = biggest;
				current.pop_back();
			}
		}

		printSolution();
	}
}
