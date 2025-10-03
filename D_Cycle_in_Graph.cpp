#include<bits/stdc++.h>
///////////////////////////////////////////////////// DYNATOS ////////////////////////////////////////////////////
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
    // int t=1;
    // cin>>t;
    // while (t--)
    {	//Lesgooooooo!!!!
        ll n,m,k,start = 0,end = 0,found =0 ;
        cin>>n>>m>>k;
        vector<vector<ll>> adj(n+1);
        for(int i=1;i<=m;i++){
            ll u,v;cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<ll> vis(n+1),parentMap(n+1), depthMap(n+1),ans;
        function<void(ll,ll)> dfs = [&](ll node,ll parent)->void{
            if(found)return ;
            vis[node] = 1;
            depthMap[node] = depthMap[parent]+1;
            for(auto x: adj[node]){
                if(x == parent) continue;
                if(vis[x]){
                    if(depthMap[node] - depthMap[x] + 1 >= k+1){
                        start = x, end = node;
                        found =1;
                        return;
                    }
                }
                else {
                    parentMap[x] = node;
                    dfs(x,node);
                }
            }
            return;
        };
        for(int i = 1;i<=n;i++){
            if(found)break;
            if(vis[i])continue;
            dfs(i,i);
        }
        for(auto x = end;;x = parentMap[x]){
            ans.push_back(x);
            if(x == start)break;
        }
        reverse(all(ans));
        cout<<ans.size()<<endl;out(ans);
        // debug(vis,parentMap,start,end,depthMap);
    }

    return 0;
}
