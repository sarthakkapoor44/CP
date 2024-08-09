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
#define pyes cout<<"YES";
#define pno cout<<"NO";
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
 
int main() {
    // FOR GCD - gcd snip
    // FOR SIEVE OF ERATOSTHENES - erat_snip;
    // FOR SPF - spf_snip
    // FOR BINARY_EXPONENTATION - binpow_snip
    OPTIMIZE_IO // Optimize input/output (remove if using scanf and printf)
 
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<vll> arr(3, vll(n)), pre(3, vll(n + 1));
        rep(i, 3) rep(j, n) cin >> arr[i][j];
        
        ll sum = accumulate(all(arr[0]), 0LL);
        ll val = ceil(sum / 3.0);
        
        rep(i, 3) {
            rep(j, n) pre[i][j + 1] = pre[i][j] + arr[i][j];
        }
        
        bool flag = 0;
        vector<vll> ans(3, vector<ll>(2));
        
        forf(j, 1, n + 1) {
            rep(i, 3) {
                ll temp = pre[i][j] - val;
                auto x = upper_bound(all(pre[i]), temp) - pre[i].begin();
                if (x > 0) {
                    x--;
                    if (pre[i][j] - pre[i][x] >= val) {
                        if (pre[(i + 1) % 3][x] >= val && (pre[(i + 2) % 3][n] - pre[(i + 2) % 3][j]) >= val && x>=1 && j+1<=n && x+1<=j) {
                            flag = 1;
                            ans[(i + 1) % 3] = {1, x};
                            ans[(i + 2) % 3] = {j + 1, n};
                            ans[i] = {x + 1, j};
                        }
                        if (pre[(i + 2) % 3][x] >= val && (pre[(i + 1) % 3][n] - pre[(i + 1) % 3][j]) >= val && x>=1 && j+1<=n && x+1<=j) {
                            flag = 1;
                            ans[(i + 2) % 3] = {1, x};
                            ans[(i + 1) % 3] = {j + 1, n};
                            ans[i] = {x + 1, j};
                        }
                    }
                }
            }
        }
        
        if (flag) {
            for (auto x: ans) { cout << x[0] << " " << x[1] << " "; }
        } else cout << -1;
        ce;
    }
    return 0;
}
