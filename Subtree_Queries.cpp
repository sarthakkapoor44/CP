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

struct segTree
{
    vector<ll>  tree;
    ll size;
    segTree(ll n)
    {
        size = n;
        tree.resize(4 * n);
    }
    void build(ll node, ll start, ll end, vector<ll> &arr)
    {
        if (start == end)
        {
            tree[node] = arr[start];
        }
        else
        {
            ll mid = (start + end) / 2;
            build(2 * node + 1, start, mid, arr);
            build(2 * node + 2, mid + 1, end, arr);
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }
    void update(ll node, ll start, ll end, ll idx, ll val)
    {
        if (start == end)
        {
            tree[node] = val;
        }
        else
        {
            ll mid = (start + end) / 2;
            if (idx <= mid)
            {
                update(2 * node + 1, start, mid, idx, val);
            }
            else
            {
                update(2 * node + 2, mid + 1, end, idx, val);
            }
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }
    ll query(ll node, ll start, ll end, ll l, ll r)
    {
        if (r < start || end < l)
        {
            return 0;
        }
        if (l <= start && end <= r)
        {
            return tree[node];
        }
        ll mid = (start + end) / 2;
        ll p1 = query(2 * node + 1, start, mid, l, r);
        ll p2 = query(2 * node + 2, mid + 1, end, l, r);
        return p1 + p2;
    }
    void update(ll idx, ll val)
    {
        update(0, 0, size - 1, idx, val);
    }
    ll query(ll l, ll r)
    {
        return query(0, 0, size - 1, l, r);
    }

};
int main() {
    // FOR GCD - gcd snip
    // FOR SIEVE OF ERATOSTHENES - erat_snip;fast_sieve
    // FOR SPF - spf_snip
    // FOR BINARY_EXPONENTATION - binpow_snip
    // FOR SEGMENT_TREE - seg_snip
    // FOR LCA - lca_snip
    OPTIMIZE_IO // Optimize input/output (remove if using scanf and printf)
 
    // int t=1;
    // cin>>t;
    // while (t--)
    {	//Lesgooooooo!!!!
        ll n,q;
        cin>>n>>q;
        vll arr(n);
        rep(i,n) cin>>arr[i];
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
        vector<ll> dfs_order,dfs_vals(n);
        vector<ll> subSize(n,1);
        function<void(ll,ll)> dfs = [&](ll node,ll par)->void{
            // subSum[node]=arr[node];    
            dfs_vals[node] = dfs_order.size();
            dfs_order.pb(arr[node]);  
            for(auto child:adj[node])
            {
                if(child==par) continue;
                dfs(child,node);
                subSize[node]+=subSize[child];
                // subSum[node]+=subSum[child];
            }
        };  
        dfs(0,-1);
        // debug(dfs_order);
        segTree st(n);
        st.build(0,0,n-1,dfs_order);
        // debug(st.tree);
        rep(i,q)
        {
            ll query;
            cin>>query;
            if(query == 1)
            {
                ll s,x;
                cin>>s>>x;
                s--;
                st.update(dfs_vals[s],x);
                dfs_order[dfs_vals[s]]=x;
            }
            else
            {
                ll x;
                cin>>x;
                x--;
                ll sub = subSize[x];
                ll ans = st.query(dfs_vals[x],dfs_vals[x]+sub-1);
                cout<<ans<<endl;
            }
        }
    }

    return 0;
}
