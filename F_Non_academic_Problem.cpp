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
 
    int t=1;
    cin>>t;
    while (t--)
    {	//Lesgooooooo!!!!
        ll n,m;
        cin>>n>>m;
        vector<vector<ll>> adj(n);
        for (ll i = 0; i < m; i++)
        {
            ll a,b;cin>>a>>b;
            adj[a-1].push_back(b-1);
            adj[b-1].push_back(a-1);
        }
        vector<ll> vis(n,0),tin(n,0),lo(n,0);
        ll timer = 0;
        ll ans= (n*(n-1))/2 ;
        function<ll(ll,ll)> dfs = [&](ll pos,ll par)->ll{
            vis[pos]=1;
            tin[pos] = lo[pos] = ++timer;
            ll size = 1;
            for(auto it : adj[pos])
            {
                if(it == par)continue;
                if(vis[it])
                {
                    lo[pos] = min(tin[it],lo[pos]);
                }
                else 
                {
                    ll subtree = dfs(it,pos);
                    size+= subtree;
                    lo[pos] = min(lo[pos],lo[it]);
                    if(lo[it] > tin[pos])
                    {
                        ll val  = n - subtree;
                        ll pairs = (val*(val-1))/2 + (subtree*(subtree-1))/2;
                        ans = min(ans,pairs);
                    }
                }
            }
            return size;
        };
        dfs(0,-1);
        
        cout<<ans;ce;
    }

    return 0;
}
