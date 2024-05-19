#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const string CARD_ORDER = "A23456789DQJK";
const char WILDCARD = '*';

struct Player {
    map<char, int> card_count; // Keeps track of the number of each card
    vector<char> cards; // Keeps track of the actual cards
    bool has_wildcard;

    Player() : has_wildcard(false) {}

    // Add card to the player's hand
    void addCard(char card) {
        cards.push_back(card);
        if (card != WILDCARD) {
            card_count[card]++;
        } else {
            has_wildcard = true;
        }
    }

    // Remove card from the player's hand
    void removeCard(char card) {
        auto it = find(cards.begin(), cards.end(), card);
        if (it != cards.end()) {
            cards.erase(it);
            if (card != WILDCARD) {
                card_count[card]--;
            } else {
                has_wildcard = false;
            }
        }
    }

    // Check if the player is in a winning state
    bool isWinning() {
        for (const auto& entry : card_count) {
            if (entry.second == 4) return true;
        }
        return false;
    }

    // Select card to pass according to the rules
    char selectCardToPass() {
        if (has_wildcard) return WILDCARD;

        char min_card = ' ';
        int min_count = 5; // Max 4 cards of each type
        for (const auto& card : cards) {
            if (card != WILDCARD && card_count[card] < min_count) {
                min_count = card_count[card];
                min_card = card;
            } else if (card != WILDCARD && card_count[card] == min_count) {
                if (CARD_ORDER.find(card) < CARD_ORDER.find(min_card)) {
                    min_card = card;
                }
            }
        }
        return min_card;
    }
};

int main() {
    int N, K;
    cin >> N >> K;
    K--; // Convert to zero-based index

    vector<Player> players(N);

    // Read initial cards
    for (int i = 0; i < N; ++i) {
        string cards;
        cin >> cards;
        for (char card : cards) {
            players[i].addCard(card);
        }
    }

    // Initial wildcard assignment
    players[K].addCard(WILDCARD);

    int current_player = K;

    while (true) {
        Player &player = players[current_player];
        char card_to_pass = player.selectCardToPass();

        // Find the next player
        int next_player = (current_player + 1) % N;

        // Pass the card
        player.removeCard(card_to_pass);
        players[next_player].addCard(card_to_pass);

        // Check if next player wins
        if (players[next_player].isWinning()) {
            cout << next_player + 1 << endl; // Convert back to one-based index
            break;
        }

        // Move to the next player
        current_player = next_player;
    }

    return 0;
}
