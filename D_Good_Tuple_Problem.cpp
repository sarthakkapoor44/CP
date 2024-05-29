#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define INF 1000000000000000000
#define pb push_back
#define mp make_pair
#define all(s) s.begin(), s.end()
#define rep(i, n) for (ll i = 0; i < n; i++)
#define vp vector<pair<ll, ll>>
#define v vector<ll>
const ll MODN = 1e9 + 7;
const ll MAXN = 1000001;

// DFS function to check graph bipartiteness
bool dfs(ll pos, vector<vector<ll> > &adj, v &visited, ll parent_color,ll parent) {
    if (visited[pos] == -1) {
        visited[pos] = 1 - parent_color;
        for (auto x : adj[pos]) {
            if(x!=parent){
            if (!dfs(x, adj, visited, 1 - parent_color,pos)) {
                return false;
            }}
        }
    } else if (visited[pos] == parent_color) {
        return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll n, m;
    cin >> n >> m;
    v a(m), b(m);
    rep(i, m) cin >> a[i];
    rep(i, m) cin >> b[i];
    
    vector<vector<ll> > adj(n, vector<ll>());
    rep(i, m)
    {
        adj[a[i]-1].pb(b[i]-1);
        adj[b[i]-1].pb(a[i]-1);
    }
    // rep(i,n)
    // {
    //     cout<<i+1<<" ";for(auto x:adj[i])cout<<x+1<<" ";
    //     cout<<endl;
    // }
   
    v visited(n, -1);
    bool isBipartite = true;
    rep(i, n) 
    {
        if (visited[i] == -1) {
            if (!dfs(i, adj, visited, 0,-1)) 
            {
                isBipartite = false;
                break;
            }
        }
    }
    
    if (isBipartite) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}
