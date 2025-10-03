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
        ll n;
        cin>>n;
        vector<string> grid(2);
        rep(i,2)cin>>grid[i];
        vector<vector<ll>> dp(n+1,vector<ll>(4,-INF));
        dp[0][3]=0;
        for(int i=1;i<=n;i++)
        {
            if(i-3>=0)
            {   
                ll val =0;
                for(int type = 0;type<=1;type++)
                {
                    ll temp=0;
                    for(int j =i-2;j<=i;j++)if(grid[type][j-1]=='A')temp++;
                    if(temp>=2)val++;
                }
                dp[i][3] = max(dp[i][3],dp[i-3][3]+val);
            }
            if(i-1>=1)
            {
                ll one = 0,two =0;
                ll temp =0 ;
                if(grid[0][i-1]=='A')temp++;
                if(grid[1][i-1]=='A')temp++;
                if(grid[0][i-2]=='A')temp++;
                if(temp>=2)one++;
                temp= 0 ;
                if(grid[0][i-1]=='A')temp++;
                if(grid[1][i-1]=='A')temp++;
                if(grid[1][i-2]=='A')temp++;
                if(temp>=2)two++;
                // cout<<one<<" "<<two<<" f";ce;
                dp[i][3] = max(dp[i][3] , dp[i-1][1]+one );
                dp[i][3] = max(dp[i][3] , dp[i-1][2]+two );
            }
             
            ll one_1 =0 ,two_1 =0 ;
            if(i-2>=0)
            {
                ll temp =0 ;
                if(grid[0][i-1]=='A')temp++;
                if(grid[1][i-2]=='A')temp++;
                if(grid[0][i-2]=='A')temp++;
                if(temp>=2)two_1++;
                dp[i][2] = max(dp[i][2],dp[i-2][3]+two_1);
            }

            if(i>=4)
            {
                ll val1 =0 ,val2 =0 ;
                ll temp =0 ;
                ll idx =i-1;
                if(grid[0][idx]=='A')temp++;
                if(grid[0][idx-1]=='A')temp++;
                if(grid[0][idx-2]=='A')temp++;
                if(temp>=2)val1++;
                temp =0 ;
                if(grid[1][idx-1]=='A')temp++;
                if(grid[1][idx-2]=='A')temp++;
                if(grid[1][idx-3]=='A')temp++;
                if(temp>=2)val2++;
                dp[i][2] = max(dp[i][2],dp[i-3][2] +val1+val2);
            }
            if(i-2>=0)
            {
                ll temp =0 ;
                if(grid[1][i-1]=='A')temp++;
                if(grid[1][i-2]=='A')temp++;
                if(grid[0][i-2]=='A')temp++;
                if(temp>=2)one_1++;
                dp[i][1] = max(dp[i][1],dp[i-2][3]+one_1);
            }

            if(i>=4)
            {
                ll val1 =0 ,val2 =0 ;
                ll temp =0 ;
                ll idx = i-1;
                if(grid[1][idx]=='A')temp++;
                if(grid[1][idx-1]=='A')temp++;
                if(grid[1][idx-2]=='A')temp++;
                if(temp>=2)val1++;
                temp =0 ;
                if(grid[0][idx-1]=='A')temp++;
                if(grid[0][idx-2]=='A')temp++;
                if(grid[0][idx-3]=='A')temp++;
                if(temp>=2)val2++;
                dp[i][1] = max(dp[i][1],dp[i-3][1] +val1+val2);
            }

        }
        // debug(dp);
        cout<<dp[n][3];ce;
    }

    return 0;
}
