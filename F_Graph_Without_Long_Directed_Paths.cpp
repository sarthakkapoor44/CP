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
 
// #ifndef ONLINE_JUDGE
// #include "debug.cpp"
// #define debug(x...)               \
//     cerr << "[" << #x << "] = ["; \
//     _print(x)
// #else
// #define debug(x...)
// #endif
 
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
 
    // int t=1;
    // cin>>t;
    // while (t--)
    {	//Lesgooooooo!!!!
        ll n,m;
        cin>>n>>m;
        vector<vector<ll>> adj(n+1);
        vector<pair<ll,ll>> edges;
        rep(i,m)
        {
            ll u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
            ll e=0;
         
            edges.pb({u,v});
        }

        vector<ll> node(n+1,-1);
        node[0]= INF;
        bool cq= 1;
        function<void(ll,ll)> dfs = [&](ll pos,ll color)->void
        {

            node[pos] = color;
            for(auto x:adj[pos])
            {
                if(node[x]==-1)dfs(x,1-color);
                else if(node[x]==color)cq=0;
            }
            return;
        };
        dfs(1,0);
        // rep(i,n)cout<<node[i]<<" ";
        if(cq)
        {
            pyes;ce;
            rep(i,m)
            {
                if(node[edges[i].fi]==0)cout<<1;
                else cout<<0;
            }   
        }
        else {pno;}

        
    }

    return 0;
}
