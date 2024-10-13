#include<bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int nTests; cin>>nTests;

	for (int t = 0; t < nTests; t++) {
		int lines, columns; cin>>lines>>columns;
		int smallest_x = 1e9;
		int biggest_x = 0;
		int smallest_y = 1e9;
		int biggest_y = 0;


		for (int i = 0; i < lines; i++) {
			for (int j = 0; j < columns; j++) {
				char val; cin>>val;
				if (val == '#') {
					smallest_x = min(smallest_x, j+1);
					biggest_x = max(biggest_x, j+1);
					smallest_y = min(smallest_y, i+1);
					biggest_y = max(biggest_y, i+1);
				}
			}
		}

		cout<<(biggest_y-smallest_y)/2 + smallest_y<<" "<<(biggest_x-smallest_x)/2 + smallest_x<<endl;
	}

	return 0;
}