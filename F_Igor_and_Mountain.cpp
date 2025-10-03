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
 
int main() {
    // FOR GCD - gcd snip
    // FOR SIEVE OF ERATOSTHENES - erat_snip;fast_sieve
    // FOR SPF - spf_snip
    // FOR BINARY_EXPONENTATION - binpow_snip
    // FOR SEGMENT_TREE - seg_snip
    // FOR LCA - lca_snip
    OPTIMIZE_IO // Optimize input/output (remove if using scanf and printf)
 
    int t=1;
    cin>>t;
    while (t--)
    {	//Lesgooooooo!!!!
        ll n,m,d;
        cin>>n>>m>>d;
        vector<string> grid(n);
        rep(i,n)cin>>grid[i];
        
        vector<vector<vector<ll>>> dp(n,vector<vector<ll>>(m,vector<ll>(2,0))) , pref(n,vector<vector<ll>>(m,vector<ll>(2,0)));
        for(int i=n-1;i>=0;i--)
        {
            rep(j,m)
            {
                if(i+1<n)
                {
                    if(grid[i][j]=='X')
                    {
                     
                        ll width =d-1;
                        ll left = max(0ll,j-width);
                        ll right = min(m-1,j+width);
                        (dp[i][j][0] +=(pref[i+1][right][0]%modn - ((left-1>=0)?pref[i+1][left-1][0]:0)%modn + modn)%modn)%=modn;
                        (dp[i][j][0] += (pref[i+1][right][1]%modn - ((left-1>=0)?pref[i+1][left-1][1]:0)%modn  +modn)%modn)%=modn;
                        // (pref[i][j][0] = (dp[i][j][0]%modn + ((j-1>=0?pref[i][j-1][0]:0))%modn)%modn)%=modn;
                    }
                }
                else if(grid[i][j]=='X' and i+1>=n)
                {
                    dp[i][j][0] = 1;
                }
                pref[i][j][0] = ((dp[i][j][0])%modn + ((j-1>=0)?pref[i][j-1][0]:0)%modn)%modn;
                
            }
            rep(j,m)
            {
                if(grid[i][j]=='X')
                {
                    ll width =d;
                    ll left = max(0ll,j-width);
                    ll right = min(m-1,j+width);
                    (dp[i][j][1] += ((pref[i][right][0]%modn - ((left-1>=0?pref[i][left-1][0]:0))%modn +modn)%modn - (dp[i][j][0])%modn + modn)%modn)%=modn;
                }
                (pref[i][j][1] = (dp[i][j][1] + ((j-1>=0)?pref[i][j-1][1]:0)%modn)%modn)%=modn;
            }
        }
        // debug(dp,pref);
        cout<<(pref[0][m-1][0]%modn+pref[0][m-1][1]%modn)%modn;ce;         
        
    }

    return 0;
}
