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

	while (left % (int)sqrtWidth != 0 && left <= right) {
		if (values[left] == value) nNumbers++;
		left++;
	}

	while ((right+1) % (int)sqrtWidth != 0 && right >= left) {
		if (values[right] == value) nNumbers++;
		right--;
	}

	
	left = left/sqrtWidth;
	right = (right+1)/sqrtWidth;
	while (left < right) {
		nNumbers += valuesSQRT[left++][value];
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