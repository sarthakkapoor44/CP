#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#ifdef ONLINE_JUDGE
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#endif
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
//  using namespace __gnu_pbds;
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
#define pll pair<ll, ll>
#define OPTIMIZE_IO                   \
    std::ios::sync_with_stdio(false); \
    std::cin.tie(nullptr);            \
    std::cout.tie(nullptr);
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//    tree_order_statistics_node_update> ost;

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
void out(vector<T> a)
{
    for (int i = 0; i < (int)a.size(); i++)
    {
        cout << a[i] << " ";
    }
    ce;
}

int main()
{
    // FOR GCD - gcd snip
    // FOR SIEVE OF ERATOSTHENES - erat_snip;fast_sieve
    // FOR SPF - spf_snip
    // FOR BINARY_EXPONENTATION - binpow_snip
    // FOR SEGMENT_TREE - seg_snip
    // FOR LCA - lca_snip
    OPTIMIZE_IO // Optimize input/output (remove if using scanf and printf)
    {           // Lesgooooooo!!!!
        ll n;
        cin >> n;
        vector<ll> arr(n);
        rep(i, n) cin >> arr[i];
        const ll mx = 5005;
        vector<ll> dp(mx), prefix(mx);
        srt(arr);
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < i; j++)
            {
                dp[arr[i] - arr[j]]++;
            }
        }
        for (ll i = 0; i < mx; i++)
        {
            prefix[i] = (i - 1 >= 0 ? prefix[i - 1] : 0) + dp[i];
        }
        // debug(dp,prefix);
        ll ans = 0;
        for (ll i = 0; i < mx; i++)
        {
            for (ll j = 0; j < i; j++)
            {
                ll diff = i - j;
                ans += dp[i] * dp[j] * prefix[diff - 1];
            }
        }
        ll denom = (n * (n - 1)) / 2;
        long double fin = (long double)ans;
        rep(i, 3)
        {
            fin = (long double)fin / denom;
        }
        cout << fixed << setprecision(7) << fin;
    }

    return 0;
}
