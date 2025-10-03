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
#define pll pair<ll,ll>
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
        ll n,m,mx,time =0 ;
        cin>>n>>m>>mx;
        vector<ll> arr(n);
        rep(i,n)cin>>arr[i];
        vector<vector<ll>> adj(n);
        rep(i,m){
            ll u,v;
            cin>>u>>v;
            u--;v--;
            adj[u].pb(v);
            adj[v].pb(u);
        } 
        vector<ll> vis(n),tin(n,INF),low(n,INF),color(n);
        unordered_map<ll,set<ll>> bridges;
        function<void(ll,ll,ll)> dfs = [&](ll node,ll parent, ll col)->void{
            vis[node] = 1;
            low[node] = tin[node] = ++time;
            color[node] = col;
            for(auto x:adj[node]){
                if(x == parent)continue;
                if(vis[x]){
                    low[node] = min(low[node],tin[x]);
                } else {
                    dfs(x,node,1-col);
                    low[node] = min(low[node],low[x]);
                    if(low[x] > tin[node]){
                        bridges[node].insert(x);
                        bridges[x].insert(node);
                    }
                }
            }
        };
        dfs(0,-1,0);
        vector<bool> vis2(n,0);
        function<ll(ll,ll,vector<ll>&)> dfs2 = [&](ll node, ll parent,vector<ll>&nodes)->ll{
            vis2[node]=1;
            nodes.pb(node);
            ll odd = 0 ;
            for(auto x: adj[node]){
                if(vis2[x] && bridges[node].count(x) == 0){
                    odd |= (color[x] == color[node]);
                }
                if(!vis2[x] && bridges[node].count(x)==0){
                    odd |= dfs2(x,node,nodes);
                    odd |= (color[x] == color[node]);
                }
            }
            return odd;
        };
        ll ans = 1;
        vector<ll> component;
        rep(i,n){
            component.clear();
            if(!vis2[i]){
                ll odd = dfs2(i,-1,component);
                ll val = -1,flag = 0 ;
                // debug(component);
                for(auto x: component){
                    if(arr[x]!=-1){
                       if(val==-1) val = arr[x];   
                       if(odd && arr[x]!=0)ans=0;
                       else if(val!=arr[x]){ans= 0;break;}
                    } else {
                        flag =1;
                    }
                }
                if(ans && flag ==1 && val == -1 && !odd)(ans*=mx%modn)%=modn;
            }
        }
        cout<<ans;ce;
    }

    return 0;
}
