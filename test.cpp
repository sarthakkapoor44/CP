#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

const int MOD = 1000000007;

// Function to check if James wins
bool jamesWins(char james, char lily) {
    return (james == 'R' && lily == 'S') ||
           (james == 'P' && lily == 'R') ||
           (james == 'S' && lily == 'P');
}

// Memoization map to store the results of subproblems
unordered_map<string, int> memo;

// Function to generate sequences and count the number of winning sequences
int generateSequences(const string& lily, int index, char lastSign, string& current) {
    if (index == lily.size()) {
        int jamesScore = 0;
        int lilyScore = 0;
        for (int i = 0; i < lily.size(); ++i) {
            if (jamesWins(current[i], lily[i])) {
                jamesScore++;
            } else if (jamesWins(lily[i], current[i])) {
                lilyScore++;
            }
        }
        return (jamesScore > lilyScore) ? 1 : 0;
    }
    
    string memoKey = to_string(index) + lastSign + current;
    if (memo.find(memoKey) != memo.end()) {
        return memo[memoKey];
    }

    int count = 0;
    for (char sign : {'R', 'P', 'S'}) {
        if (sign != lastSign) {
            current.push_back(sign);
            count = (count + generateSequences(lily, index + 1, sign, current)) % MOD;
            current.pop_back();
        }
    }
    
    memo[memoKey] = count;
    return count;
}

int count_winning_sequences(int N, const string &input2) {
    string current;
    return generateSequences(input2, 0, '\0', current);
}

int main() {
    int N;
    string input2;

    // Example usage
    N = 3;
    input2 = "RPS";
    cout << count_winning_sequences(N, input2) << endl;  // Output should be 4
    
    N = 2;
    input2 = "RR";
    cout << count_winning_sequences(N, input2) << endl;  // Output should be 2
    
    return 0;
}
