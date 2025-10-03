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
 
const ll MOD = 1e9 + 7;
const ll MAXN = 5000;
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

int eul[MAXN+1][MAXN+1];
int pre[MAXN+1][MAXN+1];


int main() {
    // FOR GCD - gcd snip
    // FOR SIEVE OF ERATOSTHENES - erat_snip;fast_sieve
    // FOR SPF - spf_snip
    // FOR BINARY_EXPONENTATION - binpow_snip
    // FOR SEGMENT_TREE - seg_snip
    // FOR LCA - lca_snip
    OPTIMIZE_IO // Optimize input/output (remove if using scanf and printf)
 
    eul[0][0] = 1;
    forf(i,1,MAXN+1)
    {
        forf(d,0,i+1)
        {
            ll val = 0;
            if(d-1 >= 0)(val += ((i - d) * eul[i-1][d-1])%MOD)%=MOD;
            (val += ((d + 1) * eul[i-1][d])%MOD)%=MOD;
            eul[i][d] = val;
        }
    }

    forf(i,0,MAXN+1)
    {
        ll s = 0;
        forf(d, 0, i+1)
        {
            (s += (eul[i][d]) % MOD)%=MOD;
            pre[i][d] = s;
        }
    }

    int t;
    cin >> t;
    while(t--)
    {
        ll n, k;
        cin>>n>>k;
        if(k == 0)cout <<0;     
        else cout<<pre[n][k-1]%MOD;
        ce;
    }
    return 0;
}

