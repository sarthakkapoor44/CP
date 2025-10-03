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
        ll n;
        cin>>n;
        vll arr(n);
        string s = "";
        rep(i,n){cin>>arr[i];arr[i]--;s+="0";}
        vector<vll> adj(n);
        rep(i,n-1)
        {
            ll u,v;
            cin>>u>>v;
            adj[u-1].pb(v-1);
            adj[v-1].pb(u-1);
        } 
        
        vll occurence(n,-1);
        function<void(ll,ll,ll)> dfs = [&](ll pos,ll par,ll ht)->void{
            // debug(pos,par,ht,occurence);
            // out(occurence);
            if(occurence[arr[pos]]!=-1)
            {
                ll nodes = ht - occurence[arr[pos]] + 1;
                if(nodes<=3)s[arr[pos]] = '1';
            }
            ll old = occurence[arr[pos]];
            occurence[arr[pos]] = ht;
            // out(occurence);
            // debug(pos,par,ht,occurence);
            set<ll> st;
            for(auto x:adj[pos])
            {
                if(x==par)continue;
                if(st.find(arr[x])!=st.end())s[arr[x]] = '1';
                st.insert(arr[x]);
                if(arr[x]==arr[pos])s[arr[x]] ='1';
                dfs(x,pos,ht+1);
            }
            occurence[arr[pos]] = old;
        };
        dfs(0,0,1);
        cout<<s<<endl;
    }

    return 0;
}
