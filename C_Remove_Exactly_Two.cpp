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
    std::cin.tie(nullptr);\
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
 
int main() {
    // FOR GCD - gcd snip
    // FOR SIEVE OF ERATOSTHENES - erat_snip;fast_sieve
    // FOR SPF - spf_snip
    // FOR BINARY_EXPONENTATION - binpow_snip
    // FOR SEGMENT_TREE - seg_snip
    // FOR LCA - lca_snip
    OPTIMIZE_IO // Optimize input/output (remove if using scanf and printf)
 
    int t=1;
    cin>>t;
    while (t--)
    {	//Lesgooooooo!!!!
        ll n;
        cin>>n;
        ll ans = 0;
        vector<vector<ll>> adj(n);
        rep(i,n-1)
        {
            ll u,v;
            cin>>u>>v;
            u--;v--;
            adj[u].pb(v);
            adj[v].pb(u);
        } 
        if(n<=2)cout<<0;
        else
        {
            vp deg;
            rep(i,n)
            {
                deg.pb({adj[i].size(),i});
                srt(adj[i]);
            }
            sort(all(deg),greater<pair<ll,ll>>());
            ll val = deg[0].se;
            ll val2 = deg[1].se;
            ll val3 = deg[2].se;

        
            ans = max(ans,deg[0].fi+deg[1].fi-2);
            auto x = lower_bound(all(adj[val]),val2);
            if(*x!=val2 )ans = max(ans,deg[0].fi+deg[1].fi-1);

            ans = max(ans,deg[0].fi+deg[2].fi-2);
            x = lower_bound(all(adj[val]),val3);
            if(*x!=val3 )ans = max(ans,deg[0].fi+deg[2].fi-1);

            ans = max(ans,deg[1].fi+deg[2].fi-2);
            x = lower_bound(all(adj[val2]),val3);
            if(*x!=val3 )ans = max(ans,deg[1].fi+deg[2].fi-1);

            cout<<ans;
        }
        cout<<endl;
        
    }

    return 0;
}
