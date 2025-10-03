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
#define pyes cout<<"YES";
#define pno cout<<"NO";
#define rep(i, n) for (ll i = 0; i < n; i++)
#define forf(i, a, b) for (ll i = a; i < b; i++)
#define forb(i, s, e) for (ll i = s; i >= e; i--)
#define vp vector<pair<ll, ll> >
#define vll vector<ll>
#define OPTIMIZE_IO  std::ios::sync_with_stdio(false);\
    std::cin.tie(nullptr);
// typedef tree<ll, null_type, less<ll>, rb_tree_tag,
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
    for (ll i = 0; i < (ll)a.size(); i++)
    {
        cout << a[i] << " ";
    }
    ce;
}
 
signed main() {
    OPTIMIZE_IO // Optimize input/output (remove if using scanf and printf)

    
    ll t = 1;
    cin >> t;
    while (t--) {
        ll n, m;
        cin >> n >> m;
        vector<vll> adj(n); 
        rep(i, m) 
        {
            ll u, v;
            cin >> u >> v;
            adj[u-1].pb(v-1);
            adj[v-1].pb(u-1);
        }
        
        vector<ll> vis(n, 0);
        vector<ll> colors(n, -1);
        ll cq = 1;

        function<bool(ll,ll)> isBipartite = [&](ll pos, ll color) -> bool {
             queue<int> q;
    
            // Iterate through all vertices to handle disconnected graphs
            for(int i = 0; i < n; i++) {

                // If the vertex is uncolored, start BFS from it
                if(colors[i] == -1) {

                    // Assign first colors (0) to the starting vertex
                    colors[i] = 0;
                    q.push(i);
                    
                    // Perform BFS
                    while(!q.empty()) {
                        int u = q.front();
                        q.pop();
                        
                        // Traverse all adjacent vertices
                        for(auto &v : adj[u]) {

                            // If the adjacent vertex is uncolored,
                            // assign alternate color
                            if(colors[v] == -1) {
                                colors[v] = 1 - colors[u];
                                q.push(v);
                            }

                            // If the adjacent vertex has the same colors,
                            // graph is not bipartite
                            else if(colors[v] == colors[u]) {
                                return false;
                            }
                        }
                    }
                }
            }
            
            // If no conflicts in coloring, graph is bipartite
            return true;
        };
      
        cq = isBipartite(0, 0);
          

        if (cq) 
        {
            cout << "Bob"<<endl;
            cout.flush();
            vector<ll> p1,p2;
            rep(i,n){if(colors[i])p1.push_back(i);else p2.pb(i);}
            
            rep(i, n) {
                ll a, b;
                cin >> a >> b;  // Reading two color choices
                if((a==1 || b==1) && p1.size()){
                    cout<<p1.back()+1<<" "<<1;
                    p1.pop_back();
                }
                else if((a==2 || b==2 ) && p2.size())
                {
                    cout<<p2.back()+1<<" "<<2;
                    p2.pop_back();
                }
                else if((a==1 || b==1) && p1.empty()){
                    cout<<p2.back()+1<<" "<<(a==1?b:a);
                    p2.pop_back();
                }
                else {
                     cout<<p1.back()+1<<" "<<(a==2?b:a);
                     p1.pop_back();
                }
                ce;
            }
        } 
        else {
            cout << "Alice"<<endl;
            cout.flush();
            rep(i, n) {
                cout << 1 << " " << 2<<endl;   // Default output for Alice case
                cout.flush();
                ll idx, col;
                cin >> idx >> col;  // Interactive input reading
                if(idx==-1 || col==-1)break;
            }
        }
    }

    return 0;
}