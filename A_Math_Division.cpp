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
ll mod_inverse(ll a, ll m)
{
    ll m0 = m;
    ll y = 0, x = 1;
    if (m == 1)
        return 0;
    while (a > 1)
    {
        ll q = a / m;
        ll t = m;
        m = a % m, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0)
        x += m0;
    return x;
}
ll inv2 = mod_inverse(2,MODN);
const int N = 1e5+5;
vector<vector<ll>> dp(N,vector<ll>(2,0));
// ll solve(string s,ll carry)
// {
//     debug(s,carry);
//     if(s.size()==1 )return carry;
//     if(dp[s.size()][carry]!=0)
//     {
//         return dp[s.size()][carry];
//     }

//     char last = s.back();
//     s.pop_back();
//     if(last == '0')
//     {
//         if(carry == 0)
//         {
//             return (dp[s.size()][carry] =(1+ solve(s,0)%MODN)%MODN)%=MODN;
//         }
//         else
//         {
           
//             return (dp[s.size()][carry] = (1+ ((solve(s,1)*inv2)%MODN+ (solve(s,0)*inv2)%MODN)%MODN)%MODN)%=MODN;
//         }
//     }
//     else
//     {
//         if(carry ==0)
//         {
           
//             return (dp[s.size()][carry] = (1+ ((solve(s,1)*inv2)%MODN + (solve(s,0)*inv2)%MODN)%MODN)%MODN)%=MODN;
//         }
//         else
//         {
           
//             return (dp[s.size()][carry] =(1+solve(s,1)%MODN)%MODN)%=MODN;
//         }
//     }
//     // debug(s,carry,dp[s.size()][carry]);
// }
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
        ll n;
        cin>>n;
        dp.clear();
        dp.resize(n+1,vector<ll>(2,0));
        string s;
        cin>>s;
        // reverse(all(s));
        dp[0][0] =0 ;
        dp[0][1] = 1;
        for(int i=1;i<n;i++)
        {
            if(s[i]=='0')
            {
                dp[i][0] = (dp[i-1][0]+1)%MODN;
                dp[i][1] = (1 + (inv2*dp[i-1][1])%MODN + (inv2*dp[i-1][0])%MODN)%MODN; 
            }
            else
            {
                dp[i][0] = (1 + (inv2*dp[i-1][1])%MODN + (inv2*dp[i-1][0])%MODN)%MODN;
                dp[i][1] = (dp[i-1][1]+1)%MODN;
            }
        }
        // debug(dp);
        cout<<dp[n-1][0]<<endl;
    }

    return 0;
}
