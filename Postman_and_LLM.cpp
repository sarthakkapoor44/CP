#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>

using namespace std;

long long power(long long base, long long exp) {
    long long res = 1;
    base %= 998244353;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % 998244353;
        base = (base * base) % 998244353;
        exp /= 2;
    }
    return res;
}

long long inverse(long long n) {
    return power(n, 998244353 - 2);
}

long long nCr_mod_p(int n, int r, const vector<long long>& fact, const vector<long long>& invFact) {
    if (r < 0 || r > n) return 0;
    return (((fact[n] * invFact[r]) % 998244353) * invFact[n - r]) % 998244353;
}

int main() {
    int t;
    cin >> t;
    vector<long long> fact(200001);
    vector<long long> invFact(200001);
    fact[0] = 1;
    invFact[0] = 1;
    for (int i = 1; i <= 200000; ++i) {
        fact[i] = (fact[i - 1] * i) % 998244353;
        invFact[i] = inverse(fact[i]);
    }

    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> d(n);
        for (int i = 0; i < n; ++i) {
            cin >> d[i];
        }
        vector<int> sorted_d = d;
        sort(sorted_d.begin(), sorted_d.end());

        long long min_sum = -1;
        long long min_sum_count = 0;

        for (int i = 0; i <= n - m; ++i) {
            vector<int> h;
            for (int j = 0; j < m; ++j) {
                h.push_back(sorted_d[i + j]);
            }
            long long current_sum = 0;
            for (int j = 0; j < m; ++j) {
                current_sum += (long long)(2 * (j + 1) - m - 1) * h[j];
            }

            if (min_sum == -1 || current_sum < min_sum) {
                min_sum = current_sum;
                min_sum_count = 0;
            }
            if (current_sum == min_sum) {
                min_sum_count++;
            }
        }

        long long assignment_count_total = 0;
        for (int i = 0; i <= n - m; ++i) {
            vector<int> h;
            for (int j = 0; j < m; ++j) {
                h.push_back(sorted_d[i + j]);
            }
            long long current_sum = 0;
            for (int j = 0; j < m; ++j) {
                current_sum += (long long)(2 * (j + 1) - m - 1) * h[j];
            }

            if (current_sum == min_sum) {
                map<int, int> chosen_counts;
                for (int val : h) {
                    chosen_counts[val]++;
                }
                map<int, int> original_counts;
                for (int val : d) {
                    original_counts[val]++;
                }
                long long current_assignment_count = 1;
                for (auto const& [val, count] : chosen_counts) {
                    current_assignment_count = (current_assignment_count * nCr_mod_p(original_counts[val], count, fact, invFact)) % 998244353;
                }
                assignment_count_total = (assignment_count_total + current_assignment_count) % 998244353;
            }
        }

        cout << (2 * min_sum) % 998244353 << " " << assignment_count_total << endl;
    }
    return 0;
}