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
 #define pll pair<ll,ll>
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
  
 const ll MODN = 1e9 + 7;
 const ll MAXN = 1000001;
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

 vector<vector<ll>> mat_mul(vector<vector<ll>> &a, vector<vector<ll>> &b) {
    int n = a.size(), m = b[0].size(), p = b.size();
    vector<vector<ll>> c(n, vector<ll>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < p; k++) {
                c[i][j] = (c[i][j] + (a[i][k] * b[k][j])%MODN) % MODN;
            }
        }
    }
    return c;
}
vector<vector<ll>> mat_exp(vector<vector<ll>> &a, ll b) {
    int n = a.size();
    vector<vector<ll>> res(n, vector<ll>(n, 0));
    for (int i = 0; i < n; i++) res[i][i] = 1;
    while (b) {
        if (b & 1) res = mat_mul(res, a);
        a = mat_mul(a, a);
        b >>= 1;
    }
    return res;
}
 int main() {
    // FOR GCD - gcd snip
    // FOR SIEVE OF ERATOSTHENES - erat_snip;fast_sieve
    // FOR SPF - spf_snip
    // FOR BINARY_EXPONENTATION - binpow_snip
    // FOR SEGMENT_TREE - seg_snip
    // FOR LCA - lca_snip
    OPTIMIZE_IO // Optimize input/output (remove if using scanf and printf)

    {	//Lesgooooooo!!!!
        ll n;
        cin>>n;
        vector<vector<ll>> f = {{16},{8},{4},{2},{1},{1}},
        matrix = {
            {1,1,1,1,1,1},
            {1,0,0,0,0,0},
            {0,1,0,0,0,0},
            {0,0,1,0,0,0},
            {0,0,0,1,0,0},
            {0,0,0,0,1,0}
        };
        if(n<=5)
        {
            cout<<f[5-n][0];
            return 0;
        }
        matrix = mat_exp(matrix,n-5);
        f = mat_mul(matrix,f);
        // debug(f);

        cout<<f[0][0];ce;
    }
 
     return 0;
 }
