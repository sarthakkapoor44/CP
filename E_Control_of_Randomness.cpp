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
        ll n,q;
        cin>>n>>q;
        vector<vector<ll>> adj(n+1);
        for(int i=0 ;i<n-1;i++)
        {
            ll u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        rep(i,q)
        {
            ll v,p;
            cin>>v>>p;
        
            vector<pair<ll,ll>> path;
            ll cq =0;
            function<void(ll,ll)> dfs = [&](ll pos,ll par)->void
            {
                if(cq==0)path.push_back({pos,adj[pos].size()});
                else return;
                if(pos == v) cq=1;
                for(auto x: adj[pos])
                {
                    if(x==par)continue;
                    dfs(x,pos);
                }
                if(cq==0)path.pop_back();
                return;
            } ;
            dfs(1,0);
            ll ans =1;
            vector<ll> vect;
            for(int i = path.size()-2;i>=1;i-=2)
            {
                ll num =  2*path[i].se;
                if(i==1)num--;
                vect.pb(num);
            }
            // debug(vect);
         
            srt(vect);
            for(int i=vect.size()-1;i>=0;i--)
            {
                if(p)
                {
                    ans+= 2;
                    if(vect[i]%2 == 1)ans--;
                    p--;
                }
                else ans+= vect[i];
            }
            // debug(path);
            cout<<ans<<endl;
        }
    }

    return 0;
}
