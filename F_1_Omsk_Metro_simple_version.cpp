#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#ifdef ONLINE_JUDGE
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#endif
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
typedef long long ll;
#define fi first
#define se second
#define INF 1000000000000000000LL
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
#define OPTIMIZE_IO                                                                 \
    std::ios::sync_with_stdio(false);                                               \
    std::cin.tie(nullptr);
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
    // FOR SIEVE OF ERATOSTHENES - erat_snip;
    // FOR SPF - spf_snip
    // FOR BINARY_EXPONENTATION - binpow_snip
    // FOR SEGMENT_TREE - seg_snip
    OPTIMIZE_IO // Optimize input/output (remove if using scanf and printf)

    int t;
    cin >> t;
    while (t--)
    { // Lesgooooooo!!!!
        ll n;
        cin >> n;
        if (n == 0)
            break;
        ll nodes = 1;
        vll arr(2 * n + 5);           
        arr[0] = 1;
        vector<vector<ll>> adj(2 * n + 5); 
        vp query;
        rep(i, n)
        {
            char type;
            cin >> type;
            if (type == '+')
            {
                ll u, val;
                cin >> u >> val;
                u--;
                arr[nodes] = val;
                adj[u].pb(nodes);
                adj[nodes].pb(u);
                nodes++;
            }
            else
            {
                ll a, b, c;
                cin >> a >> b >> c;
                b--;
                query.pb({b, c});
               
            }
        }

        vp range(2 * n + 5, {INF, -INF}); 
        function<void(ll, ll, ll, ll, ll, ll)> dfs = [&](ll pos, ll par, ll sum, ll best_sum, ll sum2, ll min_sum) -> void {
            sum = max(sum + arr[pos], arr[pos]);
            sum2 = min(sum2 + arr[pos], arr[pos]);
            min_sum = min(min_sum, sum2);
            best_sum = max(best_sum, sum);
            range[pos] = {min_sum, best_sum};
            for (auto x : adj[pos])
            {
                if (x == par)
                    continue;
                dfs(x, pos, sum, best_sum, sum2, min_sum);
            }
        };
        dfs(0, -1, 0, -INF, 0, INF);
        // range[0].fi = 0;
        for (auto x : query)
        {
            if (x.fi < nodes &&( (range[x.fi].fi <= x.se && range[x.fi].se >= x.se )|| x.se==0) )
                pyes;
            else
                pno;
            ce;
        }
       
    }

    return 0;
}
