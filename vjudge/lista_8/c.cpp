#include<bits/stdc++.h>
using namespace std;

int startNumber, targetNumber, nButtons;
int minDistance[10000];

int main() {
	int testNumber = 1;
	while (1) {
		cin>>startNumber>>targetNumber>>nButtons;
		
		if (startNumber == 0 && targetNumber == 0 && nButtons == 0) {
			break;
		}
		
		vector<int> buttons;
		for (int i = 0; i < nButtons; i++) {
			int button; cin>>button;
			buttons.push_back(button);
		}

		queue<pair<int, int>> q;
		for (int i = 0; i < 10000; i++) {
			minDistance[i] = -1;
		}

		q.push({0, startNumber});
		minDistance[startNumber] = 0;

		while (!q.empty()) {
			pair<int, int> current = q.front(); q.pop();
			int distance = current.first;
			int number = current.second;

			for (int button: buttons) {
				int nextNumber = (number + button) % 10000;

				if (distance+1 < minDistance[nextNumber] || minDistance[nextNumber] == -1) {
					minDistance[nextNumber] = distance+1;
					q.push({distance+1, nextNumber});
				}
			}
		}

		cout<<"Case "<<testNumber++<<": ";
		if (minDistance[targetNumber] == -1) {
			cout<<"Permanently Locked"<<endl;
		} else {
			cout<<minDistance[targetNumber]<<endl;
		}
	}

	return 0;
}