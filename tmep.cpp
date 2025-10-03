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
const ll MAXN = 1e4+5;
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

ll op(ll x, ll y) {
    cout << "? " << x << " " << y << "\n";
    cout.flush();
    ll res;
    cin >> res;
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
 
    int test=1;
    cin>>test;
    while (test--)
    {	//Lesgooooooo!!!!
        ll n,k;
        cin>>n>>k;
        vll arr(n);
        rep(i,n)cin>>arr[i];
        ll lg = floor(log2(n)) + 1;
        ll st[lg][MAXN];
        rep(i,n)st[i][0] = arr[i];
        for (int i = 1; i <= lg; i++)
        for (int j = 0; j + (1 << i) <= n; j++)
        st[i][j] = op(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);

        vll result;
        rep(i,n-k)
        {
            ll l =i, r=i+k, j = floor(log2(r-l+1));
            ll res = op(st[l][j],st[r-(1ll<<j)+1][j]);
            result.push_back(res);
        }
        cout << "! ";
        out(result);
        cout.flush();
    
    }

    return 0;
}
