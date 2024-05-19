#include <bits/stdc++.h>

using namespace std;

// Deck mapping for card values
map<char, int> deck = {{'A', 1}, {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9}, {'D', 10}, {'Q', 11}, {'J', 12}, {'K', 13}};

// Function to find the card to pass
char findCardToPass(multiset<int>& hand) {
	map<int, int> frequency;
	for (int card : hand) {
		frequency[card]++;
	}

	int minFreq = 5;
	int cardToPass = 0;
	for (const auto& entry : frequency) {
		if (entry.second < minFreq) {
			minFreq = entry.second;
			cardToPass = entry.first;
		}
	}

	return cardToPass;
}

int main() {
	int nPlayers, startPlayer;
	cin>>nPlayers>>startPlayer;
	
	vector<multiset<int>> hands(nPlayers);
	int wildcardOwner = startPlayer - 1;
	
	for (int i = 0; i < nPlayers; i++) {
		for (int j = 0; j < 4; j++) {
			char card;
			cin >> card;
			hands[i].insert(deck[card]);
		}
	}
	
	int currentPlayer = wildcardOwner;
	bool wildcardPassed = false;
	
	while (true) {
		int nextPlayer = (currentPlayer + 1) % nPlayers;
		
		for (int i = 0; i < nPlayers; i++) {
			if (hands[i].size() == 4 && wildcardOwner != i && hands[i].count(*hands[i].begin()) == 4) {
				cout<<i+1<<endl;
				return 0;
			}
		}
		
		if (wildcardOwner == currentPlayer && !wildcardPassed) {
			wildcardPassed = true;

			int cardToPass = findCardToPass(hands[currentPlayer]);
			hands[currentPlayer].erase(hands[currentPlayer].find(cardToPass));
			hands[nextPlayer].insert(cardToPass);
		} else if (wildcardOwner == currentPlayer){
			wildcardOwner = nextPlayer;
			wildcardPassed = false;
		} else {
			int cardToPass = findCardToPass(hands[currentPlayer]);
			hands[currentPlayer].erase(hands[currentPlayer].find(cardToPass));
			hands[nextPlayer].insert(cardToPass);
		}
		
		currentPlayer = nextPlayer;
	}
	
	return 0;
}