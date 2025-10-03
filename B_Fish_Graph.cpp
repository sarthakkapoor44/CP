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
        ll n,m;
        cin>>n>>m;
        vector<vll> adj(n);
        rep(i,m)
        {
            ll u,v;
            cin>>u>>v;
            adj[u-1].pb(v-1);
            adj[v-1].pb(u-1);
        }   
        bool flag = false;      
        for(int i = 0 ;i < n;i++)
        {
            if(adj[i].size()<4)continue;
            ll cy_sz= INF;
            vector<bool> vis1(n,false),visited(n,false);
            ll start = i;
            vector<ll> cycle;
            vector<ll> path1,path;
            function<void(ll,ll)> check_len  = [&](ll node,ll par)->void
            {
                vis1[node] = true;
                path1.pb(node);
                for(auto x:adj[node])
                {
                    if(!vis1[x])
                    {
                        check_len(x,node);
                    }
                    else if(x!=par && x == start)
                    {
                        cy_sz = min((ll)path1.size(),cy_sz);
                    }
                }
                path1.pop_back();
            };
            check_len(start,-1);
            if(cy_sz==INF)continue;
            // debug(cy_sz);
            function<void(ll,ll)> dfs = [&](ll node,ll par)->void
            {
                visited[node]= true;
                path.pb(node);
                for(auto x:adj[node])
                {
                    if(!visited[x])
                    {
                        dfs(x,node);
                    }
                    else if(x!=par && x == start && cycle.size()==0)
                    {
                        if(path.size()==cy_sz)
                        {
                            cycle = path;
                            return;
                        }
                    }
                }
                if(cycle.size()!=0)return;
                path.pop_back();
            };
            dfs(start,-1);
            vector<ll> cycle_nodes(n);
            for(auto x:cycle)
            {
                cycle_nodes[x] = 1;
            }
            vp edges;
            // debug(i,cycle);
            if(cy_sz!=INF)
            {
                ll cnt= 0;
                for(auto x:adj[start])
                {
                    if(cnt<2 && cycle_nodes[x]==0)
                    {
                        cycle_nodes[x] = 1;
                        edges.pb({start,x});
                        cnt++;
                    }
                }
                if(cnt==2)
                {
                    flag= true;
                    cout<<"YES\n";
                    cout<<cycle.size()+2<<endl;
                    for(int i = 0;i<cy_sz;i++)
                    {
                        cout<<cycle[i]+1<<" "<<cycle[(i+1)%cy_sz]+1<<endl;
                    }
                    for(auto x:edges)
                    {
                        cout<<x.fi+1<<" "<<x.se+1<<endl;
                    }
                }
            }
            if(flag)break;
        }
        if(!flag)cout<<"NO\n";
    }

    return 0;
}
