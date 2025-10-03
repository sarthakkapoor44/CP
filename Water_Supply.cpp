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

int log2ceil(int n) {
    return (n <= 1) ? 0 : 1 + log2ceil((n + 1) / 2);
}

int initializeLCA(int root, const vector<vector<pair<ll,ll>>> &adj, vector<int> &depth, vector<vector<int>> &up) {
    int n = adj.size();
    int maxLog = log2ceil(n);
    depth.assign(n, 0);
    up.assign(n, vector<int>(maxLog + 1, -1));
    function<void(int, int)> dfs = [&](int u, int p) {
        up[u][0] = p;
        for (int i = 1; i <= maxLog; i++) {
            if (up[u][i - 1] != -1) {
                up[u][i] = up[up[u][i - 1]][i - 1];
            }
        }
        for (const auto& [v, w] : adj[u]) {
            if (v != p) {
                depth[v] = depth[u] + 1;
                dfs(v, u);
            }
        }
    };
    dfs(root, -1);
    return maxLog;
}

int lca(int u, int v, vector<int> &depth, vector<vector<int>> &up) {
    if (depth[u] < depth[v]) {
        swap(u, v);
    }
    int k = depth[u] - depth[v];
    for (int i = 0; i < up[0].size(); i++) {
        if ((k >> i) & 1) {
            u = up[u][i];
        }
    }
    if (u == v) {
        return u;
    }
    for (int i = up[0].size() - 1; i >= 0; i--) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
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
        ll n,k;
        cin>>n>>k; 
        vector<ll> nodes(n-1),edges(n-1);
        rep(i,n-1){cin>>nodes[i];nodes[i]--;}
        rep(i,n-1)cin>>edges[i];
        vector<vector<pll>> adj(n);
        for(int i =0 ; i < n-1 ; i++){
            adj[nodes[i]].pb({i+1,edges[i]});adj[i+1].pb({nodes[i],edges[i]});
        }
        vector<int> depth;
        vector<vector<int>> up;
        initializeLCA(0,adj,depth,up);
        vector<ll> ans(n);
        ans[0]= k;
        function<void(ll,ll,ll)>dfs = [&](ll pos,ll par,ll val)->void{
            for(auto x: adj[pos]){
                // debug(val);
                if(x.fi== par)continue;
                ll val2 = val - (val/x.se);
                ans[x.fi] = val2;
                dfs(x.fi,pos,val2);
            }
        };
        dfs(0,0,k);
        vector<ll>mn;ll mnElem = *min_element(all(ans));
        rep(i,n)if(ans[i]==mnElem)mn.pb(i);
        ll lcs = mn[0];
        rep(i,mn.size()){
            lcs = lca(lcs,mn[i],depth,up);
        }   
        if(lcs==0)cout<<mnElem;
        else {
            vector<ll> finPath;bool cq=0;
            function<void(ll,ll,vector<ll>&)>dfs2 = [&](ll pos,ll par,vector<ll>& path)->void{
                if(cq)return;
                for(auto x: adj[pos]){                    
                    if(x.fi== par)continue;
                    path.pb(x.se);
                    if(x.fi==lcs){
                        cq=1;
                        return ;
                    }
                    dfs2(x.fi,pos,path);
                    path.pop_back();
                }
            };
            dfs2(0,0,finPath);
            
        }
    }

    return 0;
}
