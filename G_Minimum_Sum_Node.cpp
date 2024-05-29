#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll INF = 1000000000000000000;
const ll MAXN = 2*1e5 + 10;
 
vector<ll> adj[MAXN];
vector <ll> sizeee(MAXN);
ll sod[MAXN];
vector<ll> ansv;
ll msod = INF;
void dfs(ll node, ll parent) {
    sizeee[node] = 1;
    sod[node] = 0;
 
    for (ll child : adj[node]) {
        if (child != parent) {
            dfs(child, node);
            sizeee[node] += sizeee[child];
            sod[node] += (sod[child] + sizeee[child]);
        }
    }
}
void dfs2(ll node, ll parent, ll psod, ll N) {
    ll csod = sod[node] + psod + (N - sizeee[node]);
    if (csod < msod) {
        msod = csod;
        ansv.clear();
        ansv.push_back(node);
    } else if (csod == msod) {
        ansv.push_back(node);
    }
 
    for (ll child : adj[node]) {
        if (child != parent) {
            ll npsod = csod - (sod[child] + sizeee[child]);
            dfs2(child, node, npsod, N);
        }
    }
}
 
int main() {
    ll N;
 
    cin >> N;
 
 
    for (ll i = 0; i < N - 1; i++) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
 
    dfs(1, -1);
 
 
    dfs2(1, -1, 0, N);
 
 
    cout << ansv.size() << endl;
 
    sort(ansv.begin(), ansv.end());
 
    for (ll vertex : ansv) {
        cout << " " << vertex;
    }
    cout << endl;
 
    return 0;
}