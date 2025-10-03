#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <climits>

using namespace std;


int card_value(char c) {
    if (c == 'A') return 1;
    if (c >= '2' && c <= '9') return c - '0';
    if (c == 'D') return 10;
    if (c == 'Q') return 11; 
    if (c == 'J') return 12;
    if (c == 'K') return 13;
    return 0; 
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<char>> hands(n + 1); 
    for (int i = 1; i <= n; ++i) {
        string s;
        cin >> s;
        for (char c : s) {
            hands[i].push_back(c);
        }
    }

    
    char block_card = 'B'; 
    hands[k].push_back(block_card);

    
    vector<char> last_received(n + 1, '\0');
    
    vector<bool> can_pass_block(n + 1, true);
    can_pass_block[k] = false;

    
    queue<int> player_queue;
    for (int i = 0; i < n; ++i) {
        int player = ((k - 1 + i) % n) + 1;
        player_queue.push(player);
    }

    while (true) {
        int current_player = player_queue.front();
        player_queue.pop();
        player_queue.push(current_player);
        int next_player = player_queue.front();

        // Check for winning condition before current player's turn
        int winner = 0;
        int winning_card_value = INT_MAX;

        for (int i = 1; i <= n; ++i) {
            // Total number of cards including block card if present
            int total_cards = hands[i].size();
            // Exclude block card for value comparison
            vector<char> non_block_cards;
            for (char c : hands[i]) {
                if (c != block_card) {
                    non_block_cards.push_back(c);
                }
            }

            if (total_cards == 4) {
                // Since total_cards == 4, there is no block card in hand
                // Check if all cards are of the same value
                char first_card = hands[i][0];
                bool all_same = all_of(hands[i].begin(), hands[i].end(),
                                       [first_card](char c) { return c == first_card; });
                if (all_same) {
                    int c_value = card_value(first_card);
                    if (c_value < winning_card_value) {
                        winner = i;
                        winning_card_value = c_value;
                    } else if (c_value == winning_card_value && i < winner) {
                        winner = i;
                    }
                }
            }
        }
        if (winner != 0) {
            cout << winner << endl;
            break;
        }

        // Determine if the current player can pass the block card
        bool has_block_card = false;
        for (char c : hands[current_player]) {
            if (c == block_card) {
                has_block_card = true;
                break;
            }
        }
        bool can_pass_block_card = false;
        if (has_block_card && last_received[current_player] != block_card && can_pass_block[current_player]) {
            can_pass_block_card = true;
        }

        // Choose the card to pass
        char card_to_pass;
        if (can_pass_block_card) {
            // If the player can give the block card, they will surely give it
            card_to_pass = block_card;
        } else {
            // Cannot pass the block card, select the card with the lowest frequency
            unordered_map<char, int> freq;
            for (char c : hands[current_player]) {
                if (c != block_card) {
                    freq[c]++;
                }
            }
            // Find the minimum frequency
            int min_freq = INT_MAX;
            for (auto& p : freq) {
                if (p.second < min_freq) {
                    min_freq = p.second;
                }
            }
            // Collect all cards with the minimum frequency
            vector<char> candidates;
            for (auto& p : freq) {
                if (p.second == min_freq) {
                    candidates.push_back(p.first);
                }
            }
            // Choose the card with the lowest value among the candidates
            card_to_pass = candidates[0];
            for (char c : candidates) {
                if (card_value(c) < card_value(card_to_pass)) {
                    card_to_pass = c;
                }
            }
        }

        
        
        auto it = find(hands[current_player].begin(), hands[current_player].end(), card_to_pass);
        if (it != hands[current_player].end()) {
            hands[current_player].erase(it);
        }
        
        hands[next_player].push_back(card_to_pass);
        
        last_received[next_player] = card_to_pass;

        
        can_pass_block[current_player] = true;
    }

    return 0;
}
