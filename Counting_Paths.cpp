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
    // FOR SEGMENT_TREE - seg_snip
    OPTIMIZE_IO // Optimize input/output (remove if using scanf and printf)

    {	//Lesgooooooo!!!!
        ll n,m;
        cin>>n>>m;
        vector<vll> adj(n);
        rep(i,n-1)
        {
            ll u,v;
            cin>>u>>v;
            u--;v--;
            adj[u].pb(v);
            adj[v].pb(u);
        }
       ll l = 31;
       ll timer =0 ;
       vll tin(n),tout(n);
       vector<vll> succ(n,vector<ll>(l+1,-1));
       function<void(ll,ll)> find_succ = [&](ll pos,ll par)->void
       {
           succ[pos][0] = par;
           for(int i = 1;i<=l;i++)
           {
               succ[pos][i] = succ[succ[pos][i-1]][i-1];
           }
           tin[pos]=timer++;
           for(auto x:adj[pos])
           {
               if(x==par)continue;
               find_succ(x,pos);
           }
           tout[pos]=timer++;
       };
       find_succ(0,0);
       function<bool(ll,ll)> is_ancestor  =[&](ll a,ll b)->bool
       {
           return (tin[a]<=tin[b] && tout[a]>=tout[b]);
       };
       
       function<ll(ll,ll)> lca = [&](ll a,ll b)->ll
       {
           if(is_ancestor(a,b))return a;
           if(is_ancestor(b,a))return b;
           for (int i = l; i >= 0; --i) 
           {
               if (!is_ancestor(succ[a][i], b))
               a = succ[a][i];
           }
           return succ[a][0];
       };

       vll ans(n);
       vll start(n),end(n);// start,end
       rep(i,m)
       {
            ll u,v;
            cin>>u>>v;
            u--;v--;
            ll num = lca(u,v);
            // cout<<u<<" "<<v<<" "<<num;ce;
            start[u]++;
            start[v]++;
            end[num]++;
       } 
       function<ll(ll,ll)> dfs = [&](ll pos,ll par)->ll
       {
           
            for(auto x: adj[pos])
            {
                if(x==par)continue;
                ans[pos]+= dfs(x,pos);
            }
            ans[pos]+= start[pos]-end[pos];
            return ans[pos]- end[pos];
        };  

       
        dfs(0,0); 
        out(ans);
    }

    return 0;
}
