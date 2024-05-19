
#include <bits/stdc++.h>

using namespace std;

map<char, int> deck = {{'A', 1}, {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9}, {'D', 10}, {'Q', 11}, {'J', 12}, {'K', 13}};
multiset<int> hand[13];
int nPlayers, startPlayer;

int main(){
	cin>>nPlayers>>startPlayer;
	for (int i = 0; i < nPlayers; i++) {
		for (int j = 0; j < 4; j++) {
			char card; cin>>card;
			hand[i].insert(deck[card]);
		}
	}

	int currentPlayer = startPlayer-1;
	int wildCardOwner = currentPlayer;
	int canPassWild = false;

	while (true) {
		int nextPlayer = (currentPlayer+1)%nPlayers;
		for (int i = 0; i < nPlayers; i++) {
			if (hand[i].size() == 4 && i != wildCardOwner && hand[i].count(*hand[i].begin()) == 4) {
				cout<<i+1<<endl;
				return 0;
			}
		}

		if (wildCardOwner == currentPlayer && canPassWild) {
			canPassWild = false;
			wildCardOwner = nextPlayer;
			currentPlayer = nextPlayer;
			continue;
		} else if (wildCardOwner == currentPlayer) {
			canPassWild = true;
		}

		map<int, int> frequency;
		for (int card: hand[currentPlayer]) {
			frequency[card]++;
		}

		int cardToPass = -1;
		int smallestFrequency = 10;
		for (pair<int, int> freq: frequency) {
			if (freq.second < smallestFrequency) {
				cardToPass = freq.first;
				smallestFrequency = freq.second;
			}
		}

		hand[currentPlayer].erase(hand[currentPlayer].find(cardToPass));
		hand[nextPlayer].insert(cardToPass);

		currentPlayer = nextPlayer;
	}

	return 0;
}