///////////////////////////////////////////////////// DYNATOS ////////////////////////////////////////////////////
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#ifdef ONLINE_JUDGE
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#endif
using namespace std;
typedef long long ll;

#define rep(i,n) for(ll i=0;i<(ll)(n);++i)
#define pb push_back

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,q; 
    if(!(cin>>n>>q)) return 0;
    vector<vector<ll>> adj(n);
    vector<ll> val(n);
    rep(i,n) cin>>val[i];
    rep(i,n-1){
        ll u,v; cin>>u>>v; --u;--v;
        adj[u].pb(v); adj[v].pb(u);
    }

    ll LOG = max(1LL,(ll)ceil(log2((double)max(1LL,n))));
    vector<vector<ll>> up(n, vector<ll>(LOG+1,-1));
    vector<ll> depth(n,0), sz(n,0), tin(n,0), tout(n,0), euler; euler.reserve(n);

    function<void(ll,ll)> dfs = [&](ll u, ll p){
        up[u][0] = p;                  
        for(int i=1;i<=LOG;i++){
            if(up[u][i-1] == -1) { up[u][i] = -1; }
            else up[u][i] = up[ up[u][i-1] ][i-1];
        }
        tin[u] = (ll)euler.size();
        euler.pb(val[u]);
        sz[u]=1;
        for(ll v: adj[u]){
            if(v==p) continue;
            depth[v]=depth[u]+1;
            dfs(v,u);
            sz[u]+=sz[v];
        }
        tout[u] = tin[u] + sz[u] - 1; 
    };
    dfs(0,-1);

    auto isAncestor = [&](ll a, ll b)->bool{
        return tin[a] <= tin[b] && tout[a] >= tout[b];
    };

    auto kth_ancestor = [&](ll a, ll k)->ll{
        for(int i=0;i<=LOG && a!=-1;i++){
            if(k & (1LL<<i)) a = (a==-1 ? -1 : up[a][i]);
        }
        return a;
    };

    auto lca = [&](ll a, ll b)->ll{
        if(isAncestor(a,b)) return a;
        if(isAncestor(b,a)) return b;
        for(int i=LOG;i>=0;i--){
            ll ua = up[a][i];
            if(ua!=-1 && !isAncestor(ua,b)) a = ua;
        }
        return up[a][0];
    };

    vector<ll> BIT1(n+2,0), BIT2(n+2,0);
    auto bit_add = [&](vector<ll>& B, ll i, ll v){
        for(; i <= n+1; i += i & -i) B[i] += v;
    };
    auto bit_sum = [&](const vector<ll>& B, ll i){
        ll s = 0;
        for(; i > 0; i -= i & -i) s += B[i];
        return s;
    };
    auto range_add = [&](ll l, ll r, ll v){
        if(l>r) return;
        ll L=l+1, R=r+1;
        bit_add(BIT1, L, v);
        bit_add(BIT1, R+1, -v);
        bit_add(BIT2, L, v*(L-1));
        bit_add(BIT2, R+1, -v*R);
    };
    auto prefix_sum = [&](ll r){ 
        if(r<0) return 0LL;
        ll P=r+1;
        return bit_sum(BIT1,P)*P - bit_sum(BIT2,P);
    };
    auto range_sum = [&](ll l, ll r){
        if(l>r) return 0LL;
        return prefix_sum(r) - prefix_sum(l-1);
    };
    for(ll i=0;i<(ll)euler.size();++i) range_add(i,i,euler[i]);

    auto inc_subtree = [&](ll u, ll x){
        range_add(tin[u], tout[u], x);
    };
    auto sum_subtree = [&](ll u)->ll{
        return range_sum(tin[u], tout[u]);
    };
    auto sum_all = [&]()->ll{
        return range_sum(0, n-1);
    };

    ll root = 0;

    while(q--){
        ll t; cin>>t;
        if(t==1){
            ll r; cin>>r; --r;
            root = r;
        }else if(t==2){
            ll u,v,x; cin>>u>>v>>x; --u;--v;
            ll w1 = lca(u,v);
            ll w2 = lca(u,root);
            ll w3 = lca(v,root);
            ll w = w1;
            if(depth[w2] > depth[w]) w = w2;
            if(depth[w3] > depth[w]) w = w3;

            if(w == root){
                
                range_add(0, n-1, x);
            }else if(isAncestor(w, root)){
                range_add(0, n-1, x);
                ll dist = depth[root] - depth[w] - 1; 
                ll c = kth_ancestor(root, dist);
                inc_subtree(c, -x);
            }else{
                inc_subtree(w, x);
            }
        }else{ 
            ll u; cin>>u; --u;
            if(u == root){
                cout << sum_all() << "\n";
            }else if(isAncestor(u, root)){ 
                ll dist = depth[root] - depth[u] - 1;
                ll c = kth_ancestor(root, dist);
                cout << (sum_all() - sum_subtree(c)) << "\n";
            }else{
                cout << sum_subtree(u) << "\n";
            }
        }
    }
    return 0;
}
