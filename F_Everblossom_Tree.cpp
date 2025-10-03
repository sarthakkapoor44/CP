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
 
const ll MOD = 1e9 + 7;
const ll MAXN = 200000;
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
long long modPow2(long long exp) {
    long long base = 2, result = 1;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return result;
}

struct ChildInfo {
    int to;      
    int edgeType;
};


ll n, q;
ll a[MAXN+1];           
long long expVal[MAXN+1];
ll parentNode[MAXN+1];  
vector<ChildInfo> children[MAXN+1];


void updateSubtree(ll start) {

    stack<ll> st;
    st.push(start);

    while (!st.empty()) {
        ll u = st.top();
        st.pop();

    
        for (auto &ch : children[u]) {
            ll w = ch.to;
            ll t = ch.edgeType;
        
            long long newExp;
            if (t == 1) {
            
                newExp = expVal[u] + a[w];
            } else {
            
            
                newExp = min((long long)expVal[u], (long long)a[w]);
            }

            if (newExp > expVal[w]) {
                expVal[w] = newExp;
                st.push(w);
            }
        }
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
 
    cin >> n >> q;
    vector<vector<pair<ll,ll>>> adj(n+1);

    rep(i,n-1){
        ll u,v,t;
        cin >> u >> v >> t;
        adj[u].push_back({v,t});
        adj[v].push_back({u,t});
    }
    forf(i,1,n+1){
        cin >> a[i];
    }
    vector<ll> edgeType(n+1, -1); 
    parentNode[1] = -1; 
    edgeType[1]   = -1;

    {
        queue<ll>q2;
        q2.push(1);
        vector<bool> visited(n+1,false);
        visited[1] = true;
        while(!q2.empty()){
            ll u = q2.front(); q2.pop();
            for(auto &nx : adj[u]){
                ll v = nx.first;
                ll t = nx.second; 
                if(!visited[v]){
                    visited[v] = true;
                    parentNode[v] = u;
                    edgeType[v] = t; 
                    q2.push(v);
                }
            }
        }
    }


    forf(i,2,n+1)
    {
        ll p = parentNode[i];
        if(p<0) continue;
        children[p].push_back({i, edgeType[i]});
    }
    expVal[1] = a[1];
    queue<ll>q2;
    q2.push(1);
    while(!q2.empty()){
        ll u = q2.front(); q2.pop();
    
        for(auto &ch : children[u]){
            ll c = ch.to;
            ll t = ch.edgeType;
            if(t == 1){
            
                expVal[c] = expVal[u] + a[c];
            } else {
            
                expVal[c] = min(expVal[u], (long long)a[c]);
            }
            q2.push(c);
        }
    }

    while(q--)
    {
        ll type; cin >> type;
        if(type==1)
        {
            ll u; cin >> u;
        
            long long ans = modPow2(expVal[u]);
            cout << ans << "\n";
        } 
        else 
        {
            ll u,v; 
            cin >> u >> v;
            ll p, c; 
            if(parentNode[u] == v){
                p = v; c = u;
            } else {
                p = u; c = v;
            }
            for(auto &ch : children[p]){
                if(ch.to == c){
                    ch.edgeType = 1; 
                    break;
                }
            }
            long long newVal = expVal[p] + a[c];
            if(newVal > expVal[c]){
                expVal[c] = newVal;
                updateSubtree(c);
            }
        }
    }

    return 0;

}



