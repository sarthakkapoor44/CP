///////////////////////////////////////////////////// DYNATOS ////////////////////////////////////////////////////
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define INF 1000000000000000000
#define pb push_back
#define mp make_pair
#define srt(vect) sort(vect.begin(), vect.end())
#define ce cout << endl
#define all(s) s.begin(), s.end()
#define pyes cout << "YES"
#define pno cout << "NO"
#define rep(i, n) for (ll i = 0; i < n; i++)
#define forf(i, a, b) for (ll i = a; i < b; i++)
#define forb(i, s, e) for (ll i = s; i >= e; i--)
#define vp vector<pair<ll, ll>>
#define vll vector<ll>
#define OPTIMIZE_IO              \
    std::ios::sync_with_stdio(false); \
    std::cin.tie(nullptr);

#ifndef ONLINE_JUDGE
#include "debug.cpp"
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif

const ll MODN = 1e9 + 7;
const ll MAXN = 1000001;
const ll modn = 998244353;

template <typename T>
void out(vector<T> a) {
    for (int i = 0; i < (int)a.size(); i++) {
        cout << a[i] << " ";
    }
    ce;
}

int main() {
    OPTIMIZE_IO // Optimize input/output (remove if using scanf and printf)

        ll n, m, k;
        cin >> n >> m >> k;
        vector<vector<ll>> grid(n, vector<ll>(m));
        ll sx, sy;
        cin >> sx >> sy;
        rep(i, n) rep(j, m) cin >> grid[i][j];
        sx--; sy--;
        // debug(grid);
       
        vector<vector<ll>> dp1(n, vector<ll>(m, -INF));
        vector<vector<ll>> dp2(n, vector<ll>(m, -INF));
        vector<vector<ll>> dp3(n, vector<ll>(m, -INF));
        vector<vector<ll>> dp4(n, vector<ll>(m, -INF));

        dp1[sx][sy] = 0;
        for (ll i = sx; i < n; i++) {
            for (ll j = sy; j < m; j++) {
                if (i > sx) dp1[i][j] = max(dp1[i][j], dp1[i-1][j] + grid[i][j]);
                if (j > sy) dp1[i][j] = max(dp1[i][j], dp1[i][j-1] + grid[i][j]);
            }
        }

        dp2[sx][sy] = 0;
        for (ll i = sx; i < n; i++) {
            for (ll j = sy; j >= 0; j--) {
                if (i > sx) dp2[i][j] = max(dp2[i][j], dp2[i-1][j] + grid[i][j]);
                if (j < sy && j+1 < m) dp2[i][j] = max(dp2[i][j], dp2[i][j+1] + grid[i][j]);
            }
        }

        dp3[sx][sy] = 0;
        for (ll i = sx; i >= 0; i--) {
            for (ll j = sy; j < m; j++) {
                if (i < sx && i+1<n) dp3[i][j] = max(dp3[i][j], dp3[i+1][j] + grid[i][j]);
                if (j > sy) dp3[i][j] = max(dp3[i][j], dp3[i][j-1] + grid[i][j]);
            }
        }

         dp4[sx][sy] = 0;
        for (ll i = sx; i >= 0; i--) {
            for (ll j = sy; j >= 0; j--) {
                if (i < sx && i+1 < n) dp4[i][j] = max(dp4[i][j], dp4[i+1][j] + grid[i][j]);
                if (j < sy && j+1 < m) dp4[i][j] = max(dp4[i][j], dp4[i][j+1] + grid[i][j]);
            }
        }
        // debug(dp1);
        ll max_ans = -INF;
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < m; j++) {
                ll moves = abs(i - sx) + abs(j - sy);
                if (k >= moves) {
                    ll remaining_moves = k - moves;
                    ll value = -INF;
                    if (i >= sx && j >= sy) {
                        value = dp1[i][j] + remaining_moves * grid[i][j];
                    } else if (i >= sx && j <= sy) {
                        value = dp2[i][j] + remaining_moves * grid[i][j];
                    } else if (i <= sx && j >= sy) {
                        value = dp3[i][j] + remaining_moves * grid[i][j];
                    } else if (i <= sx && j <= sy) {
                        value = dp4[i][j] + remaining_moves * grid[i][j];
                    }
                    max_ans = max(max_ans, value);
                }
            }
        }

       cout<<max_ans;ce;
    
    return 0;
}
