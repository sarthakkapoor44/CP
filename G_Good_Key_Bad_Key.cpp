#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i, n) for (ll i = 0; i < n; i++)
#define forf(i, a, b) for (ll i = a; i < b; i++)
#define forb(i, s, e) for (ll i = s; i >= e; i--)

const ll MODN = 1e9 + 7;
const ll INF = 1e15;  // Set to a large value, but ensure it's less than the minimum possible dp value.
const int MAX_SHIFT = 31; // Since you're shifting up to 64 bits.

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        vector<ll> arr(n + 1, 0);
        forf(i, 1, n + 1) {
            cin >> arr[i];
        }

        // dp[i][j] represents the maximum value accumulated till ith position with j right shifts
        vector<vector<ll> > dp(n + 1, vector<ll>(MAX_SHIFT + 1, -INF));
        dp[0][0] = 0;

        forf(i, 1, n + 1) {
            rep(j, MAX_SHIFT + 1) {
                ll num = arr[i] >> j;
                if (dp[i - 1][j] != -INF) {
                    dp[i][j] = max(dp[i][j],dp[i - 1][j] - k + num);
                }
                if (j > 0 && dp[i - 1][j - 1] != -INF) {
                    ll num2 = arr[i]>>(j-1);
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + num);
                }
            }
        }

        ll val = 0;
        rep(j, MAX_SHIFT + 1) {
            val = max(val, dp[n][j]);
        }

        cout << val << '\n'; // Use '\n' for faster output rather than endl which flushes the buffer.
    }
    return 0;
}
