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
#define pyes cout << "YES";
#define pno cout << "NO";
#define rep(i, n) for (ll i = 0; i < n; i++)
#define forf(i, a, b) for (ll i = a; i < b; i++)
#define forb(i, s, e) for (ll i = s; i >= e; i--)
#define vp vector<pair<ll, ll>>
#define vll vector<ll>
#define OPTIMIZE_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//    tree_order_statistics_node_update> ost;
#ifndef ONLINE_JUDGE
#include "debug.cpp"
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
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

    int t = 1;
    cin >> t;
    while (t--) { // Lesgooooooo!!!!
        ll n;
        cin >> n;
        vll arr(n); rep(i, n) cin >> arr[i];
        vector<vector<ll>> adj(n);
        rep(i, n - 1) {
            ll a, b; cin >> a >> b;
            adj[a - 1].pb(b - 1);
            adj[b - 1].pb(a - 1);
        }
        ll ans = 0;
        multiset<ll> l, h;
        function<void(int, int, int, multiset<ll>&, multiset<ll>&)> dfs = [&](int pos, int par, int len, multiset<ll>& low, multiset<ll>& high) -> void {
            if (high.size() && arr[pos] > *(high.begin())) {
                high.insert(arr[pos]);
                ll val = *(high.begin());
                high.erase(high.begin());
                low.insert(val);
            } else {
                low.insert(arr[pos]);
            }
            if (low.size() - high.size() >= 2) {
                ll val = *(--low.end());
                low.erase(--low.end());
                high.insert(val);
            }
            if (len % 2) { ans += *(--low.end()); }
            
            for (auto x : adj[pos]) {
                if (x == par) { continue; }
                dfs(x, pos, len + 1, low, high);
            }
            
            if(high.count(arr[pos]))
            {
                high.erase(high.find(arr[pos]));
                if (low.size() - high.size() >= 2) 
                {
                    ll val = *(--low.end());
                    low.erase(--low.end());
                    high.insert(val);
                }
            }
            else if(low.count(arr[pos]))
            {
                low.erase(low.find(arr[pos]));
                if (low.size() < high.size()) 
                {
                    ll val = *(high.begin());
                    high.erase(high.begin());
                    low.insert(val);
                }
            }
            return;
        
        };
        dfs(0, -1, 1, l, h);
        cout << ans; ce;
    }

    return 0;
}


