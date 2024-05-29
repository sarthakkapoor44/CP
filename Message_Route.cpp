#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1000000000000000000; // Using const instead of #define

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll n, m;
    cin >> n >> m;
    vector<vector<ll> > adj(n + 1); // Use ll instead of long long for consistency

    for(ll i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    queue<ll> bfs;
    bfs.push(1);
    vector<bool> visited(n + 1, false);
    vector<ll> dist(n + 1,-1);
    vector<ll> parent(n + 1, -1);
    
    dist[1] = 0;
    parent[1] = -1;
    visited[1]=true;
    while(!bfs.empty()) {
        ll pos = bfs.front();
        bfs.pop();
            for(auto x : adj[pos]) {
                if(!visited[x]) {
                    visited[x]=true;
                    dist[x] = dist[pos] + 1;
                    parent[x] = pos;
                    bfs.push(x); // Enqueue child nodes only if not visited
                }
            }
        
    }

    if(dist[n] != INF) {
        cout << dist[n] + 1 << endl; // Added endl to flush the output
        ll pos = n;
        vector<ll> path;

        while(pos != -1) {
            path.push_back(pos);
            pos = parent[pos];
        }

        reverse(path.begin(), path.end());
        for(auto y : path) {
            cout << y << " ";
        }
        cout << endl; // Added endl to flush the output
    }
    else {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}
