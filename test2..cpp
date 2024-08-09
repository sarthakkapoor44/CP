#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

const long long MOD = 1e9 + 7;
const int BASE = 31;

vector<int> break_string(int T, vector<string> &test_cases) {
    vector<int> results;

    for (const string &S : test_cases) {
        int n = S.length();
        vector<long long> prefix_hash(n + 1, 0);
        vector<long long> suffix_hash(n + 1, 0);
        vector<long long> power(n + 1, 1);

        // Precompute powers of the base
        for (int i = 1; i <= n; ++i) {
            power[i] = (power[i - 1] * BASE) % MOD;
        }

        // Compute prefix hashes
        for (int i = 0; i < n; ++i) {
            prefix_hash[i + 1] = (prefix_hash[i] * BASE + (S[i] - 'a' + 1)) % MOD;
        }

        // Compute suffix hashes
        for (int i = n - 1; i >= 0; --i) {
            suffix_hash[i] = (suffix_hash[i + 1] * BASE + (S[i] - 'a' + 1)) % MOD;
        }

        int ways = 0;

        // Check all possible split points
        for (int i = 0; i <= n; ++i) {
            // Check if the prefix can be divided into two equal parts
            bool valid_prefix = false;
            if (i % 2 == 0) {
                int mid = i / 2;
                long long left_prefix_hash = prefix_hash[mid];
                long long right_prefix_hash = (prefix_hash[i] - (prefix_hash[mid] * power[mid] % MOD) + MOD) % MOD;
                if (left_prefix_hash == right_prefix_hash) {
                    valid_prefix = true;
                }
            } else if (i == 0) {
                valid_prefix = true; // Empty prefix
            }

            // Check if the suffix can be divided into two equal parts
            bool valid_suffix = false;
            int remaining_length = n - i;
            if (remaining_length % 2 == 0) {
                int suffix_mid = i + remaining_length / 2;
                long long left_suffix_hash = (suffix_hash[i] - (suffix_hash[suffix_mid] * power[remaining_length / 2] % MOD) + MOD) % MOD;
                long long right_suffix_hash = suffix_hash[suffix_mid];
                if (left_suffix_hash == right_suffix_hash) {
                    valid_suffix = true;
                }
            } else if (remaining_length == 0) {
                valid_suffix = true; // Empty suffix
            }

            if (valid_prefix && valid_suffix) {
                ways++;
            }
        }

        results.push_back(ways % MOD);
    }

    return results;
}

int main() {
    int T;
    cin >> T;
    vector<string> test_cases(T);

    for (int i = 0; i < T; ++i) {
        cin >> test_cases[i];
    }

    vector<int> results = break_string(T, test_cases);

    for (int result : results) {
        cout << result << endl;
    }

    return 0;
}
