#include<bits/stdc++.h>

using namespace std;

int nNumbers, target; 
int sign[40];
int values[40];
int sufixSum[40];
unordered_map<int, int> pathResult[40];

int path(int value, int index) {
	if (index == nNumbers) {
		return value == target;
	}

	if (abs(target-value) > sufixSum[index]) {
		return 0;
	}

	if (pathResult[index].find(value) != pathResult[index].end()) {
		return pathResult[index][value];
	}

	int sum = path(value+values[index], index+1);
	int sub = path(value-values[index], index+1);

	sign[index] = sign[index] | (sum+sub*2);
	pathResult[index][value] = sub|sum;

	return sum|sub;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	while (cin>>nNumbers>>target) {
		if (nNumbers == 0 && target == 0) {
			break;
		}

		for (int i = 0; i < nNumbers; i++) {
			cin>>values[i];
		}

		for (int i = 0; i < nNumbers; i++) {
			sign[i] = 0;
			sufixSum[i] = 0;
			pathResult[i].clear();
		}

		sufixSum[nNumbers-1] = values[nNumbers-1];
		for (int i = nNumbers-2; i >= 0; i--) {
			sufixSum[i] = sufixSum[i+1] + values[i];
		}

		int possible = path(0, 0);
		if (possible) {
			for (int i = 0; i < nNumbers; i++){
				if (sign[i] == 3) {
					cout<<"?";
				} else if (sign[i] == 1) {
					cout<<"+";
				} else {
					cout<<"-";
				}
			}
			cout<<"\n";
		} else {
			cout<<"*"<<"\n";
		}
	}

	return 0;
}