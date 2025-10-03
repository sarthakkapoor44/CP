#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// Function to compute XOR from 0 to n
ull compute_prefix_xor(ull n) {
    ull mod = n % 4;
    if (mod == 0)
        return n;
    else if (mod == 1)
        return 1;
    else if (mod == 2)
        return n + 1;
    else
        return 0;
}

// Function to compute XOR from l to r
ull compute_range_xor(ull l, ull r) {
    return compute_prefix_xor(r) ^ compute_prefix_xor(l - 1);
}

// Function to compute ceiling division
ll ceil_div(ll a, ll b) {
    if (b == 0)
        return 0; // Avoid division by zero
    ll res = a / b;
    if ((a % b != 0) && ((a > 0) == (b > 0)))
        res += 1;
    return res;
}

// Function to compute floor division
ll floor_div(ll a, ll b) {
    if (b == 0)
        return 0; // Avoid division by zero
    ll res = a / b;
    if ((a % b != 0) && ((a > 0) != (b > 0)))
        res -= 1;
    return res;
}

void solve() {
    int t;
    cin >> t;
    while (t--) {
        ull l, r;
        int i;
        ull k;
        cin >> l >> r >> i >> k;
        ull total_xor = compute_range_xor(l, r);
        ull two_i = 1ULL << i;
        ll t1 = ceil_div((ll)l - (ll)k, (ll)two_i);
        ll t2 = floor_div((ll)r - (ll)k, (ll)two_i);

        if (t1 > t2) {
            // No numbers satisfy x ≡ k mod 2^i in [l, r]
            cout << total_xor << '\n';
        } else {
            // Compute the XOR of numbers satisfying x ≡ k mod 2^i
            ull count = t2 - t1 + 1;
            ull s = compute_prefix_xor((ull)t2) ^ compute_prefix_xor((ull)(t1 - 1));
            ull xor_to_remove = (s << i);
            if (count % 2 == 1)
                xor_to_remove ^= k;
            ull answer = total_xor ^ xor_to_remove;
            cout << answer << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
