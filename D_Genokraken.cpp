///////////////////////////////////////////////////// DYNATOS ////////////////////////////////////////////////////
#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#ifdef ONLINE_JUDGE
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#endif
using namespace std;

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
#define OPTIMIZE_IO  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

const ll MODN = 1e9 + 7;
const ll MAXN = 1000001;
const ll modn = 998244353;

template <typename T>
void out(vector<T> a) {
    for (int i = 0; i < (int)a.size(); i++) {
        cout << a[i] << " ";
    }
    ce;
}

int main() {
    OPTIMIZE_IO // Optimize input/output

    int t = 1;
    cin >> t;
    while (t--) { // Lesgooooooo!!!!
        ll n;
        cin >> n;
        vector<vector<ll>> adj(n);
        adj[0].pb(1);
        adj[1].pb(0);
        ll last = 1;
        vector<ll> vis(n);
        vis[0] = 1;
        vis[1] = 1;
        set<ll> st;

        for (int i = 2; i < n; i++) {
            cout << "?" << " " << 1 << " " << i; ce;
            cout.flush();
            ll val;
            cin >> val;
            if (val == 0) {
                adj[i].pb(last);
                adj[last].pb(i);
                last = i;
                vis[i] = 1;
            } else {
                if (last == 1) {
                    adj[i].pb(0);
                    adj[0].pb(i);
                    st.insert(i);
                    vis[i] = 1;
                }
            } 
        } 

        forf(i, 2, n) {
            if (!vis[i] && !st.empty()) {
                ll num = *st.begin();
                cout << "?" << " " << i << " " << num;ce;
                cout.flush();
                ll val;
                cin >> val;
                if (!val) {
                    st.erase(st.begin());
                    adj[num].pb(i);
                    adj[i].pb(num);
                    st.insert(i);
                    vis[i] = 1;
                } else {
                    st.erase(st.begin());
                    i--;
                }
            }
        }

        vll ans(n);
        function<void(ll, ll)> dfs = [&](ll pos, ll parent) {
            ans[pos] = parent;
            for (auto x : adj[pos]) {
                if (x == parent) {
                    continue;
                }
                dfs(x, pos);
            }
        };

        dfs(0, 0);
        cout << "!" << " ";
        for (int i = 1; i < n; i++) cout << ans[i] << " ";
        ce;
        cout.flush();
    }

    return 0;
}
