#include <bits/stdc++.h>
#define ll long long

using namespace std;
int segment[1000000];
int original[1000000];

void update(int currentPos, int left, int right, int pos, int newValue) {
    if (left == right) {
        segment[currentPos] = newValue != 0 ? newValue/abs(newValue) : 0;
    } else {
        int middle = (left + right)/2;
        if (pos <= middle) {
            update(currentPos*2, left, middle, pos, newValue);
		} else {
			update(currentPos*2+1, middle+1, right, pos, newValue);
		}

		segment[currentPos] = segment[currentPos*2] * segment[currentPos*2+1];
    }
}

int prod(int currentPos, int left, int right, int targetLeft, int targetRight) {
    if (targetLeft > targetRight){
		return 1;
	}
    
	if (left == targetLeft && right == targetRight) {
        return segment[currentPos];
    }

    int middle = (left + right)/2;
    return prod(currentPos*2,    left,      middle,  targetLeft,                 min(targetRight, middle)) *
		   prod(currentPos*2+1,  middle+1,  right,   max(targetLeft, middle+1),  targetRight);
}

void build(int original[], int currentPos, int left, int right) {
    if (left == right) {
        segment[currentPos] = original[currentPos] != 0 ? original[currentPos]/abs(original[currentPos]) : 0;
    } else {
        int middle = (left + right)/2;
        build(original, currentPos*2, left, middle);
        build(original, currentPos*2+1, middle+1, right);
        segment[currentPos] = segment[currentPos*2] * segment[currentPos*2+1];
    }
}

int main() {
	int size, nOperations; cin>>size>>nOperations;
	for (int i = 0; i < size; i++) {
		cin>>original[i];
	}
	
	build(original, 0, 0, size-1);
	for (int i = 0; i < nOperations; i++) {
		char operation; int pos, value; 
		cin>>operation>>pos>>value;
		
		int posInit = pos-1;
		int posFim = value-1;

		if (operation == 'C') {
			update(0, 0, size-1, pos-1, value);
		} else {
			cout<<"P - "<<posInit<<" "<<posFim<<endl;
			int value = prod(0, 0, size-1, posInit, posFim);
			if (value > 0) {
				cout<<"+";
			} else if (value < 0) {
				cout<<"-";
			} else {
				cout<<0;
			}
		}
	}

	return 0;
}