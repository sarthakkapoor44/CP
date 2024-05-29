#include<bits/stdc++.h>
using namespace std;
#include<tuple>
typedef long long ll;
#define fi first
#define se second
#define INF 1000000000000LL
#define pb push_back
#define mp make_pair

int main() {
    int t=1;
    scanf("%d", &t);
    while (t--) {
        ll n, m;
        scanf("%lld %lld", &n, &m);
        vector<vector<pair<ll, ll> > > adj(n);
        for (ll i = 0; i < m; i++) {
            ll a, b, w;
            scanf("%lld %lld %lld", &a, &b, &w);
            adj[a-1].pb(mp(b-1, w));
            adj[b-1].pb(mp(a-1, w));
        }
        
        vector<ll> cycle(n);
        for (ll i = 0; i < n; i++) {
            scanf("%lld", &cycle[i]);
        }
        
        vector<vector<ll> > dist(n, vector<ll>(n, INF));
        dist[0][0] = 0;
        
        // Define priority queue with tuples, using greater<> for min heap
        priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll> >, greater<tuple<ll, ll, ll> > > pq;
        pq.push(make_tuple(0LL, 0LL, 0LL)); // Initial distance, node, and 'i' value
        
        while (!pq.empty()) {
            auto [currentDist, i, currentNode] = pq.top();
            pq.pop();
            
            for (auto& edge : adj[currentNode]) {
                ll nextNode = edge.fi;
                ll weight = edge.se;
                
                if (cycle[currentNode] < cycle[i]) {
                    if (dist[nextNode][currentNode] > currentDist + weight * cycle[currentNode]) {
                        dist[nextNode][currentNode] = currentDist + weight * cycle[currentNode];
                        pq.push(make_tuple(dist[nextNode][currentNode], currentNode, nextNode));
                    }
                } else {
                    if (dist[nextNode][i] > currentDist + weight * cycle[i]) {
                        dist[nextNode][i] = currentDist + weight * cycle[i];
                        pq.push(make_tuple(dist[nextNode][i], i, nextNode));
                    }
                }
            }
        }
        
        ll ans = INF;
        for (ll j = 0; j < n; j++) {
            ans = min(dist[n-1][j], ans);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
