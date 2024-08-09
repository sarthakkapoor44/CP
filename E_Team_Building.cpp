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
 
int main() {
    // FOR GCD - gcd snip
    // FOR SIEVE OF ERATOSTHENES - erat_snip;
    // FOR SPF - spf_snip
    // FOR BINARY_EXPONENTATION - binpow_snip
    OPTIMIZE_IO // Optimize input/output (remove if using scanf and printf)
 
   
    {	//Lesgooooooo!!!!
        ll n,p,k;
        cin>>n>>p>>k;
        vll arr(n);
        rep(i,n)cin>>arr[i];
        vector<vll> grid(n,vll(p));
        rep(i,n)
        {
            rep(j,p)cin>>grid[i][j];
        }
        vector<vector<ll>> dp(n+1,vector<ll>((1ll<<p),-INF));
        dp[0][0] = 0;
        for(int i = 1 ; i <= n; i++ )
        {
            for(int j= 0;j<(1ll<<p);j++)
            {
                if(dp[i-1][j]>-INF) dp[i][j] = max(dp[i-1][j]+arr[i-1],dp[i][j]);
                for(int t = 0; t<p ; t++)
                {
                    if(((1ll<<t)&j))
                    {
                       if( dp[i][(j^(1ll<<t))]>-INF)dp[i][j] = max(dp[i][j],dp[i][j^(1ll<<t)]+grid[i-1][j]);
                    }
                }
            }   
        }
        cout<<dp[n][(1ll<<p)-1];
    }

    return 0;
}
