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

    {	//Lesgooooooo!!!!
        ll n,m;
        cin>>n>>m;
        vector<vector<int>> adj(n);
        vector<vector<int>> edges;
        for(int i=0;i<m;i++){
            int u,v;cin>>u>>v;
            u--;v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n,0);
        vector<int> tin(n,0),low(n,0);
        int timer = 0;
        bool cq  = 0;
      
        function<void(int,int)> dfs = [&](int pos,int par)->void{
            low[pos] = tin[pos] = ++timer;
            vis[pos]=1;
            for(auto x:adj[pos])
            {
                if(x==par)continue;
                if(vis[x])
                {
                    low[pos] = min(tin[x],low[pos]);
                }
                else 
                {
                    dfs(x,pos);
                    low[pos] = min(low[x],low[pos]);
                    if(tin[pos] < low[x])
                    {
                        edges.pb({pos+1,x+1});
                    }
                  
                }
            }
            vis[pos]=2;
        };
        int cnt = 0 ;
        for(int i=0;i<n;i++){if(!vis[i]){dfs(i,-1);}}

        for(auto x:edges){cout<<x[0]<<" "<<x[1]<<" ";ce;}
        
    }

    return 0;
}
