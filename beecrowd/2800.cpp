#include<bits/stdc++.h>

using namespace std;

int values[100000];
int valuesSQRT[320][100001];
int nValues, nQueries; 

int sqrtWidth;
void update(int index, int value){
	int sqrtIndex = index/sqrtWidth;

	valuesSQRT[sqrtIndex][value]++;
	valuesSQRT[sqrtIndex][values[index]]--;
	values[index] = value;
}

int read(int left, int right, int value){
	if (left > right) {
		return 0;
	}

	left = max(left, 0);
	right = min(right, nValues-1);

	int nNumbers = 0;
	int range = abs(right-left)+1;

	for (int i = left; i <= min((left/sqrtWidth + 1) * sqrtWidth, right); i++) {
		if (values[i] == value) nNumbers++;
	}

	for (int i = right; i >= max((left/sqrtWidth-1) * sqrtWidth, left); i--) {
		if (values[i] == value) nNumbers++;
	}

	left = left/sqrtWidth+1;
	right = right/sqrtWidth-1;
	for (int i = left; i <= right; i++) {
		nNumbers += valuesSQRT[i][value]; 
	}

	return abs(range-nNumbers);
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>nValues>>nQueries;
	sqrtWidth = ceil(sqrt(nValues));

	for (int i = 0; i < nValues; i++) {
		int value; cin>>value;
		update(i, value);
	}	

	for (int i = 0; i < nQueries; i++) {
		int op; cin>>op;
		if (op == 1) {
			int index, value; cin>>index>>value;
			index--;
			update(index, value);
		} else {
			int left, right, value; cin>>left>>right>>value;
			left--; right--;
			cout<<read(left, right, value)<<endl;
		}
	}

	return 0;
}