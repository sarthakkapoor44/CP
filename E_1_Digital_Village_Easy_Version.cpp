#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cstring>
#include <limits>

using namespace std;

typedef long long ll;

const ll INF = 1e18;

struct Edge {
    int u, v;
    ll w;
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

int find(int u, vector<int>& parent) {
    if (parent[u] != u) {
        parent[u] = find(parent[u], parent);  // Path compression
    }
    return parent[u];
}

void union_sets(int u, int v, vector<int>& parent, vector<int>& s_flag) {
    int pu = find(u, parent);
    int pv = find(v, parent);
    if (pu != pv) {
        parent[pu] = pv;
        s_flag[pv] += s_flag[pu];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m, p;
        cin >> n >> m >> p;

        vector<int> s(p);
        vector<int> s_flag(n + 1, 0);
        for (int i = 0; i < p; ++i) {
            cin >> s[i];
            s_flag[s[i]] = 1;
        }

        vector<Edge> edges(m);
        for (int i = 0; i < m; ++i) {
            int u, v;
            ll w;
            cin >> u >> v >> w;
            edges[i] = {u, v, w};
        }

        sort(edges.begin(), edges.end());

        vector<int> parent(n + 1);
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }

        vector<ll> ans(n + 1, INF);
        int c_L = p;

        for (int k = n; k >= 1; --k) {
            ans[k] = INF;
        }

        for (const auto& edge : edges) {
            int u = edge.u;
            int v = edge.v;
            ll w = edge.w;

            int pu = find(u, parent);
            int pv = find(v, parent);

            if (pu != pv) {
                int total_s_flag = s_flag[pu] + s_flag[pv];
                union_sets(u, v, parent, s_flag);

                if (s_flag[pu] >= 1 && s_flag[pv] >= 1) {
                    c_L--;
                    for (int k = c_L; k <= n; ++k) {
                        if (ans[k] > (ll)p * w) {
                            ans[k] = (ll)p * w;
                        }
                    }
                } else if (s_flag[pu] >= 1 || s_flag[pv] >= 1) {
                    s_flag[find(u, parent)] = 1;
                }
            }
        }

        for (int k = 1; k <= n; ++k) {
            if (ans[k] == INF) ans[k] = 0;
            cout << ans[k] << (k == n ? '\n' : ' ');
        }
    }

    return 0;
}
