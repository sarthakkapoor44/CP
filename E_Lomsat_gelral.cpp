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
 
    {	//Lesgooooooo!!!!
        ll n;
        cin>>n;
        vll arr(n);
        rep(i,n)cin>>arr[i];
        vector<vector<ll>> adj(n);
        rep(i,n-1)
        {
            ll u,v;
            cin>>u>>v;
            u--;
            v--;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        vll ans(n);
        function<map<ll,ll>(ll,ll,map<ll,ll>&)> dfs = [&](ll pos,ll par,map<ll,ll>& c_occ)->map<ll,ll>
        {
            map<ll,ll> colors;
            map<ll,ll> cnt;
            cnt[arr[pos]]=1;
            colors[arr[pos]]=1;
            for(auto x:adj[pos])
            {
                if(x==par)continue;
                map<ll,ll> child_occurence;
                map<ll,ll> child = dfs(x,pos,child_occurence);
                if(child.size()>colors.size())swap(child,colors);
                if(child_occurence.size()>cnt.size())swap(child_occurence,cnt);
                for(auto x:child)
                {
                    colors[x.fi]+=x.se;
                }      
            }
            return colors;
        };
        map<ll,ll> temp;
        dfs(0,-1,temp);
    }

    return 0;
}
