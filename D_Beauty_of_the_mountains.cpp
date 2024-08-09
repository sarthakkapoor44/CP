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

vector<ll> convolution(const vector<string> &matrix, ll k) {
    ll n = matrix.size();
    ll m = matrix[0].size();
    vector<ll> val;
    ll temp = 0;
    rep(i, k) rep(j, k) {
        if (matrix[i][j] == '1') temp += 1;
        else temp -= 1;
    }
    vector<vector<ll>> rp(n, vll(m)), cp(n, vll(m));
    rep(i, n)
        rep(j, m) {
            rp[i][j] = (j ? rp[i][j - 1] : 0) + ((matrix[i][j] == '1') ? 1 : -1);
        }

    rep(j, m)
        rep(i, n) {
            cp[i][j] = (i ? cp[i - 1][j] : 0) + ((matrix[i][j] == '1') ? 1 : -1);
        }

    ll temp1 = temp;
    for (int i = 0; i <= n - k; i++) {
        if (i) {
            temp1 += (rp[i + k - 1][k - 1] - rp[i - 1][k - 1]);
        }
        if(temp1)val.pb(abs(temp1));
        temp = temp1;
        for (int j = 1; j <= m - k; j++) {
            temp += (- (cp[i + k - 1][j - 1] - (i ? cp[i - 1][j - 1] : 0)) +
                     (cp[i + k - 1][j + k - 1] - (i ? cp[i - 1][j + k - 1] : 0)));
            if(temp)val.pb(abs(temp));
        }
    }
    return val;
}


signed main() {
    // FOR GCD - gcd snip
    // FOR SIEVE OF ERATOSTHENES - erat_snip;
    // FOR SPF - spf_snip
    // FOR BINARY_EXPONENTATION - binpow_snip
    OPTIMIZE_IO // Optimize input/output (remove if using scanf and printf)
 
     int t = 1;
    cin >> t;
    while (t--) {
        ll n, m, k;
        cin >> n >> m >> k;
        vector<vector<ll>> grid(n, vll(m));
        vector<string> type(n);
        rep(i, n) {
            rep(j, m) cin >> grid[i][j];
        }
        rep(i, n) {
            cin >> type[i];
        }
        vector<ll> result = convolution(type, k);
        ll val = 0;
        rep(i, n) {
            rep(j, m) {
                if (type[i][j] == '1') val += grid[i][j];
                else val -= grid[i][j];
            }
        }
        bool flag= 0;
        if(abs(val)==0){flag= 1;}
        else if(result.size())
        {
            ll nums = abs(result[0]);
            for(int i=0;i<result.size();i++)
            {
                if(result[i] && abs(val)%abs(result[i])==0){flag=1;break;}
                
                  if(result[i])  nums =  __gcd(abs(result[i]),nums);
            }
             if((abs(val)%nums)==0){flag=1;}
            
        }

        if(flag){pyes;}
        else {pno;}
        ce;
    

    }
    return 0;
}


