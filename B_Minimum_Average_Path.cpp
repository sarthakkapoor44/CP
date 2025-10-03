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
    // FOR SIEVE OF ERATOSTHENES - erat_snip;
    // FOR SPF - spf_snip
    // FOR BINARY_EXPONENTATION - binpow_snip
    // FOR SEGMENT_TREE - seg_snip
    // FOR LCA - lca_snip
    OPTIMIZE_IO // Optimize input/output (remove if using scanf and printf)
 
    {	//Lesgooooooo!!!!
        ll n,m;
        cin>>n>>m;
        vector<vector<pair<ll,long double>>> adj(n+1);
        rep(i,m)
        {
            ll u,v;
            long double w;
            cin>>u>>v>>w;
            adj[u].pb({v,w});
        }
        long double left = 0,right  =100;
        vector<ll> topo;
        vector<ll> vis(n+1,0);
        function<void(ll)> toposort = [&](ll pos)->void{
            if(vis[pos])return;
            vis[pos]= 1;
            for(auto [x,w]: adj[pos])
            {
                toposort(x);
            }
            topo.pb(pos);
        };  
        toposort(1);
        reverse(all(topo));
        // out(topo);
        vector<ll> par(n+1,-1);
        while(right - left > 1e-10)
        {
            long double mid = (left+right)/(2.0);
            vector<long double> dist(n+1,INF);
            for(auto x: topo)
            {
                if(dist[x] == INF)dist[x] = 0 ;
                for(auto [y,w]: adj[x])
                {
                    if(dist[y] > dist[x]+w-mid)
                    {
                        dist[y] = dist[x]+w-mid;
                        par[y] = x;
                    }
                }
            }

            bool cq = (dist[n]<=0);
            if(cq)
            {
                right = mid;
            }
            else
            {
                left = mid;
            }
        }
        vector<ll> path;
        for(int i = n ;i!=-1;i = par[i])
        {
            path.pb(i);
        }
        reverse(all(path));
        cout<<path.size()-1<<endl;
        out(path);
        // cout<<endl;
        // cout<<(right+left)/2.0<<endl;
        
    }

    return 0;
}
