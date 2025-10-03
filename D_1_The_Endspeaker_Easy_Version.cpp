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
    // FOR SEGMENT_TREE - seg_snip
    OPTIMIZE_IO // Optimize input/output (remove if using scanf and printf)
    
    int t=1;
    cin>>t;
    while (t--)
    {	//Lesgooooooo!!!!
        ll n,m;
        cin>>n>>m;
        vll a(n),b(m);
        rep(i,n)cin>>a[i];
        rep(i,m)cin>>b[i];
        vector<ll> suffix(n);
        forb(i,n-1,0)
        {
            suffix[i] = a[i] + ((i+1<n)?suffix[i+1]:0);
        }
        reverse(all(suffix));
        // debug(suffix);
        vector<vector<ll>> dp(n+1,vector<ll>(m,INF));

        // function<ll(ll,ll)> solve =[&](ll i,ll j)->ll
        // {
        //     if(i>=n){return  0;}
        //     if(j<0)return  INF;
        //     if(dp[i][j]<INF)return dp[i][j];
        //     auto x = upper_bound(suffix.begin(),suffix.end(),b[j]+((i-1>=0)?suffix[i-1]:0ll)) - suffix.begin()-1;
        //     dp[i][j] = min({(m-1-j) + solve(x+1,j-1),solve(i,j-1),((x+1>i)?((m-1-j) + solve(x+1,j)):INF)});
        //     return dp[i][j];
        // };
        for(int i=0;i<m;i++)dp[n][i]=0;
        for(int i = n-1;i>=0;i--)
        {
            for(int j =0;j<m;j++)
            {
                auto x = upper_bound(suffix.begin(),suffix.end(),b[j]+((i-1>=0)?suffix[i-1]:0ll)) - suffix.begin()-1;
                if(x+1<=n)
                {
                    dp[i][j]  = min(dp[i][j],((x+1>i)?((m-1-j) + dp[x+1][j]):INF));
                    if(j-1>=0)dp[i][j] = min(dp[i][j],(m-1-j) + dp[x+1][j-1]);
                }
                if(j-1>=0)dp[i][j] = min(dp[i][j],dp[i][j-1]);
            }
        }
        
        // ll ans = solve(0,m-1);
        cout<<((dp[0][m-1]==INF)?-1:dp[0][m-1]);ce;
        
    }

    return 0;
}
