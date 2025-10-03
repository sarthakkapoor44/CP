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
 
const ll N = 2e5+1;
vector<ll> ranks(N),parent(N),diff(N),a(N),b(N);
void make_set(ll u)
{
    ranks[u]=1;
    parent[u]=u;
    diff[u] = a[u] - b[u]; 
}
ll find(ll u)
{
    if(parent[u]== u)return u ;
    else return find(parent[u]);
}
ll union_set(ll u, ll v)
{
    u = find(u);
    v = find(v);
    if(ranks[v] > ranks[u])swap(u,v);
    ranks[u]+= ranks[v];
    parent[v] = u;
    ll val=  min(abs(diff[u]),abs(diff[v]));
    if(diff[u]*diff[v] > 0)val =0 ;
    diff[u]+= diff[v];
    return val; 
}
int main() {
    // FOR GCD - gcd snip
    // FOR SIEVE OF ERATOSTHENES - erat_snip;
    // FOR SPF - spf_snip
    // FOR BINARY_EXPONENTATION - binpow_snip
    // FOR SEGMENT_TREE - seg_snip
    // FOR LCA - lca_snip
    OPTIMIZE_IO // Optimize input/output (remove if using scanf and printf)
 
    {	//Lesgooooooo!!!!
        ll n,m,k;
        cin>>n>>m>>k;
        a.clear();b.clear();diff.clear();ranks.clear();parent.clear();
        a.resize(n);b.resize(n);diff.resize(n);ranks.resize(n);parent.resize(n);
        vector<vector<pair<ll,ll>>> adj(n);
        vector<vector<ll>> edge_list;
        rep(i,m)
        {
            ll u,v,w;
            cin>>u>>v>>w;
            u--;v--;
            adj[u].pb({v,w});
            adj[v].pb({u,w});
            vector<ll> edge = {w,u,v};
            edge_list.pb(edge);
        }
        srt(edge_list);

        rep(i,k)
        {
            ll node;
            cin>>node;
            a[node-1]++;
        }
        rep(i,k)
        {
            ll node;
            cin>>node;
            b[node-1]++;
        }   

        rep(i,n)
        {
            make_set(i);
        }
        // out(a);
        // out(b);
        // out(diff);
        ll ans = 0 ;
        for(auto x: edge_list)
        {
            ll wt = x[0];
            ll u = x[2],v = x[1];
            if (find(u)!=  find(v))
            {
                ll val = union_set(u,v);
                // cout<<val<<" "<<wt;ce;
                ans += wt*val;
            }
        }
        cout<<ans;ce;
    }

    return 0;
}
