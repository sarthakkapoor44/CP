#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 50001;
const ll K = 501;

vector<vector<ll> > dp(N, vector<ll>(K, 0));

vector<vector<ll> > adj(N);
ll ans = 0;
void dist(ll pos, ll parent, ll k) {
    for (auto x : adj[pos]) {
        if (x == parent) continue;
        dist(x, pos, k);
        for (int i = 1; i <= k; i++) {
            dp[pos][i] += dp[x][i - 1];
        }
    }

    // Calculate paths ending at this node.
    ll temp =0;

    // Calculate paths within the subtree rooted at this node.
    for (auto x : adj[pos]) {
        if (x == parent) continue;
        for (int i = 1; i <= k; i++) {
            if (k - i -1 >= 0) {
                temp += dp[x][i - 1] * (dp[pos][k - i] - dp[x][k - i - 1]);
            }
        }
    }
    ans+= (temp/2)+ dp[pos][k];
}

int main() {
    ll n, k;
    cin >> n >> k;
    for (int i = 0; i < n - 1; i++) {
        ll a, b;
        cin >> a >> b;
        adj[a - 1].push_back(b - 1);
        adj[b - 1].push_back(a - 1);
    }
    for(int i=0;i<n;i++)dp[i][0]=1;
    dist(0, -1, k);
    cout << ans << endl;
    return 0;
}
