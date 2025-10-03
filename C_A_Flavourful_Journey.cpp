///////////////////////////////////////////////////// DYNATOS ////////////////////////////////////////////////////
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
// const ll MAXN = 1000001;
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

const ll MAXN = 1E5 + 5;
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
        vector<ll> col(n), val(n);
        rep(i, n) cin >> col[i];
        rep(i, n) cin >> val[i];
        map<ll, vector<ll>> vect;
        rep(i, n)
        {
            vect[col[i]].pb(val[i]);
        }

        for (auto x : vect)
        {
            srt(x.se);
        }

        vector<vector<pair<ll, ll>>> len(n + 1);
        for (auto x : vect)
        {
            if (x.se.size())
            {
                srt(x.se);
                ll s = 0;
                for (int j = x.se.size() - 1; j >= 0; j--)
                {
                    s += x.se[j];
                    len[x.se.size() - j].pb({s, x.fi});
                }
            }
        }

        forf(i, 1, n + 1) srt(len[i]);
        ll ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ll temp = 0;
            if (len[i].size() == 0)
                continue;
            if (i - 1 >= 0)
            {
                if (len[i - 1].size() && len[i - 1].back().se != len[i].back().se)
                    temp = max(temp, len[i].back().fi + len[i - 1].back().fi);
                if (len[i - 1].size())
                    len[i - 1].pop_back();
                if (len[i - 1].size() && len[i - 1].back().se != len[i].back().se)
                    temp = max(temp, len[i].back().fi + len[i - 1].back().fi);
            }
            if (len[i].size() >= 2)
            {
                temp = max(temp, len[i][len[i].size() - 1].fi + len[i][len[i].size() - 2].fi);
            }
            if (i + 1 <= n)
            {
                if (len[i].size() >= 2 && len[i + 1].size())
                {
                    if (len[i][len[i].size() - 2].se != len[i + 1].back().se)
                    {
                        temp = max(temp, len[i][len[i].size() - 2].fi + len[i + 1].back().fi);
                    }
                }
            }
            ans = max(temp, ans);
        }
        cout << ans;
        ce;
    }

    return 0;
}
