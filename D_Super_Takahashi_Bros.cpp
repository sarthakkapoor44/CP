#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define INF 1000000000000000000
#define pb push_back
#define mp make_pair

void dijkstra(ll s, vector<ll> &d, vector<vector<pair<ll, ll> > > &adj, int n) {
    d.assign(n, INF);
    d[s] = 0;
    
    // Use priority queue where the pair is (distance, vertex)
    priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, greater<pair<ll, ll> > > pq;
    pq.push(mp(0, s)); // Push starting node with distance 0
    
    while (!pq.empty()) {
        ll v = pq.top().second;
        ll d_v = pq.top().first;
        pq.pop();
        
        // If this node has already been processed with a shorter distance, skip it
        if (d_v != d[v])
            continue;

        for (auto edge : adj[v]) {
            ll to = edge.first;
            ll len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                pq.push(mp(d[to], to)); // Push the updated distance and vertex to the priority queue
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    scanf("%lld", &n);
    vector<vector<pair<ll, ll> > > adj(n);
    for (ll i = 0; i < n-1; i++) {
        ll a, b, x;
        scanf("%lld %lld %lld", &a, &b, &x);
        adj[i].pb(mp(i+1, a));
        adj[i].pb(mp(x-1, b)); // Make sure x-1 is within bounds and correctly represents the intended edge
    }
    vector<ll> dist;
    dijkstra(0, dist, adj, n);
    printf("%lld\n", dist[n-1]);

    return 0;
}
