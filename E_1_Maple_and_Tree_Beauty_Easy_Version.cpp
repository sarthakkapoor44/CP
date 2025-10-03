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
        ll n,k;
        cin>>n>>k;
        vector<vector<ll>> adj(n);
        forf(i,1,n){
            ll u;cin>>u;u--;
            adj[u].pb(i);
            adj[i].pb(u);
        } 
        vector<ll> levels = {1};
        queue<ll> q;
        q.push(0);
        vector<ll> vis(n);
        vis[0]=1;
        // debug(adj);
        ll min_depth = n;
        while(!(q.empty())){
            ll sz= q.size();
            for(int i=0 ;i <sz;i++){
                ll top = q.front();
                if(adj[top].size()==1 && top!=0){
                    min_depth = min(ll(levels.size()),min_depth);}
                q.pop();
                for(auto x: adj[top]){
                    if(!vis[x]){vis[x]=1;q.push(x);}
                }
            }
            if(q.size())levels.pb(q.size());
        }
        vector<vector<ll>> dp(levels.size()+1,vector<ll>(k+1,-1));
        dp[1][0]=1;
        if(k>=1)dp[1][1]=1;
        dp[0][0]=0;
        min_depth = min(ll(levels.size()),min_depth);
        ll tot = 1;
        for(int i =2;i<=levels.size();i++){
            tot+= levels[i-1];
            for(int j = 0 ;j<=min(tot,k);j++){
                if(dp[i-1][j]>=0)dp[i][j]= dp[i-1][j];
                if(j-levels[i-1] >= 0 && dp[i-1][j-levels[i-1]] >= 0)dp[i][j] = max(dp[i][j],dp[i-1][j-levels[i-1]]+1);
                if(tot - j <= n-k && dp[i-1][j] >= 0)dp[i][j] = max(dp[i][j],dp[i-1][j]+1);
            }
        }
        // debug(dp,min_depth);
        ll nodesLeft = 0;
        for(int i= min_depth;i<levels.size();i++){
            nodesLeft+= levels[i];
        }
        ll ans = 0;
        for(int i = 0 ; i<=k;i++){
            ans = max(ans,dp[min_depth][i]);
        }
        cout<<ans;ce;
    }

    return 0;
}
