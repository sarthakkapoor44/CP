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
 
    // int t=1;
    // cin>>t;
    // while (t--)
    {	//Lesgooooooo!!!!
        ll n;
        cin>>n;
        vector<vll> adj(n);
        rep(i,n-1)
        {
            ll a,b;
            cin>>a>>b;
            adj[a-1].pb(b-1);
            adj[b-1].pb(a-1);
        }
        vp sub(n);
        function<void(ll,ll)> subtree  =[&](ll pos,ll par)->void{
            sub[pos] = {0,1};
            for(auto x:adj[pos])
            {
                if(x==par)continue;
                subtree(x,pos);
                sub[pos] = {sub[pos].fi+sub[x].fi+1*sub[x].se,sub[pos].se+sub[x].se};
            }
        };
        subtree(0,0);
        vll ans(n);
        function<void(ll,ll)> dfs = [&](ll pos,ll par)->void
        {
            if(pos>0)ans[pos] = ans[par] - 2*sub[pos].se + n;
            else ans[pos]= sub[pos].fi;
            for(auto x:adj[pos]){
                if(x==par)continue;
                dfs(x,pos);
            }
        };
        dfs(0,0);
        out(ans);
    }

    return 0;
}
