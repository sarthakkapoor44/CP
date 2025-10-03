///////////////////////////////////////////////////// DYNATOS ////////////////////////////////////////////////////
#include<bits/stdc++.h>
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
#define INF 1000000000000000000
#define pb push_back
#define mp make_pair
#define srt(vect) sort(vect.begin(), vect.end())
#define ce cout<<endl
#define all(s) s.begin(), s.end()
#define pyes cout<<"YES"
#define pno cout<<"NO"
#define rep(i, n) for (ll i = 0; i < n; i++)
#define forf(i, a, b) for (ll i = a; i < b; i++)
#define forb(i, s, e) for (ll i = s; i >= e; i--)
#define vp vector<pair<ll, ll> >
#define vll vector<ll>
#define OPTIMIZE_IO  std::ios::sync_with_stdio(false);\
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
 


class DSU {
public:
    vector<ll> parent, rank;

    DSU(ll n) {
        parent.resize(n);
        rank.resize(n, 1);
        for (ll i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    ll find(ll x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unionSets(ll x, ll y) {
        ll rootX = find(x);
        ll rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

ll distanceSquared(ll x1, ll y1, ll x2, ll y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

signed main() {
    OPTIMIZE_IO;
    ll n, m, w;
    cin >> n >> m >> w;

    vector<tuple<ll, ll, ll>> webs(w);
    rep(i,w){
        ll x, y, r;
        cin >> x >> y >> r;
        webs[i] = make_tuple(x, y, r);
    }

    DSU dsu(w + 4);
    ll LEFT = w, RIGHT = w + 1, TOP = w + 2, BOTTOM = w + 3;

    rep(i,w)
    {
        ll x1, y1, r1;
        tie(x1, y1, r1) = webs[i];

        if (x1 - r1 <= 0) dsu.unionSets(i, LEFT);       
        if (x1 + r1 >= n) dsu.unionSets(i, RIGHT);      
        if (y1 - r1 <= 0) dsu.unionSets(i, TOP);       
        if (y1 + r1 >= m) dsu.unionSets(i, BOTTOM);     

        for (ll j = 0; j < w; ++j) {
            ll x2, y2, r2;
            tie(x2, y2, r2) = webs[j];
            ll r_sum_squared = (r1 + r2) * (r1 + r2);
            if (distanceSquared(x1, y1, x2, y2) <= r_sum_squared) {
                dsu.unionSets(i, j);
            }
        }
    }

    if (dsu.find(LEFT) == dsu.find(RIGHT) || 
        dsu.find(TOP) == dsu.find(BOTTOM) ||
        dsu.find(LEFT) == dsu.find(TOP) ||
        dsu.find(BOTTOM) == dsu.find(RIGHT)) {
        cout << "N" << endl; 
    } else {
        cout << "S" << endl; 
    }

    return 0;
}
