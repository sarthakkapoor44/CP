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
        vll val(n);
        rep(i,n)cin>>val[i];
        vector<vll> adj(n);
        rep(i,n-1)
        {
            ll u,v;
            cin>>u>>v;
            adj[u-1].pb(v-1);
            adj[v-1].pb(u-1);
        } 
        vector<ll> in(n,0),outt(n,0);
        ll time = 0;
        map<ll,pair<ll,ll>> mp;
        function<void(ll,ll)> dfs = [&](ll pos,ll par)->void
        {
            in[pos] = ++time;
            if(mp[val[pos]].fi == 0)mp[val[pos]].fi = in[pos];
            else mp[val[pos]].fi = min(mp[val[pos]].fi,in[pos]);
            for(auto x:adj[pos])
            {
                if(x!=par)
                {
                    dfs(x,pos);
                }
            }
            outt[pos] = ++time;
            mp[val[pos]].se = max(mp[val[pos]].se,outt[pos]);
        };     
        dfs(0,-1);

        vll nodes(n);
        iota(all(nodes),0ll);
        
        sort(all(nodes),[&](ll a,ll b)->bool
        {
            return val[a]<val[b];
        });
        vll ans ;

        // debug(in,outt,nodes,mp);

        forb(i,n-1,0)
        {
            auto next = mp.upper_bound(val[nodes[i]]);
            if(next == mp.end())continue;
            ll nl =  next->se.fi;
            ll nr = next->se.se;
            
            if(!(in[nodes[i]]<=nl and outt[nodes[i]]>=nr) )
            {
                // cout<<nodes[i]<<" "<<next->fi<<endl;
                // cout<<nl<<" "<<nr<<" "<<in[nodes[i]]<<" "<<outt[nodes[i]]<<endl;
                ans.pb(nodes[i]+1);
                // break;
            }
        }
        cout<<ans.size()<<" ";
        out(ans);
    }

    return 0;
}
