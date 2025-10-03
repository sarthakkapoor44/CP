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

void make_set(ll i,vll &parent,vll &ranks)
{
    parent[i] = i;
    ranks[i] = 0;
}
ll find_set(ll i,vll &parent)
{
    if(i==parent[i])
        return i;
    return parent[i] = find_set(parent[i],parent);
}
void union_sets(ll a, ll b,vll &parent,vll &ranks)
{
    a = find_set(a,parent);
    b = find_set(b,parent);
    if(a!=b)
    {
        if(ranks[a]<ranks[b])
            swap(a,b);
        parent[b] = a;
        if(ranks[a]==ranks[b])
            ranks[a]++;
    }
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
        ll n,m1,m2;
        cin>>n>>m1>>m2;
        vector<vector<ll>> adj(n);
        vector<pair<ll,ll>> edges1,edges2;
        rep(i,m1){
            ll u,v;
            cin>>u>>v;
            u--,v--;
            adj[u].pb(v);
            adj[v].pb(u);
            edges1.pb({u,v});
        }
        
        rep(i,m2){
            ll u,v;
            cin>>u>>v;
            u--,v--;
            edges2.pb({u,v});
        }
        vector<ll> parent1(n),parent2(n),ranks1(n),ranks2(n);
        rep(i,n){
            make_set(i,parent1,ranks1);
            make_set(i,parent2,ranks2);
        }

        for(auto x:edges2)
        {
            union_sets(x.fi,x.se,parent2,ranks2);
        }
        vector<ll> vis(n);

        ll cnt = 0;
        function<void(ll)> dfs = [&](ll u)
        {
            vis[u] = 1;
            for(auto v:adj[u])
            {
                if(!vis[v] ){
                    if(find_set(u,parent2)==find_set(v,parent2))
                    {
                        union_sets(u,v,parent1,ranks1);
                        dfs(v);
                    }
                    else cnt++;
                }
            }
        };

        rep(i,n){
            if(!vis[i]){
                dfs(i);
            }
        }   

        rep(i,n)
        {
            ll par = find_set(i,parent2);
            if(find_set(i,parent1)!= find_set(par,parent1))
            {
                cnt++;
                union_sets(i,par,parent1,ranks1);
            }
        }
        cout<<cnt<<endl;
        
    }

    return 0;
}
