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
        ll n, m;
        cin >> n >> m;
        vector<vector<ll>> row(n), col(m);
        vector<string> grid(n);
        rep(i, n)
        {
            cin >> grid[i];
        }
        rep(i, n)
        {
            rep(j, m)
            {
                if (grid[i][j] == '#')
                {
                    row[i].pb(j);
                    col[j].pb(i);
                }
            }
        }
        vector<vector<ll>> dist(n, vector<ll>(m, INF));
        queue<vector<ll>> q;
        for (int i = 0; i < m; i++)
        {
            if (grid[n - 1][i] == '#')
            {
                dist[n - 1][i] = 1;
                q.push({n - 1, i, 0});
            }
        }
        while (!q.empty())
        {
            vector<ll> top = q.front();
            q.pop();
            if (top[2] == 0)
            {
                for (auto x : col[top[1]])
                {
                    // debug(top,x,dist[top[0]][top[1]]);
                    dist[x][top[1]] = dist[top[0]][top[1]] + 1;
                    q.push({x, top[1], 1 - top[2]});
                }
                col.erase(top[1]);
                row[top[0]].erase(top[1]);
            }
            else
            {
                for (auto x : row[top[0]])
                {
                    // debug(top,x,dist[top[0]][top[1]]);
                    dist[top[0]][x] = dist[top[0]][top[1]] + 1;
                    q.push({top[0], x, 1 - top[2]});
                }
                row.erase(top[0]);
                col[top[1]].erase(top[0]);
            }
        }
        ll ans = INF;
        rep(i,m){ans = min(ans,dist[0][i]);}
        cout<<(ans<INF?ans:-1);
        // debug(dist);
    }

    return 0;
}
